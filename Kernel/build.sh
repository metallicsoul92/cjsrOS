mkdir bin
echo -e "Starting To build Kernel":
echo -e "compiling boot.asm"
nasm -f elf32 boot.asm -o bin/boot.o
echo -e "Compiling crti.asm"
nasm -f elf32 crti.asm -o bin/crti.o
echo -e "Compiling crtn.asm"
nasm -f elf32 crtn.asm -o bin/crtn.o
echo -e "adding crtbegin.o"
cp $(gcc $CFLAGS -print-file-name=crtbegin.o) bin/crtbegin.o
echo -e "adding crtend.o"
cp $(gcc $CFLAGS -print-file-name=crtend.o) bin/crtend.o
echo -e "compiling kernel files:"
echo -e "kernel.c"
gcc -m32 -c src/kernel.c -o bin/main.o  -ffreestanding -nostdlib -nostdinc -fno-builtin -fno-stack-protector
echo -e "-linking kernelfiles"
#set -x
ld -T linker.ld   bin/crti.o bin/crtbegin.o bin/boot.o bin/main.o  bin/crtend.o bin/crtn.o /media/sf_cjsrOS/bin/liblibre-c.a -o bin/kernel32.bin 
