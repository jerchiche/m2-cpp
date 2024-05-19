#include "signal.hpp"

using namespace std;


/**************************************************************************************************

SignalReelDeterministe herite de SignalReel
protected:
	unsigned int N;
	vector<double> t;
	char codage;

**************************************************************************************************/

class SignalReelDeterministe : public SignalReel
{
public:
	SignalReelDeterministe(int n, double (*f)(double))
		: SignalReel(n) {for(int i=0; i<n; i++) t[i] = f(i);}
	SignalReelDeterministe(int n, double (*f)(unsigned))
		: SignalReel(n) {for(int i=0; i<n; i++) t[i] = f(i);}
};

/**************************************************************************************************

SignalReelRandom herite de SignalReel
protected:
	unsigned int N;
	vector<double> t;
	char codage;

**************************************************************************************************/

class SignalReelRandom : public SignalReel
{
public:
	SignalReelRandom(int n)
		: SignalReel(n) {}
	virtual void generate(void) = 0;
};

/**************************************************************************************************

MvtBrownien herite de SignalReelRandom
protected:
	unsigned int N;
	vector<double> t;
	char codage;

**************************************************************************************************/

double Gauss(double m=0, double sigma=1); // Simule une gaussienne N(m; sigma^2)

class MvtBrownien : public SignalReelRandom
{
private:
	double delta;
public:
	MvtBrownien(int n=1, double delta=1);
	void generate();
};

/**************************************************************************************************

PontBrownien herite de SignalReelRandom
protected:
	unsigned int N;
	vector<double> t;
	char codage;

**************************************************************************************************/

class PontBrownien : public SignalReelRandom
{
private:
	double longueur;
public:
	PontBrownien(int n=1, double l=1);
	void generate();
};

/**************************************************************************************************

SignalComplexeDeterministeherite de SignalComplexe
protected:
	unsigned int N;
	vector<complex<double> > t;
	char codage;

**************************************************************************************************/

class SignalComplexeDeterministe : public SignalComplexe
{
public:
	SignalComplexeDeterministe(int n, double (*f)(double))
		: SignalComplexe(n) {for(int i=0; i<n; i++) t[i] = f(i);}
	SignalComplexeDeterministe(int n, double (*f)(unsigned int))
		: SignalComplexe(n) {for(int i=0; i<n; i++) t[i] = f(i);}
};

