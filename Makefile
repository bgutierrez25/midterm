all:	mid19	unittest
	g++	mid19.cpp	-Wall	-Wextra	-omid19
	g++	unittest.cpp	-Wall	-Wextra	-ounittest
clean:	
	rm	-f	unittest	mid19
