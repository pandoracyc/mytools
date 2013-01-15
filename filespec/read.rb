#!/usr/bin/ruby -I.

require "csv"
require "read_config"

#FILE INFOMATION
read_config_file("sample","dat")
filename = "sample.dat"
csvfile = "sample_%s.csv"

unit = "head"
head_length = 5
head_keys=$file_keys[unit]
head_pack = $file_pack_template[unit].join

unit = "body"
body_record_size = 4
body_keys=$file_keys[unit]
body_pack = $file_pack_template[unit].join


# open file
fp = open(filename,"r")

# read head
print "----------------------------------------\n"
print "read head data\n"
print "----------------------------------------\n"
head = fp.read(head_length)
head_values = head.unpack(head_pack)
alist = head_keys.zip(head_values)
p head_hash = Hash[alist]
print "\n"

# read body
print "----------------------------------------\n"
print "read body record\n"
print "----------------------------------------\n"
body_hash = Array.new
while record = fp.read(body_record_size)
	body_values = record.unpack(body_pack)
	alist = body_keys.zip(body_values)
	body_hash.push(Hash[alist])
end

# print body
record_num = body_hash.length
printf("record number is %d\n",record_num)
i = 0
while i < body_hash.length
	p body_hash[i]
	i += 1
end

#close file
fp.close


print "\n"
print "\n"


# open file
print "----------------------------------------\n"
print "make csvfile\n"
print "----------------------------------------\n"
p head_filename = sprintf(csvfile,"head")
p body_filename = sprintf(csvfile,"body")
out_head = CSV.open(head_filename,"wb")
out_body = CSV.open(body_filename,"wb")

# write head
out_head << head_keys
out_head << head_pack.parse_csv
out_head << head_values = head_hash.values_at(*head_keys)

# write record
out_body << body_keys
out_body << body_pack.parse_csv
i = 0
while i < body_hash.length
	body_values = body_hash[i].values_at(*body_keys)
	out_body << body_values
	i += 1
end

# close file
out_head.close
out_body.close
