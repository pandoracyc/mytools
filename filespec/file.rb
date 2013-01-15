#!/usr/bin/ruby

require "csv"

#FILE INFOMATION
extension = "dat"
file_prefix="sample"
p configure_file=sprintf("%s_%s.conf",file_prefix ,extension)

# open file
config_fp = CSV.open(configure_file,"rb")

# read record
print "----------------------------------------\n"
p sprintf("%s.%s" ,file_prefix ,extension )
print "----------------------------------------\n"
config_hash = Array.new
while section = config_fp.readline
	unit = section.join
	file_keys = config_fp.readline
	print "unit : "
	p unit

	print "file_keys : "
	p file_keys.join
	print "config_keys="
	p config_keys = config_fp.readline
	print "\n"
end

# close file
config_fp.close


