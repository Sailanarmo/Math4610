PROB = prob5.cpp
APRO = aprox.cpp

CC = g++
DEBUG_FLAGS = -O0 -g3 -fsanitize=address
RELEASE_FLAGS = -O3 -g0
FLAGS = -std=c++14 -Wall -Wextra

prob5: $(PROB)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(PROB) -o prob5

aprox: $(APRO)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(APRO) -o aprox

