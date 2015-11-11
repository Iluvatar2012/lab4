#include <iostream>
#include <cmath>

using namespace std;


void print(double* const p, const int N, const double dx, const double xmin) {

	// iterate over all entries and output to user
	for(int i=0; i<N; i++)
		cout << i*dx + xmin << "\t" << p[i] << endl;
}


void fill (double* const p, const int N, const double x_min, const double dx) {

	double x;

	// iterate over all N entries and iterate a gaussian bell
	for (int i=0; i<N; i++) {
		x = x_min + i*dx;
		p[i] = exp(-x*x);
	}
} 


void derive (double* const p, const int N, const double dx) {

	// basic variables
	double p_i;
	double p_2i;

	// initialize first value and value for temporary storage
	p[0] = 0;
	p_2i = p[0];

	// iterate over all values and calculate the derivative to second order complexity
	for (int i = 1; i<(N-1); i++) {
		p_i 	= p[i];
		p[i] 	= (p[i+1] - p_2i)/(2*dx);
		p_2i 	= p_i;
	}

	// set the last value to zero
	p[N-1] = 0;
}  


int main(){
	const int N = 256;
	double p[N];
	const double x_max = 15;
	const double x_min = -15;
	const double dx = (x_max-x_min)/(N-1);

	// call to function which fills array p here
	fill(p, N, x_min, dx);

	// call to functio which calculates the derivative
	derive(p, N, dx);

	// print to user
	print(p,N,dx,x_min);

	// return to caller
	return 0;
}
