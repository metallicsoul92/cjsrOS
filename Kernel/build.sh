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
echo -e "ports.asm"
nasm -f elf32 src/ports.asm -o bin/ports.o
echo -e "idtlst.asm"
nasm -f elf32 src/idtlst.asm -o bin/idtlst.o
echo -e "idt.c"
gcc -m32 -c src/idt.c -o bin/idt.o  -ffreestanding -nostdlib -nostdinc -fno-builtin -fno-stack-protector
echo -e "hdd.c"
gcc -m32 -c src/hdd.c -o bin/hdd.o  -ffreestanding -nostdlib -nostdinc -fno-builtin -fno-stack-protector
echo -e "kernel.c"
gcc -m32 -c src/kernel.c -o bin/main.o  -ffreestanding -nostdlib -nostdinc -fno-builtin -fno-stack-protector
echo -e "-linking kernelfiles"
set -x
ld -n -T linker.ld bin/boot.o bin/main.o bin/ports.o bin/idt.o bin/idtlst.o bin/hdd.o /media/sf_cjsrOS/bin/liblibre-c.a -o bin/kernel32.bin
