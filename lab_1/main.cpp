#include <iostream>
#include <cmath>

using namespace std;

double eval_func(double x)
{
	return sin(4*x + 1)/(2*x + 0.1);
}

double eval_integral(double a, double b, unsigned int strips)
{
	double step, integral = 0;
	
	for(step = (b - a)/strips; a < b; a += step)
	{
		integral +=  step * eval_func(a);
	}
	return integral;		
}

int main()
{
	double a, b, accuracy;

	cout << "Enter left endpoint: ";
	cin >> a;
	cout << "Enter right endpoint: ";
	cin >> b;
	cout << "Enter accuracy: ";
	cin >> accuracy;

	double i1, i2;
	
	unsigned int strips = 1;

	i2 = eval_integral(a, b, strips);

	do
	{
		i1 = i2;
		strips *= 2;
		i2 = eval_integral(a, b, strips);
	} while ( abs(i1 - i2) > accuracy);

	cout << "Integral = " << i2 << endl << "Strips = " << strips << endl;

	return 0;
}
