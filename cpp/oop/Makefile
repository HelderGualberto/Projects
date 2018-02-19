#Compiler thats being used
CC = g++

CFLAGS = -I. --std=c++11

DEPS = physics_vector.hpp

OBJ = main.o physics_vector.o

#All .o files will be created
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	$(CC) -o $@ $^ $(CFALGS)
