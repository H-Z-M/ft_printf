#!/bin/bash

if [ $# -eq 0 ]; then
	make
	gcc -o cexe main.c libftprintf.a
	./cexe > result.txt
	gcc -o cexe main.c libftprintf.a -D binary
	./cexe > binary.txt
	uniq -u binary.txt > binary_diff.txt
	FILE=binary_diff.txt
	if [ ! -s $FILE ]; then
		rm $FILE
	fi
	make fclean
	LANG=C
	sed '/*/d' result.txt > uniq.txt
	cat uniq.txt | awk '(NR%2==1){print}' > actual.txt
	cat uniq.txt | awk '(NR%2==0){print}' > expected.txt
	rm cexe uniq.txt
	diff actual.txt expected.txt > diff.txt
	FILE=diff.txt
	if [ ! -s $FILE ]; then
		rm $FILE
	else
		vi $FILE
	fi
	grep "PRINTF((" main.c | sed -e 's/\tPRINTF/ /g' -e 's/((/(/' -e 's/));/)/' > printftest.txt
else
	rm diff.txt actual.txt expected.txt result.txt binary.txt binary_diff.txt printftest.txt
fi
