#!/usr/bin/ruby

require "csv"

#FILE INFOMATION
outfile = "sample_out.dat"
csvfile = "sample_%s.csv"

# open file
head_filename = sprintf(csvfile,"head")
body_filename = sprintf(csvfile,"body")
out_head = CSV.open(head_filename,"rb")
out_body = CSV.open(body_filename,"rb")

# read head
print "----------------------------------------\n"
print "read head\n"
print "----------------------------------------\n"
head_keys = out_head.readline
p head_pack = out_head.readline.join
head_values = out_head.readline
alist = head_keys.zip(head_values)
p head_hash = Hash[alist]
print "\n"

# read record
print "----------------------------------------\n"
print "read body\n"
print "----------------------------------------\n"
body_keys = out_body.readline
p body_pack = out_body.readline.join
body_hash = Array.new
while body_values = out_body.readline
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

print "\n"
print "\n"

# close file
out_head.close
out_body.close



# open file
fp = open(outfile,"w")

# write head
print "----------------------------------------\n"
print "write head\n"
print "----------------------------------------\n"
p head_values = head_hash.values_at(*head_keys)
p head_pack
fp.write head_values.pack(head_pack)
print "\n"

# write record
print "----------------------------------------\n"
print "write body\n"
print "----------------------------------------\n"
i = 0
while i < body_hash.length
	body_values = body_hash[i].values_at(*body_keys)
	fp.write body_values.pack(body_pack)
	i += 1
end

# close file
fp.close
