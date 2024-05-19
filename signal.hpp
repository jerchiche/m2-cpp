#include <iostream>
#include <vector>
#include <complex>

#ifndef SIGNAUX
#define SIGNAUX

using namespace std;


/**************************************************************************************************

SignalReel

**************************************************************************************************/

class SignalReel
{
protected:
	unsigned int N;
	vector<double> t;
	char codage;
	
public:
	// Constructeurs
	SignalReel(vector<double> vect=vector<double>(), char c='p')
		: N(vect.size()), t(vect), codage(c) {}
	SignalReel(int n, char c='p')
		: N(n), t(vector<double>(n)), codage(c) {}
	SignalReel(SignalReel const & S);
	
	// Destructeur
	~SignalReel() {}
	
	// Lecture et Ecriture
	unsigned int lecture(istream & i);
	void ecriture(ostream & o) const;
	
	// Accesseurs et Mutateurs
	unsigned int lireN() const
		{return N;}
	char lirecod() const
		{return codage;}
	double & operator[](unsigned int k)
		{return t[k];}
	double operator[](unsigned int k) const
		{return t[k];}
};

/**************************************************************************************************

SignalComplexe

**************************************************************************************************/

class SignalComplexe
{
protected:
	unsigned int N;
	vector<complex<double> > t;
	char codage;
	
public:
	// Constructeurs
	SignalComplexe(vector<complex<double> > vect = vector<complex<double> >(), char c='p')
		: N(vect.size()), t(vect), codage(c) {}
	SignalComplexe(int n, char c='p')
		: N(n), t(vector<complex<double> >(n)), codage(c) {}
	SignalComplexe(SignalComplexe const & S);
	SignalComplexe(const SignalReel &);
	
	// Destructeur
	~SignalComplexe() {}
	
	// Lecture et Ecriture
	unsigned int lecture(std::istream & i);
	void ecriture(std::ostream & o) const;
	
	// Accesseurs et Mutateurs
	unsigned int lireN() const
		{return N;}
	char lirecod() const
		{return codage;}
	complex<double> & operator[](unsigned int k)
		{return t[k];}
	complex<double> operator[](unsigned int k) const
		{return t[k];}
};


#endif



	