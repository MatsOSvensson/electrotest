# compiler
CC=gcc

#Where to put shared libraries
LIB_DIR=lib
MKDIR=mkdir -p

#-fPIC generates position independent code,
LIBCOMP=-c -fpic

#-shared produces a shared object which can be linked
LIB_SHARED=-shared -o

# where to put .o files
ODIR=obj

# build all
all: directories test_libcomponent

#build lib
lib: libcomponent.so

#LDFLAGS := -L<path to lib> -l<libname>
test_libcomponent: libcomponent.so
	$(CC) -o $@ test_libcomponent.c -L. -lcomponent -Wl,-rpath,.

#The shared library is created with: 
#% gcc -shared -fPIC -o libtest.so testfile.o (-shared produces a shared object which can be linked).
# lib3
libcomponent.so: component.o
	$(CC) $(LIB_SHARED) $@ $^

#An object file intended to be used in a shared library is created by gcc with the argument -fPIC:
#% gcc -c -fPIC testfile.c
#-c tells the compiler to assemble and compile, but not link, the object file
#-fPIC generates position independent code,
component.o: component.c component.h
	$(CC) $(LIBCOMP) component.c

directories: $(LIB_DIR)

$(LIB_DIR):
	$(MKDIR) $(LIB_DIR)

clean:
	rm -rf *.o *.so *.a test_libcomponent $(LIB_DIR)