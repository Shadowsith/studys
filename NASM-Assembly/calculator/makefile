bin: main.o subradd.o subrsub.o subrmul.o subrdiv.o
	gcc -m32 main.o subradd.o subrsub.o subrmul.o subrdiv.o -o bin

main.o: main.asm
	  nasm -f elf32 main.asm

subradd.o: subradd.asm
	    nasm -f elf32 subradd.asm

subrsub.o: subrsub.asm
	    nasm -f elf32 subrsub.asm

subrmul.o: subrmul.asm
	    nasm -f elf32 subrmul.asm
	    
subrdiv.o: subrdiv.asm
	    nasm -f elf32 subrdiv.asm

clean: bin main.o subradd.o subrsub.o subrmul.o
	 rm -f bin main.o subradd.o subrsub.o subrmul.o subrdiv.o
