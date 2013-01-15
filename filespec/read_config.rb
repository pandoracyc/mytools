#!/usr/bin/ruby
require "csv"

def read_config_file(file_prefix, extension )
	#FILE INFOMATION
	p configure_file=sprintf("%s_%s.conf",file_prefix ,extension)

	# open file
	config_fp = CSV.open(configure_file,"rb")

	# read record
	print "----------------------------------------\n"
	p sprintf("%s.%s" ,file_prefix ,extension )
	print "----------------------------------------\n"
	unit = Array.new
	keys = Array.new
	pack_template = Array.new
	i = 0
	while section = config_fp.readline
		unit[i] = section.join
		keys[i] = config_fp.readline
		pack_template[i] = config_fp.readline
	#	alist = pack_template[i].zip(keys[i])
	#	p Hash[alist]

		# print section
		print "unit : "
		p unit[i]
		print "keys : "
		p keys[i].join
		print "pack_template : "
		p pack_template[i]
		print "\n"

		i += 1
	end

	alist = unit.zip(keys)
	$file_keys = Hash[alist]
	#p file_keys["head"]
	#p file_keys["body"]

	alist = unit.zip(pack_template)
	$file_pack_template = Hash[alist]
	#p file_pack_template["head"]
	#p file_pack_template["body"]

	# close file
	config_fp.close

end
