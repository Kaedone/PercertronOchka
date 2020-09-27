#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <cstdlib>

using namespace std;

class Perceptron
{
public:
	Perceptron(int aDimension, double aLearningRate = 0.3);

	double	process(vector<double> aInputs);
	double	getOutput() const;
	void	changeWeights(double aAnswer);

	const vector<double>& getPresentation() const;

private:
	double mSumm;
	double mOutput;
	double mLearningRate;

	double mOffset;
	vector<double> mWeights;

	vector<double> mInputs;

	double activationFunction(double aS) const;
	double dActivationFunction(double aS) const;
};

#endif 
