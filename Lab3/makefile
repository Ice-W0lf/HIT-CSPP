CC	= gcc -m64 -w

#.. What optimization level for the compilers?
#COPT	= -O2
COPT	= -g


GRARC	 = sort.a
GRSRCS	 = swap.c selectSort.c main.c bubbleSort.c insertSort.c quickSort.c mergeSort.c heapSort.c quickSortTest.c
GROBJS	 = swap.o selectSort.o main.o bubbleSort.o insertSort.o quickSort.o mergeSort.o heapSort.o quickSortTest.o
HEADER   = sort.h

runsort: $(GROBJS)
	$(CC) $(COPT) -o runsort $(GROBJS) 

main.o: main.c sort.h
	$(CC) $(COPT) -c main.c -o main.o
swap.o: swap.c sort.h
	$(CC) $(COPT) -c swap.c -o swap.o
selectSort.o: selectSort.c sort.h
	$(CC) $(COPT) -c selectSort.c -o selectSort.o
bubbleSort.o: bubbleSort.c sort.h
	$(CC) $(COPT) -c bubbleSort.c -o bubbleSort.o
insertSort.o: insertSort.c sort.h
	$(CC) $(COPT) -c insertSort.c -o insertSort.o
quickSort.o: quickSort.c sort.h
	$(CC) $(COPT) -c quickSort.c -o quickSort.o
mergeSort.o: mergeSort.c sort.h
	$(CC) $(COPT) -c mergeSort.c -o mergeSort.o
heapSort.o: heapSort.c sort.h
	$(CC) $(COPT) -c heapSort.c -o heapSort.o
quickSortTest.o: quickSortTest.c sort.h
	$(CC) $(COPT) -c quickSortTest.c -o quickSortTest.o


clean   :
	rm -f $(GROBJS) runsort
