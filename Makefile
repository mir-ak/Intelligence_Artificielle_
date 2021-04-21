tetris: include/*.h src/*cpp
	g++ src/*cpp -o tetris -pthread -g
clean:
	rm game
