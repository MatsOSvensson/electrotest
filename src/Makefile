# compiler
CC=gcc

# Where to put shared libraries and obj files while building/linking
LIB_DIR=lib

# Install destinations
BIN_DESTINATION = /usr/local/bin
LIB_DESTINATION = /usr/local/$(LIB_DIR)

#-fPIC generates position independent code in object files
LIBCOM=-c -fpic

#-shared produces a shared object, .so, which can be linked
LIB_SHARED=-shared -o

############################

# Build all
all: electrotest

# Create the lib directory and the libs 
lib: $(shell mkdir -p $(LIB_DIR)) $(LIB_DIR)/libcomponent.so $(LIB_DIR)/libpower.so $(LIB_DIR)/libresistance.so

# Electrotest program building and linking
electrotest: lib 
	$(CC) -o $@ electrotest.c -L$(LIB_DIR) -lcomponent -lpower -lresistance -Wl,-rpath,$(LIB_DESTINATION)

# Electrotest program linking for debug purpose in current directory
# The difference from ordinary linking is the -rpath (runtime search path) option which in this case points
# to the lib subdir in current folder
electrotest_debug: lib
	$(CC) -o electrotest electrotest.c -L$(LIB_DIR) -lcomponent -lpower -lresistance -Wl,-rpath,$(LIB_DIR)

# Shared libraries, rule with automatic variables, all that matches lib%.so, 
# that is libcomponent.so with dependency component.o and so on
$(LIB_DIR)/lib%.so: $(LIB_DIR)/%.o
	$(CC) $(LIB_SHARED) $@ $^

# Library objects, *.o files, rule with automatic variables, that is all .o with corresponding .c and .h files
$(LIB_DIR)/%.o: %.c %.h
	$(CC) $(LIBCOM) $< -o $@

############################

install:
	cp electrotest $(BIN_DESTINATION); cp $(LIB_DIR)/libpower.so $(LIB_DESTINATION); cp $(LIB_DIR)/libcomponent.so $(LIB_DESTINATION); cp $(LIB_DIR)/libresistance.so $(LIB_DESTINATION)

clean:
	rm -rf *.o *.so *.a electrotest $(LIB_DIR)

uninstall:
	rm $(BIN_DESTINATION)/electrotest; rm $(LIB_DESTINATION)/libpower.so; rm $(LIB_DESTINATION)/libresistance.so;rm $(LIB_DESTINATION)/libcomponent.so 
