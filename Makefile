encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c -o encrypt.o

checksum.o: checksum.c checksum.h
	gcc -c checksum.c -o checksum.o

libhfsecurity.a: encrypt.o	checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o

bank_vault: bank_vault.c libhfsecurity.a
	gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault