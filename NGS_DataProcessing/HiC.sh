#!/bin/bash
# Processing HiC data
# Should be PAIRED-end sequencing
# e.g.: ./HiC.sh --restriction_site "AAGCTT" --thread 5 --sample SRR639029 --trimmomatic_loc ~/tools/bin/trimmomatic-0.36.jar --Remove_Pairends_InSameChr_loc ../../tools/bin/Remove_Pairends_InSameChr.py --genome ../Genome/GRCh38/GRCh38.p3.fa --genome_index_loc ../Genome/GRCh38/GRCh38_p3_ref --step 123456
sample=""
trimmomatic_loc="" #"~/tools/bin/trimmomatic-0.36.jar" # input file
genome_index_loc="" #"../Genome/GRCh38/GRCh38_p3_ref" # input file
Remove_Pairends_InSameChr_loc="" #"../../tools/bin/Remove_Pairends_InSameChr.py" # input file
genome="" #"../Genome/GRCh38/GRCh38.p3.fa" # input file
Homer_dir=""
fastq_1=""
sam_1=""
fastq_2=""
sam_2=""

Map_rate_loc="Map_rate.txt" # output file
thread=5
window_size=10000
restriction_site="AAGCTT" # HindIII
STEP=([1]=0 [2]=0 [3]=0 [4]=0 [5]=0 [6]=0 [7]=0 [8]=0)
# command line read
TEMP=`getopt -o hs: --long help,step:,sample:,trimmomatic_loc:,thread:,genome_index_loc:,Remove_Pairends_InSameChr_loc:,genome:,window_size:,restriction_site:,fastq_1:,fastq_2:,sam_1:,sam_2:,Homer_dir: -n '-h for getting help' -- "$@"`
eval set -- "$TEMP"

read -d '' help <<- EOF
---------
HiC data processing
---------
This script gives a One-Stop Solution for HiC data processing.
It depends on bowtie, fastq-dump, fastq_quality_filter, trimmomatic, fastqc, Homer (makeTagDirectory, and analyzeHiC), Remove_Pairends_InSameChr.py, and Guess_Encoding.sh.
Remove_Pairends_InSameChr.py is in https://github.com/LuezhenYuan/BioinformaticsTools
Guess_Encoding.sh is in https://github.com/LuezhenYuan/BioinformaticsTools
---------
Help for HiC data processing:

-h|--help
 	This help document
-s|--step <int>
 	Data processing steps you want to run (from 1 to 8, e.g.:--step 123456).
 	1:<.sra> to <.fastq>
 	2:filter low quality reads and trimmer low quality site
 	3:show quality of the sequencing
 	4:alignment with bowtie
 	5:sort <.sam> file based on the read id
 	6:reserve inter-chromosome interaction. Attention: This steps required sorted <.sam> file based on the read id
 	7:use Homer to filter noise in Hi-C data
 	8:use Homer to get interaction map
--genome <.fa>
 	Genome fasta file
--genome_index_loc <genome_index>
 	Genome index (indexed by bowtie)
--Remove_Pairends_InSameChr_loc <.py>
 	A python tool to remove pair-end read located in the same chromosome
--restriction_site <string>
 	Restriction site in HiC experiment. Original value is "AAGCTT"
--sample <id>
 	Sample id (e.g. SRR id)
--thread <int>
 	Number of threads used for this program
--trimmomatic_loc <.jar>
 	trimmomatic java software
--window_size <int>
 	window size used in Homer software (step 8). Original value is 10000

The following parameters should be provided if you don't run some former steps
--Homer_dir <dir>
 	If you don't run step 7 but run step 8
--fastq_1 	If you don't run step 1
--fastq_2 	If you don't run step 1
--sam_1 	If you don't run step 4
--sam_2 	If you don't run step 4

EXAMPLE
./HiC.sh --restriction_site "AAGCTT" --thread 5 --sample SRR639029 --trimmomatic_loc ~/tools/bin/trimmomatic-0.36.jar --Remove_Pairends_InSameChr_loc ../../tools/bin/Remove_Pairends_InSameChr.py --genome ../Genome/GRCh38/GRCh38.p3.fa --genome_index_loc ../Genome/GRCh38/GRCh38_p3_ref --step 123456
---------
Version 1.0 in Dec 7 2016
Author: Luezhen (lzyuan@zju.edu.cn)
---------
EOF


while true; do
	case "$1" in
		-h|--help) echo "$help" ; exit 0;shift ;;
		-s|--step) i=$2; while [[ $i > 0 ]]; do
			STEP[$[ $i%10 ]]=1;
			i=$[ $i/10 ];
			done
			shift 2 ;;
		--sample)
			case "$2" in
				"") echo "Error! Need --sample"; exit 1;;
				*) if [ -e $2".sra" ]; then sample=$2;
					else echo "Error! Need $2'.sra' file"; exit 1;
					fi
					shift 2 ;;
			esac ;;
		--trimmomatic_loc)
			case "$2" in
				"") echo "Error! Need --trimmomatic_loc"; exit 1;;
				*) if [ -e $2 ]; then trimmomatic_loc=$2;
					else echo "Error! Need trimmomatic jar file"; exit 1;
					fi
					shift 2 ;;
			esac ;;
		--thread)
			case "$2" in
				"") thread=5;shift 2 ;;
				*) thread=$2;shift 2 ;;
			esac ;;
		--genome_index_loc)
			case "$2" in
				"") echo "Error! Need --genome_index_loc"; exit 1;;
				*) if [ -e $2".1.ebwt" ]; then genome_index_loc=$2;
					else echo "Error! Need genome_index file"; exit 1;
					fi
					shift 2 ;;
			esac ;;
		--Remove_Pairends_InSameChr_loc)
			case "$2" in
				"") echo "Error! Need --Remove_Pairends_InSameChr_loc"; exit 1;;
				*) if [ -e $2 ]; then Remove_Pairends_InSameChr_loc=$2;
					else echo "Error! Need Remove_Pairends_InSameChr python file"; exit 1;
					fi
					shift 2 ;;
			esac ;;
		--genome)
			case "$2" in
				"") echo "Error! Need --genome"; exit 1;;
				*) if [ -e $2 ]; then genome=$2;
					else echo "Error! Need genome fasta file"; exit 1;
					fi
					shift 2 ;;
			esac ;;
		--window_size)
			case "$2" in
				"") window_size=10000;shift 2 ;;
				*) window_size=$2;shift 2 ;;
			esac ;;
		--restriction_site)
			case "$2" in
				"") restriction_site="AAGCTT";shift 2 ;;
				*) restriction_site=$2; shift 2 ;;
			esac ;;
		--fastq_1) fastq_1=$2;shift 2 ;;
		--fastq_2) fastq_2=$2;shift 2 ;;
		--sam_1) sam_1=$2;shift 2 ;;
		--sam_2) sam_2=$2;shift 2 ;;
		--Homer_dir) Homer_dir=$2;shift 2 ;;
		--) shift ; break ;;
		*) echo "Error parameters!" ; exit 1 ;;
	esac
done

if [[ $trimmomatic_loc == "" ]]; then echo "Error! Need --trimmomatic_loc"; exit 1; fi
if [[ $Remove_Pairends_InSameChr_loc == "" ]]; then echo "Error! Need --Remove_Pairends_InSameChr_loc"; exit 1; fi
if [[ $genome == "" ]]; then echo "Error! Need --genome"; exit 1; fi
if [[ $genome_index_loc == "" ]]; then echo "Error! Need --genome_index_loc"; exit 1; fi
if [[ $sample == "" ]]; then echo "Error! Need --sample"; exit 1; fi



# step 1:<.sra> to <.fastq>
if [[ ${STEP[1]} == 1 ]]; then
fastq-dump --split-3 $sample".sra" 2>>$sample"_fastq-dump.out" # PAIRED
chmod 444 $sample"_{1,2}.fastq"
encoding_version=`bash Guess_Encoding.sh $sample"_1.fastq"` #33 or 64
fastq_1=$sample"_1.fastq"
fastq_2=$sample"_2.fastq"
fi

# step 2:filter low quality reads and trimmer low quality site
if [[ ${STEP[2]} == 1 ]]; then
fastq_quality_filter -Q $encoding_version -q 20 -p 80 -i $fastq_1 -o $sample"_1_filter.fastq"
fastq_quality_filter -Q $encoding_version -q 20 -p 80 -i $fastq_2 -o $sample"_2_filter.fastq"
java -jar $trimmomatic_loc SE -threads $thread "-phred"$encoding_version $sample"_1_filter.fastq" $sample"_1_trimmed.fastq" LEADING:20 TRAILING:20 2>>$sample"_1_trimmed.out"
java -jar $trimmomatic_loc SE -threads $thread "-phred"$encoding_version $sample"_2_filter.fastq" $sample"_2_trimmed.fastq" LEADING:20 TRAILING:20 2>>$sample"_2_trimmed.out"
fastq_1=$sample"_1_trimmed.fastq"
fastq_2=$sample"_2_trimmed.fastq"
fi

# step 3:show quality of the sequencing
if [[ ${STEP[3]} == 1 ]]; then
fastqc $fastq_1
fastqc $fastq_2
fi
# scp ylz@10.71.115.210:/home/ylz/data/SRRdata/*fastqc.html . # move to a directory

# step 4:alignment with bowtie
##1. Discard all reads that do not uniquely map to a single genomic locus
##2. perform the alignment for each half of a paired-end read separately

# bowtie-build -f GRCh38.p3.fa GRCh38_p3_ref # biuld the .ebwt index file
if [[ ${STEP[4]} == 1 ]]; then
bowtie --threads $thread -m 1 -n 2 -e 70 -q $genome_index_loc "--phred"$encoding_version"-quals" $fastq_1 -S $sample"_1_aligned.sam"  1>>$sample"_1_bowtie.out"
bowtie --threads $thread -m 1 -n 2 -e 70 -q $genome_index_loc "--phred"$encoding_version"-quals" $fastq_2 -S $sample"_2_aligned.sam"  1>>$sample"_2_bowtie.out"
awk 'BEGIN{line="";print "File\talign\tfail\t>1";} {if(FNR==0){print line;line="";} if($0~/at least/){split($0,A,/[()]/);line=line""FILENAME"\t"A[2]"\t";} else if($0~/failed/){split($0,A,/[()]/);line=line""A[2]"\t";} else if($0~/suppressed/){split($0,A,/[()]/);line=line""A[2]"\n";} } END{print line;}' $sample"_1_bowtie.out" >>$Map_rate_loc
awk 'BEGIN{line="";print "File\talign\tfail\t>1";} {if(FNR==0){print line;line="";} if($0~/at least/){split($0,A,/[()]/);line=line""FILENAME"\t"A[2]"\t";} else if($0~/failed/){split($0,A,/[()]/);line=line""A[2]"\t";} else if($0~/suppressed/){split($0,A,/[()]/);line=line""A[2]"\n";} } END{print line;}' $sample"_2_bowtie.out" >>$Map_rate_loc
sam_1=$sample"_1_aligned.sam"
sam_2=$sample"_2_aligned.sam"
fi

# step 5:sort <.sam> file based on the read id
if [[ ${STEP[5]} == 1 ]]; then
sample="SRR639025"
header_section_sam=`awk 'BEGIN{i=0;} {if($0~/^@/){i=i+1;}else{print i;exit;}}' $sam_1`

tail -n "+"$header_section_sam $sam_1|sort -t"." -k 2 --buffer-size=500M -n >>$sample"_1_aligned_sort.sam"
tail -n "+"$header_section_sam $sam_2|sort -t"." -k 2 --buffer-size=500M -n >>$sample"_2_aligned_sort.sam"
sam_1=$sample"_1_aligned_sort.sam"
sam_2=$sample"_2_aligned_sort.sam"
fi

# step 6:reserve inter-chromosome interaction
if [[ ${STEP[6]} == 1 ]]; then
python $Remove_Pairends_InSameChr_loc $sam_1 $sam_2
awk -F"." '{line=$1"_InDiffChr";for(i=2;i<=NF;i++){line=line"."$i;}}' $sam_1
sam_1=`echo $sam_1|awk -F"." '{line=$1"_InDiffChr";for(i=2;i<=NF;i++){line=line"."$i;}} END{print line;}'`
sam_2=`echo $sam_2|awk -F"." '{line=$1"_InDiffChr";for(i=2;i<=NF;i++){line=line"."$i;}} END{print line;}'`
fi

# step 7:use Homer to filter noise in Hi-C data
if [[ ${STEP[7]} == 1 ]]; then
mkdir "Homer_"$sample"_filtered"
makeTagDirectory "Homer_"$sample"_filtered" $sam_1,$sam_2 -restrictionSite $restriction_site -genome $genome -removePEbg -removeSelfLigation 2>>"Homer_"$sample"_filtered/"$sample"_nohup_filtered.out"
Homer_dir="Homer_"$sample"_filtered"
fi
# step 8:use Homer to get interaction map

if [[ ${STEP[8]} == 1 ]]; then
analyzeHiC $Homer_dir"/" -res $window_size -superRes $[$window_size*2] -bgonly -cpu $thread
analyzeHiC $Homer_dir"/" analyzeHiC -res $window_size -superRes $[$window_size*2] -cpu $thread -norm > "Homer_"$sample"_filtered_analyzeHic_norm.txt"
fi

exit 0;
