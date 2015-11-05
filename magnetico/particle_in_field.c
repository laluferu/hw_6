/*
 * particle_in_field.c
 *
 *  Created on: 30/10/2015
 *      Author: Laura Ferrer
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265


int main(int argc, char **argv)
{
	double k = atof(argv[1]); // Energía cinética
	double alp = atof(argv[2]); //Ángulo
	double p[3]; //posición x, y, z.
	double b0= 3.0e-5; //
	double rt=6378.1; //Radio de la tierra en Km.
	double B[3]; //Campo magnético en 3 dimensiones.
	double v[3]; //Velocidades
	double q = 1.602176e-19; //Carga del protón en coulombs.
	double c =  299792458.0; //Velocidad de la luz en metros por segundo.
	double m = 1.672621e-27; //masa del protón en Kg.
	double c2 = pow(c,2.0); //c^2 para uso más fácil.
	double g = (k/(m*c2))+1; //factor Gamma con condición inicial
	double v0 = abs(c*sqrt((g-1)/g)); //Velocidad inicial en m/s.

	//Posiciones iniciales
	p[0] = 2*rt;
	p[1] = 0;
	p[2] = 0;

	//Velocidades iniciales
	v[0]=0;
	v[1]=v0*sin(alp*PI/180);
	v[2]=v0*cos(alp*PI/180);

	//Inicialización de las aceleraciones.
	double ax= 0.0;
	double ay= 0.0;
	double az= 0.0;

	double t = 0.0;
	double maxt = 100.0;
	double deltat = 1.0; //Cambios en el tiempo.

	void f(double x, double y, double z)
	{
		double r = pow(pow(x,2.) + pow(y,2.) + pow(z,2.),0.5);
		double vec[3] = {3.0*x*z, 3.0*y*z, 2*pow(z,2.)-pow(x,2.)-pow(y,2.)};

		printf ("%g,%g,%g,%g\n", t, p[0], p[1], p[2]);
		B[0] = -b0*pow(rt,3.)*vec[0]/pow(r,5.);
		B[1] = -b0*pow(rt,3.)*vec[1]/pow(r,5.);
		B[2] = -b0*pow(rt,3.)*vec[2]/pow(r,5.);

		double v2 = pow(v[0],2.) + pow(v[1],2.) + pow(v[0],2.);
		g = 1.0/pow(1.0-(v2/c2),0.5);

		//Producto cruz
		ax= q*(v[1]*B[2]-v[2]*B[1])/m*g; //Aceleraciones
		ay= -q*(v[0]*B[2]-v[2]*B[0])/m*g;
		az= q*(v[0]*B[1]-v[1]*B[0])/m*g;
	}

	while (t<maxt) // implementación del método  Euler
	{
		f(p[0],p[1],p[2]); //actualización de estádos.

		v[0] += ax;
		v[1] += ay;
		v[2] += az;

		//Movimiento
		p[0]+= v[0];
		p[1]+= v[1];
		p[2]+= v[2];

		t += deltat;
	}
	return 0;
}













