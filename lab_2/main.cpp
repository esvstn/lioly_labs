#include <iostream>

using namespace std;

int fill_array(int * const p, int len)
{

	cout << "Enter array elements: ";
	for (int i=0; i < len; i++)
	{
		cin >> p[i];
	}

	return len;
}

void shift_array(int * const p, int len, int shift)
{
	while (shift--)
	{
		int temp = p[len - 1];
		int i = len - 1;
		while(i--)
		{
			p[i+1] = p[i];
		}
		p[0] = temp; 
	}
}

void print_array(int * const p, int len)
{
	for(int i=0; i < len; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

int main()
{
	int *p;
	int len;
	int shift;

	cout << "Enter array length: ";
	cin >> len;
	p = new int [len];	

	len = fill_array(p, len);

	cout << "Enter shifting value: ";
	cin >> shift;
	
	shift_array(p, len, shift);

	print_array(p, len);
	delete [] p;
	return 0;
}
