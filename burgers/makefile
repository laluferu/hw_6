
gif.gif: archivo.dat 
	python gif.py

archivo.dat: burger.x
	./burger > archivo.dat

burgers: burgers.c
	cc burger.c -lm -o burger.x

clean:
	rm -f gif.gif archivo.dat 

