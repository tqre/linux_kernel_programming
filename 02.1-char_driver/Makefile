obj-m	:= scull.o

all: compile clean

compile:
	make -C /home/linux/git/kernels/staging M=`pwd` modules

clean:
	@rm -v *.mod* modules.order Module.symvers .scull*
	@rm -v *.o

