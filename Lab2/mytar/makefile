CC	= gcc -m64 -w

COPT	= -g

GRARC	 = mytar.a
GRSRCS	 = main.c mytar.c
GROBJS	 = main.o mytar.o
HEADER   = mytar.h

mytar: $(GROBJS)
	$(CC) $(COPT) -o mytar $(GROBJS)

main.o: main.c mytar.h
	$(CC) $(COPT) -c main.c -o main.o

mytar.o: mytar.c mytar.h
	$(CC) $(COPT) -c mytar.c -o mytar.o

clean:
	rm -f $(GROBJS) mytar test.pkg
	rm -rf testfolder
