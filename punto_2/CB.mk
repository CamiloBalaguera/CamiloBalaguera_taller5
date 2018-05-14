cuerda.mp4 : CB_graph.py 	cuerda.cpp
	c++ cuerda.cpp
	./a.out > datos.dat
	python3 CB_graph.py

datos.dat : cuerda.cpp
	c++ cuerda.cpp
	./a.out > datos.dat
