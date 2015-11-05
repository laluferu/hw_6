kinetic_energy = 1.0
alpha = 30.0


grafica.pdf: trayectoria_E_alpha_$(kinetic_energy)_$(alpha).dat  
	python grafica.py trayectoria_E_alpha_$(kinetic_energy)_$(alpha).dat

trayectoria_E_alpha_$(kinetic_energy)_$(alpha).dat: particle_in_field.x
	./particle_in_field.x > trayectoria_E_alpha.dat

particle_in_field.x: particle_in_field.c
	cc particle_in_field.c -lm -o particle_in_field.x 

clean:
	rm -f grafica.pdf trayectoria_E_alpha.dat 

