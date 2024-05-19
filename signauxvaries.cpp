#include "signauxvaries.hpp"

using namespace std;


/**************************************************************************************************

MvtBrownien herite de SignalReelRandom
protected:
	unsigned int N;
	vector<double> t;
	char codage;
private:
	double delta;

**************************************************************************************************/

double Gauss(double m, double sigma)
{
	static bool test = true;
	static double u;
	static double theta;
	double g;
	if(test)
	{
		u = log(rand() / (double) RAND_MAX);
		theta = 2 * M_PI *rand() / (double) RAND_MAX;
		g = sqrt(-2 * u) * cos(theta);
		test = false;
	}
	else
	{
		g = sqrt(-2 * u) * sin(theta);
		test = true;
	}
	return m + sigma * g;
}

MvtBrownien::MvtBrownien(int n, double delta)
	: SignalReelRandom(n), delta(delta)
{
	t[0] = 0;
	double sigma = sqrt(delta);
	for(int i=1; i<n; i++)
		t[i] = t[i-1] + Gauss(0, sigma);
}

void MvtBrownien::generate()
{
	t[0]=0;
	double sigma = sqrt(delta);
	for(int i=1; i<N; i++)
		t[i] = t[i-1] + Gauss(0, sigma);
}

/**************************************************************************************************

PonttBrownien herite de SignalReelRandom
protected:
	unsigned int N;
	vector<double> t;
	char codage;
private:
	double longueur;

**************************************************************************************************/

PontBrownien::PontBrownien(int n, double l)
	: SignalReelRandom(n), longueur(l)
{
	vector<double> MB(n);
	double delta = l/(double)(n-1);
	double sigma = sqrt(delta);
	MB[0] = 0;
	t[0] = 0;
	for(int i=1; i<n; i++)
		MB[i] = MB[i-1] + Gauss(0, sigma);
	for(int i=1; i<n; i++)
		t[i] = l * MB[i] - i * delta * MB[n-1];
}

void PontBrownien::generate()
{
	vector<double> MB(N);
	double delta = longueur/(double)(N-1);
	double sigma = sqrt(delta);
	MB[0] = 0;
	t[0] = 0;
	for(int i=1; i<N; i++)
		MB[i] = MB[i-1] + Gauss(0, sigma);
	for(int i=1; i<N; i++)
		t[i] = longueur * MB[i] - i * delta * MB[N-1];
}



