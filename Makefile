fish.o: fish.c
	gcc -c fish.c
fish: fish.o
	gcc fish.o -o fish