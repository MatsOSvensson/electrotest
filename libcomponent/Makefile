# compiler
CC=gcc

#Where to put shared libraries
LIB_DIR=lib
MKDIR=mkdir -p

#Bin destination
BIN_DESTINATION = /usr/local/bin
LIB_DESTINATION = /usr/local/lib

#-fPIC generates position independent code,
LIBCOM=-c -fpic

#-shared produces a shared object which can be linked
LIB_SHARED=-shared -o

# where to put .o files
ODIR=obj

# build all
all: directories electrotest

#build lib
lib: libcomponent.so libpower.so libresistance.so

#LDFLAGS := -L<path to lib> -l<libname>
electrotest: libcomponent.so libpower.so libresistance.so
	$(CC) -o $@ electrotest.c -L. -lcomponent -lpower -lresistance -Wl,-rpath,.

#The shared library is created with: 
#% gcc -shared -fPIC -o libtest.so testfile.o (-shared produces a shared object which can be linked).
# lib3
libcomponent.so: component.o
	$(CC) $(LIB_SHARED) $@ $^

libpower.so: power.o
	$(CC) $(LIB_SHARED) $@ $^

libresistance.so: resistance.o
	$(CC) $(LIB_SHARED) $@ $^

#An object file intended to be used in a shared library is created by gcc with the argument -fPIC:
#% gcc -c -fPIC testfile.c
#-c tells the compiler to assemble and compile, but not link, the object file
#-fPIC generates position independent code,
component.o: component.c component.h
	$(CC) $(LIBCOM) component.c

power.o: power.c power.h
	$(CC) $(LIBCOM) power.c

resistance.o: resistance.c resistance.h
	$(CC) $(LIBCOM) resistance.c

directories: $(LIB_DIR)

$(LIB_DIR):
	$(MKDIR) $(LIB_DIR)

install: electrotest
	cp electrotest $(BIN_DESTINATION); cp libpower.so $(LIB_DESTINATION); cp libcomponent.so $(LIB_DESTINATION); cp libresistance.so $(LIB_DESTINATION)

clean:
	rm -rf *.o *.so *.a electrotest $(LIB_DIR)

uninstall: electrotest
	rm $(BIN_DESTINATION)/electrotest; rm $(LIB_DESTINATION)/libpower.so; rm $(LIB_DESTINATION)/libresistance.so;rm $(LIB_DESTINATION)/libcomponent.so 
