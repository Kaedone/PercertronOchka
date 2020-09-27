#include <iostream>
#include <vector>

#include "Perceptron.h"


int main()
{
	vector<Perceptron> p(500, Perceptron(2, 0.31));
	double x;
	int t = 0;
	int f = 0;
	for (double i = 0; i < 251; i++) {
		for (double j = 0; j < 251; j++) {
			x = i + j;
			cout << p[i].process({ i, j }) << endl;
			p[i].changeWeights(x);
			if (p[i].process({ i, j }) == x) {
				t++;
			}
			else {
				f++;
			}

		}
	}

	cout << "Right " << t << endl;
	cout << "Left " << f << endl;

	return 0;
}
