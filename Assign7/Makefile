JACOBI = jacobi.cpp matrixGen.hpp
GAUSS = gaussSiedel.cpp matrixGen.hpp
CONJGRAD = conjGrad.cpp matrixGen.hpp

CC = g++
DEBUG_FLAGS = -O0 -g3 -fsanitize=address
RELEASE_FLAGS = -O3 -g0
FLAGS = -std=c++14 -Wall -Wextra

jacobi: $(JACOBI)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(JACOBI) -o jacobi

gauss: $(GAUSS)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(GAUSS) -o gauss

conjGrad: $(CONJGRAD)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(CONJGRAD) -o conjGrad

debug: $(OBJS) 
		$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS) -o debug && cgdb ./debug
