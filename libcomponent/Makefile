# build all
all: test_libcomponent

test_libcomponent: libcomponent.so
	gcc -o test_libcomponent test_libcomponent.c -L. -lcomponent -Wl,-rpath,.


#The shared library is created with: 
#% gcc -shared -fPIC -o libtest.so testfile.o (-shared produces a shared object which can be linked).
# lib3
libcomponent.so: component.o
	gcc -shared -fPIC -o libcomponent.so component.o


#An object file intended to be used in a shared library is created by gcc with the argument -fPIC:
#% gcc -c -fPIC testfile.c
#-c tells the compiler to assemble and compile, but not link, the object file
#-fPIC generates position independent code,
component.o: component.c component.h
	gcc -c -fPIC component.c

clean:
	rm -rf *.o *.so *.a test_libcomponent