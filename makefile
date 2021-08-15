shell: shell.o prefixCalc.o fileInteraction.o
	cc shell.o prefixCalc.o fileinteraction.o -o shell

shell.o: shell.c headerfile.h
	cc -c shell.c

prefixCalc.o: prefixCalc.c
	cc -c prefixCalc.c

fileInteraction.o: fileinteraction.c
	cc -c fileinteraction.c
