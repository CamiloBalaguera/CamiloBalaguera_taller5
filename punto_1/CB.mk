placas.pdf : placas.cpp grafica.py
	c++ placas.cpp 
	./a.out > datos.dat
	python3 grafica.py

datos.dat : placas.cpp
	c++ placas.cpp
	./a.out > datos.dat
