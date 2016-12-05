#!/usr/bin/env python
# Remove pair-end read that located in the same chromosome
# Input: two sorted sam files
# Use: python Remove_Pairends_InSameChr.py <.sam> <.sam>
# e.g.: python Remove_Pairends_InSameChr.py try_1.sam try_2.sam
# Parameters
#  sys.argv[1]:first-end sam file
#  sys.argv[2]:second-end sam file
#
# How to sort sam file:
#  !!Don't use samtools sort, this only sort based on chromosome!!
#  I use:
#    tail -n +28 <.sam>|nohup sort -t"." -k 2 --buffer-size=500M -n >><.sam> &
#    Here "+28" is used to remove the header section of the sam file, and here I removed first 28 lines(You should see your original sam file)
import sys
import resource #monitor memory useage, resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
try:
	infile1=open(sys.argv[1],'r')
	infile2=open(sys.argv[2],'r')
except:
	print('Could not open the file '+sys.argv[1]+' or '+sys.argv[2]+"\n")
	exit(1)

file1_I=iter(infile1)
file2_I=iter(infile2)

out1=open(sys.argv[1].split(".")[0]+'_InDiffChr.'+'.'.join(sys.argv[1].split(".")[1:]),'w')
out2=open(sys.argv[2].split(".")[0]+'_InDiffChr.'+'.'.join(sys.argv[2].split(".")[1:]),'w')

# header section
try:
	while True:
		line1=next(file1_I)
		if line1[0]=="@":
			out1.write(line1)
		else:
			break
	
	while True:
		line2=next(file2_I)
		if line2[0]=="@":
			out2.write(line2)
		else:
			break
except:
	print("No alignment section in your sam file")
	out1.close()
	out2.close()
	exit(1)

# alignment section
try:
	while True:
		line1_Arr=line1.split("\t");
		line2_Arr=line2.split("\t");
		while line1_Arr[0].split('.')[1] != line2_Arr[0].split('.')[1]:
			if line1_Arr[0].split('.')[1] < line2_Arr[0].split('.')[1]:
				line1=next(file1_I)
				line1_Arr=line1.split("\t");
			else:
				line2=next(file2_I)
				line2_Arr=line2.split("\t");
		if line1_Arr[2]!="*" and line2_Arr[2]!="*" and line1_Arr[2]!=line2_Arr[2]:
			out1.write(line1)
			out2.write(line2)
		line1=next(file1_I)
		line2=next(file2_I)
except:
	print("Finished!")


out1.close()
out2.close()
