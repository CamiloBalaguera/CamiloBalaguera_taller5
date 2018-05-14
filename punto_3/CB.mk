caos.pdf : caos.py caos.cpp
	c++ caos.cpp -o caos.x
	./caos.x > caos.dat
	python3 caos.py

caos.dat : caos.cpp
	c++ caos.cpp -o caos.x
	./caos.x > caos.dat
