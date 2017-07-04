mkdir bin
echo -e "Starting To build Kernel":
echo -e "compiling boot.asm"
nasm -f elf32 boot.asm -o bin/boot.o
echo -e "Compiling crti.asm"
nasm -f elf32 crti.asm -o bin/crti.o
echo -e "Compiling crtn.asm"
nasm -f elf32 crtn.asm -o bin/crtn.o
echo -e "adding crtbegin.o"
gcc $CFLAGS -print-file-name=crtbegin.o
echo -e "adding crtend.o"
gcc $CFLAGS -print-file-name=crtend.o
echo -e "compiling kernel files:"
echo -e "kernel.c"
gcc -m32 src/kernel.c -o bin/main.o -nostdlib -nostdinc -fno-builtin -fno-stack-protector
echo -e "-linking kernelfiles"
set -x
ld -T linker.ld -melf_i386 bin/boot.o bin/main.o  -o bin/kernel32.bin
