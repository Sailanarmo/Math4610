OBJS = main.cpp matrixProduct.hpp matrixProduct.cpp mxv.hpp mxv.cpp

CC = g++
DEBUG_FLAGS = -O0 -g3 -fsanitize=address
RELEASE_FLAGS = -O3 -g0 -fopenmp
FLAGS = -std=c++14 -Wall -Wextra

release: $(OBJS)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS) -o release

debug: $(OBJS) 
		$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS) -o debug && cgdb ./debug
