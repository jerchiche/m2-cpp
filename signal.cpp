#include "signal.hpp"

using namespace std;


/**************************************************************************************************

SignalReel
protected:
	unsigned int N;
	vector<double> t;
	char codage;

**************************************************************************************************/

SignalReel::SignalReel(SignalReel const & S)
{
	N = S.N;
	t = S.t;
	codage = S.codage;
}

unsigned int SignalReel::lecture(istream & i)
{
	cout << "Lecture" << endl;
	i >> codage;
	if(codage != '#')
		{cout << "Fichier entre non valide. " << endl; return 0;}
	i >> codage >> N;
	t.resize(N);
	for(int k=0; k<N; k++)
		i >> t[k];
	return N;
}

void SignalReel::ecriture(ostream & o) const
{
	cout << "Ecriture" << endl;
	o << "# " << codage << ' ' << N << endl;
	for(int k=0; k<N; k++)
		o << t[k] << endl;
}

/**************************************************************************************************

SignalComplexe
protected:
	unsigned int N;
	vector<complex<double> > t;
	char codage;

**************************************************************************************************/


SignalComplexe::SignalComplexe(SignalComplexe const & S)
{
	N = S.N;
	codage = S.codage;
	t = S.t;
}

SignalComplexe::SignalComplexe(SignalReel const & S)
{
	N = S.lireN();
	codage = S.lirecod();
	t.resize(N);
	for(int k=0; k<N; k++)
		t[k] = S[k];
}

unsigned int SignalComplexe::lecture(istream & i)
{
	cout << "Lecture" << endl;
	i >> codage;
	if(codage != '#')
		{cout << "Fichier entre non valide. " << endl; return 0;}
	i >> codage >> N;
	t.resize(N);
	double a, b;
	for(int k=0; k<N; k++)
	{
		i >> a >> b;
		t[k] = complex<double>(a,b);
	}
	return N;
}

void SignalComplexe::ecriture(ostream & o) const
{
	cout << "Ecriture" << endl;
	o << "#  " << codage << ' ' << N << endl;
	for(int k=0; k<N; k++)
		o << t[k].real() << "  " << t[k].imag() << endl;
}






