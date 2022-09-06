CC	   = gcc -w

COPT   = -g

GRSRCS = main.c opmain.c print.c search.c sort.c
GROBJS = main.o opmain.o print.o search.o sort.o
HEADER = op.h sort.h stucourse.h

infosys: $(GROBJS)
	$(CC) $(COPT) -o infosys $(GROBJS)

main.o: main.c op.h
	$(CC) $(COPT) -c main.c -o main.o
opmain.o: opmain.c op.h sort.h
	$(CC) $(COPT) -c opmain.c -o opmain.o
print.o: print.c op.h stucourse.h
	$(CC) $(COPT) -c print.c -o print.o
search.o: search.c op.h stucourse.h
	$(CC) $(COPT) -c search.c -o search.o
sort.o: sort.c sort.h stucourse.h
	$(CC) $(COPT) -c sort.c -o sort.o

clean   :
	rm -f $(GROBJS) infosys
