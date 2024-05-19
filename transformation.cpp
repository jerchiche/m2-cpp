#include "transformation.hpp"


using namespace std;

/**************************************************************************************************

Fourier

**************************************************************************************************/

//	Calcul du n-ieme element de la trasformee de fourier de SC
complex<double> Fn(const SignalComplexe SC, unsigned int n)
{
	complex<double> i(0,1), result(0,0);
	unsigned int N = SC.lireN();
	for(int k=0; k<N; k++)
		result += SC[k] * exp((-2 * M_PI * k * n * i)/(double) N);
	return result;
}

//	Calcul du n-ieme element de la trasformee de fourier inverse de SC
complex<double> Fn_inv(const SignalComplexe SC, unsigned int n)
{
	complex<double> i(0,1), result(0,0);
	unsigned int N = SC.lireN();
	for(int k=0; k<N; k++)
		result += SC[k] * exp((2 * M_PI * k * n * i)/(double) N);
	return result /(double) N;
}

void Fourier::DirectTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Fourier : ";
	unsigned int N = Input.lireN();
	Output = SignalComplexe(N, 'f');
	for(int k=0; k<N; k++)
		Output[k] = Fn(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Fourier::DirectTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Fourier : ";
	int N = IOput.lireN();
	SignalComplexe tmp(N, 'f');
	for(int k=0; k<N; k++)
		tmp[k] = Fn(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Fourier::InverseTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Fourier vers Point : ";
	unsigned int N = Input.lireN();
	Output = SignalComplexe(N, 'p');
	for(int k=0; k<N; k++)
		Output[k] = Fn_inv(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Fourier::InverseTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Fourier vers Point : ";
	int N = IOput.lireN();
	SignalComplexe tmp(N, 'p');
	for(int k=0; k<N; k++)
		tmp[k] = Fn_inv(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

/**************************************************************************************************

FFT (Pas faite, copie de Fourier normale, avec les test de puissance de 2, et prepare quelques codes)

**************************************************************************************************/

complex<double> FFn(const SignalComplexe SC, unsigned int n)
{
	complex<double> i(0,1), result(0,0);
	unsigned int N = SC.lireN();
	for(int k=0; k<N; k++)
		result += SC[k] * exp((-2 * M_PI * k * n * i)/(double) N);
	return result;
}	// A faire

complex<double> FFn_inv(const SignalComplexe SC, unsigned int n)
{
	complex<double> i(0,1), result(0,0);
	unsigned int N = SC.lireN();
	for(int k=0; k<N; k++)
		result += SC[k] * exp((2 * M_PI * k * n * i)/(double) N);
	return result /(double) N;
}	// A faire

void FFT::DirectTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Fourier : ";
	unsigned int N = Input.lireN();
	if(puiss2(N)<0)
	{
		Fourier F;
		F.DirectTransform(Input, Output);
		return;
	}
	Output = SignalComplexe(N, 'f');
	for(int k=0; k<N; k++)
		Output[k] = FFn(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void FFT::DirectTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Fourier : ";
	int N = IOput.lireN();
	if(puiss2(N)<0)
	{
		Fourier F;
		F.DirectTransformInplace(IOput);
		return;
	}
	SignalComplexe tmp(N, 'f');
	for(int k=0; k<N; k++)
		tmp[k] = FFn(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void FFT::InverseTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Fourier vers Point : ";
	unsigned int N = Input.lireN();
	if(puiss2(N)<0)
	{
		Fourier F;
		F.InverseTransform(Input, Output);
		return;
	}
	Output = SignalComplexe(N, 'p');
	for(int k=0; k<N; k++)
		Output[k] = FFn_inv(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void FFT::InverseTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Fourier vers Point : ";
	int N = IOput.lireN();
	if(puiss2(N)<0)
	{
		Fourier F;
		F.InverseTransformInplace(IOput);
		return;
	}
	SignalComplexe tmp(N, 'p');
	for(int k=0; k<N; k++)
		tmp[k] = FFn_inv(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

/**************************************************************************************************

Haar (Pas faite non plus, juste prepare quelques codes)

**************************************************************************************************/

complex<double> Hn(const SignalComplexe SC, unsigned int n)
{
	complex<double> result(0,0);
	return result;
}	// A faire

complex<double> Hn_inv(const SignalComplexe SC, unsigned int n)
{
	complex<double> result(0,0);
	return result;
}	// A faire

int Psi(double x)
{
	if(x>=0 && x<1) return 1;
	if(x>=1 && x<2) return -1;
	else return 0;
}

void Haar::DirectTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Haar : ";
	unsigned int N = Input.lireN();
	Output = SignalComplexe(N, 'h');
	for(int k=0; k<N; k++)
		Output[k] = Hn(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Haar::DirectTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Haar : ";
	int N = IOput.lireN();
	SignalComplexe tmp(N, 'h');
	for(int k=0; k<N; k++)
		tmp[k] = Hn(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Haar::InverseTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Haar vers Point : ";
	unsigned int N = Input.lireN();
	Output = SignalComplexe(N, 'p');
	for(int k=0; k<N; k++)
		Output[k] = Hn_inv(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Haar::InverseTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Haar vers Point : ";
	int N = IOput.lireN();
	SignalComplexe tmp(N, 'p');
	for(int k=0; k<N; k++)
		tmp[k] = Hn_inv(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

/**************************************************************************************************

Binomiale
J'ai remarqu¨¦ que les chiffres etaient vite trop grands a cause du Cnk (a partir d'un signal d'une 20e de valeurs).
J'ai donc essaye avec des long et unsigned long sans meilleur r¨¦sultat.

**************************************************************************************************/

complex<double> Bn(const SignalComplexe SC, unsigned int n)
{
	complex<double> result(0,0);
	unsigned long Cnk = 1;
	int mUNpK = 1;
	for(int k=0; k<=n; k++)
	{
		result += Cnk * (double)mUNpK * SC[k];
		mUNpK *= -1;
		Cnk = (n == k) ? 1 : (Cnk * (n-k)/(k+1));
	}
	return result;
}

int puiss2(unsigned int n, int p)
{
	if(n==0) return -1;
	if(n==1) return 0;
	else return ((n&1)==0) ? 1+puiss2(n>>1, ++p) : -p-1;
}

void Binomiale::DirectTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Binomiale : ";
	unsigned int N = Input.lireN();
	Output = SignalComplexe(N, 'b');
	for(int k=0; k<N; k++)
		Output[k] = Bn(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Binomiale::DirectTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Point vers Binomiale : ";
	int N = IOput.lireN();
	SignalComplexe tmp(N, 'b');
	for(int k=0; k<N; k++)
		{tmp[k] = Bn(IOput, k);}
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Binomiale::InverseTransform(const SignalComplexe & Input, SignalComplexe & Output)
{
	time_t tbegin = time(NULL);
	cout << "Binomiale vers Point : ";
	unsigned int N = Input.lireN();
	Output = SignalComplexe(N, 'p');
	for(int k=0; k<N; k++)
		Output[k] = Bn(Input, k);
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

void Binomiale::InverseTransformInplace(SignalComplexe & IOput)
{
	time_t tbegin = time(NULL);
	cout << "Binomiale vers Point : ";
	int N = IOput.lireN();
	SignalComplexe tmp(N, 'p');
	for(int k=0; k<N; k++)
		tmp[k] = Bn(IOput, k);
	IOput = tmp;
	cout << difftime(time(NULL), tbegin) << " secondes" << endl;
}

/**************************************************************************************************

Exercice 19

**************************************************************************************************/

unsigned int conjugate(unsigned poweroftwo, unsigned int n)
{
	int p = puiss2(poweroftwo);
	if(p<0) {cout << "poweroftwo n'est pas une puissance de 2" << endl; return 0;}
	if(n>poweroftwo) {cout << "n est plus grand que poweroftwo" << endl; return 0;}
	
	if(n==0) {return 0;}
	if(n<(poweroftwo>>1))
		{return conjugate(poweroftwo>>1, n)<<1;}
	return 1+(conjugate(poweroftwo>>1, n-(poweroftwo>>1))<<1);
}

/**************************************************************************************************

Interface

**************************************************************************************************/

void BackToP(SignalComplexe & SC)
{
	char c = SC.lirecod();
	if(c == 'p') return;
	if(c == 'f')
	{
		FFT T;	// Fonctionne car c est la meme que Fourier normale, mais j ai prefere mettre ca au cas ou je faisais la FFT
		T.InverseTransformInplace(SC);
		return;
	}
	if(c == 'b')
	{
		Binomiale T;
		T.InverseTransformInplace(SC);
		return;
	}
	if(c == 'h')
	{
		//Haar T;
		//T.InverseTransformInplace(SC);
		//return;
	}
	cout << "Encodage non pris en charge!" << endl;
}

void PtoC(SignalComplexe & SC, char c)
{
	if(c == 'p') return;
	if(c == 'f')
	{
		FFT T;	// Comme au dessus
		T.DirectTransformInplace(SC);
		return;
	}
	if(c == 'b')
	{
		Binomiale T;
		T.DirectTransformInplace(SC);
		return;
	}
	if(c == 'h')
	{
		//Haar T;
		//T.DirectTransformInplace(SC);
		//return;
	}
	cout << "Encodage non pris en charge!" << endl;
}










