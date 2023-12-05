PROJ = Tormenta20
PROJ_DEV = Tormenta20-dev
CC = g++

FLAGS = -I ./ -pedantic -Wall -pipe
BUILD_FAGS = -O3

SDL_FLAGS = -lmingw32 -L "C:/MinGW/include/SDL2/lib" -lSDL2 -lSDL2main -lSDL2_image

#

# SOURCE

SOURCE = $(wildcard *.cpp) $(wildcard assets/*.cpp)

#

build: clear
	$(CC) $(SOURCE) -o $(PROJ) $(SDL_FLAGS) $(FLAGS) $(BUILD_FLAGS)
	@echo $(PROJ).exe compiled sucessfully!
	./$(PROJ)

dev: clear
	$(CC) $(SOURCE) -o $(PROJ_DEV) $(SDL_FLAGS) $(FLAGS)
	@echo $(PROJ_DEV).exe compiled sucessfully!
	./$(PROJ_DEV)


clear:
	@cls
