#!/bin/bash

path=$1
file_path=$2
touch $file_path

find $path -type f -name "*.txt" | while read txt; 
	do 
		count=`cat $txt | wc -m `
		echo -e "Pentru fisierul $txt numarul de caractere este: $count" #>> $file_path
	done
