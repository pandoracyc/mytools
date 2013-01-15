#!/usr/bin/ruby

#FILE INFOMATION
filename = "test.dat"
outfile = "test2.dat"

head_length = 5
head_keys=["len","to","record_size"]
head_pack = "nH2n"

body_record_size = 4
body_keys=["number","x","y"]
body_pack = "nH2H2"


# open file
fp = open(filename,"r")

# read head
print "read head data\n"
head = fp.read(head_length)
head_values = head.unpack(head_pack)
alist = head_keys.zip(head_values)
p head_hash = Hash[alist]

# read body
print "read body record\n"
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




# open file
fp = open(outfile,"w")

# write head
print "write head\n"
p head_hash = {"len"=>10, "to"=>"01", "record_size"=>0}
head_values = head_hash.values_at(*head_keys)
fp.write head_values.pack(head_pack)

# write record
print "write body\n"
i = 0
while i < body_hash.length
	p body_hash[i] = {"number"=>i+1, "x"=>"01", "y"=>"01"}
	body_values = body_hash[i].values_at(*body_keys)
	fp.write body_values.pack(body_pack)
	i += 1
end

# close file
fp.close
