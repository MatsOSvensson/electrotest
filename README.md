# electrotest
labb6

# Makefile rules

https://www.gnu.org/software/make/manual/make.html
  
Rules that compiles ‘.c’ files into ‘.o’ files:

    %.o : %.c
      $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

// work in a folder named lib

    lib/%.o: lib/%.c
      $(CC) -fPIC -c $(CFLAGS) $(CPPFLAGS) $< -o $@
    
   
Here is an example, which compiles each of foo.o and bar.o from the corresponding .c file:

    objects = foo.o bar.o

    all: $(objects)

    $(objects): %.o: %.c
      $(CC) -c $(CFLAGS) $< -o $@
        
Here ‘$<’ is the automatic variable that holds the aname of the prerequisite and ‘$@’ is the automatic variable 
that holds the name of the target
