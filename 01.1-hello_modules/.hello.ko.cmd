cmd_/home/linux/first/hello.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id  -T ./scripts/module-common.lds -o /home/linux/first/hello.ko /home/linux/first/hello.o /home/linux/first/hello.mod.o;  true