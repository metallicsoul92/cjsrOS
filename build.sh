#Build the CLibrary:
echo -e "Building the C Library:"
cd "Libc/bin"
cmake ../
make
cp liblibre-c.a ../../bin/liblibre-c.a
chmod u+x ../../bin/liblibre-c.a

echo -e "Building Kernel Files "
cd "../../Kernel"
./build.sh

cd ../
echo $PWD

echo -e "Creating The Bootloader"

if grub-file --is-x86-multiboot Kernel/bin/kernel32.bin; then
	echo -e "-setup GRUB bootloader"
	mkdir -p bin/isodir/boot/grub
	cp bin/liblibre-c.a bin/isodir/boot/kernel32.bin ####
	cp Kernel/bin/kernel32.bin bin/isodir/boot/kernel32.bin
	cp grub.cfg bin/isodir/boot/grub/grub.cfg
	grub-mkrescue -o kerneliso.iso bin/isodir
	echo -e "SUCCESS"
else
	echo -e "Invalid build"
fi
