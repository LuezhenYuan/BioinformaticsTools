#!/bin/bash
file=$1
head -n 400 $file|awk 'BEGIN{FS=""; version=64; for(i=0;i<=126;i++) ord[sprintf("%c",i)]=i;} {if(NR%4==0){for(i=1;i<=NF;i++){if(ord[$i]<64){version=33;exit;}}}} END{print version;}'

exit 0;
