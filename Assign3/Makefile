BISECTION = bisection.cpp
FIXED = fixedPointIteration.cpp

CC = g++
DEBUG_FLAGS = -O0 -g3 -fsanitize=address
RELEASE_FLAGS = -O3 -g0
FLAGS = -std=c++14 -Wall -Wextra

bisection: $(BISECTION)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(BISECTION) -o bisection

fixed: $(FIXED)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(FIXED) -o fixed

debug: $(OBJS) 
		$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS) -o debug && cgdb ./debug
