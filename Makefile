testSort: main.o bubble.o merge.o quickR.o quickM.o quick3M.o heap.o
	gcc main.o bubble.o merge.o quickR.o quickM.o quick3M.o heap.o -o testSort
main.o: main.c
	gcc -c -w main.c
bubble.o: bubble.c
	gcc -c bubble.c
merge.o: merge.c
	gcc -c merge.c
quickR.o: quickR.c
	gcc -c quickR.c
quickM.o: quickM.c
	gcc -c quickM.c
quick3M.o: quick3M.c
	gcc -c quick3M.c
heap.o: heap.c
	gcc -c heap.c
clean:
	rm -rf *.o testSort	
