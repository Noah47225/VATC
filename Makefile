game.exe: main.cpp
	g++ main.cpp plane.cpp obj.cpp -o game.exe -I./include -L./lib -lSDL3