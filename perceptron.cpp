
#include <iostream>
#include <vector>


using namespace std;

class perceptron {
public:

    double mSumm;
    double mOutput{};
    double mLearningRate;

    double mOffset;
    std::vector<double> mWeights;

    vector<double> inputs;

    perceptron(int aDimension, double aLearningRate) :
            mSumm				(0),
            mWeights			(aDimension),
            mLearningRate		(aLearningRate)
    {
        for (auto& i : mWeights)
        {
            i = (rand() % 1000 - 500) / 1000.;
        }
        mOffset = (rand() % 1000 - 500) / 1000.;
    }

    double
    process(const vector<double> &aInp) {
        inputs = aInp;

        mSumm = 0;
        for (int i = 0; i < mWeights.size(); ++i) {
            mSumm += mWeights[i] * (inputs)[i];
        }
        mSumm += mOffset;

        mOutput = activationFunction(mSumm);
        return mOutput;
    }

    double
    getOutput() const {

        return mOutput;

    }

    void
    changeWeights(double aAnswer) {
        double error = aAnswer - mOutput;
        double teta = error * dActivationFunction(mSumm);

        for (int i = 0; i < mWeights.size(); ++i) {
            mWeights[i] += mLearningRate * teta * (inputs)[i];
        }
        mOffset += mLearningRate * teta;
    }

    const std::vector<double> &
    getPresentation() const {
        return mWeights;
    }

    double
    activationFunction(double aS) const
    {
        return 1. / (1. + exp(-aS));
    }
//--------------------------------------------------------------------------------
    double
    dActivationFunction(double aS) const
    {
        return activationFunction(aS) * (1. - activationFunction(aS));
    }

};

int main()
{
    vector<vector<double>> a = { { 0., 0. }, {0., 1.}, {1.,0.}, {1.,1.} };


    perceptron p(2,0.3);
    while (true) {
        for (int i = 0; i < a.size(); i++) {

            cout << p.process(a[i])  << "  ";

            p.changeWeights(a[i][0] * a[i][1]);


        }
        cout << endl;
    };
}