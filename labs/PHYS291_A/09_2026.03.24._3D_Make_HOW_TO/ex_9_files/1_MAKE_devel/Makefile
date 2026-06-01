

all: fortran_comp C_comp binar.c ctest_fgets.c

binar:	binar.c
	gcc -o binar binar.c

ffgets: ctest_fgets.c
	gcc -o ffgets ctest_fgets.c 

C_comp: comp.c
	gcc -o C_comp comp.c

fortran_comp: comp.f
	gfortran -o fortran_comp comp.f

test: 
	./fortran_comp
	./C_comp

clean: 
	rm -f  fortran_comp C_comp binar.c ctest_fgets.c

