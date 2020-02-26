obj-m	:= kwriter.o

all: compile clean

compile:
	make -C /home/linux/kernel_source M=`pwd` modules

clean:
	@rm -v *.mod* modules.order Module.symvers .kwriter*
	@rm -v *.o

