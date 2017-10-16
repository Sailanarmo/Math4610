OBJS = main.cpp vectorNorm.hpp vectorNorm.cpp matrixNorm.hpp matrixNorm.cpp vectorError.hpp vectorError.cpp matrixAddition.hpp matrixAddition.cpp matrixSubtraction.hpp matrixSubtraction.cpp dotProduct.hpp dotProduct.cpp matrixProduct.hpp matrixProduct.cpp mxv.hpp mxv.cpp

CC = g++
DEBUG_FLAGS = -O0 -g3 -fsanitize=address
RELEASE_FLAGS = -O3 -g0 -fopenmp
FLAGS = -std=c++14 -Wall -Wextra

release: $(OBJS)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS) -o release

debug: $(OBJS) 
		$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS) -o debug && cgdb ./debug
