#include <ctime>
#include "signal.hpp"


using namespace std;

/**************************************************************************************************

Transformation

**************************************************************************************************/

class Transformation
{
public:
	virtual void DirectTransform(const SignalComplexe & Input, SignalComplexe & Output) = 0;
	virtual void DirectTransformInplace(SignalComplexe & IOput) = 0;
	virtual void InverseTransform(const SignalComplexe & Input, SignalComplexe & Output) = 0;
	virtual void InverseTransformInplace(SignalComplexe & IOput) = 0;
};

/**************************************************************************************************

Fourier (herite de Transformation)

**************************************************************************************************/

//	Calcul du n-ieme element de la trasformee de fourier de SC
complex<double> Fn(const SignalComplexe, unsigned int);
//	Calcul du n-ieme element de la trasformee de fourier inverse de SC
complex<double> Fn_inv(const SignalComplexe, unsigned int);

class Fourier : public Transformation
{
public:
	void DirectTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void DirectTransformInplace(SignalComplexe & IOput);
	void InverseTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void InverseTransformInplace(SignalComplexe & IOput);
};

/**************************************************************************************************

FFT (herite de Transformation)
(Pas faite, copie de Fourier normale, j ai juste prepare quelques codes, si j arrivais a avancer)

**************************************************************************************************/

complex<double> FFn(const SignalComplexe, unsigned int);
complex<double> FFn_inv(const SignalComplexe, unsigned int);

class FFT : public Transformation
{
public:
	void DirectTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void DirectTransformInplace(SignalComplexe & IOput);
	void InverseTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void InverseTransformInplace(SignalComplexe & IOput);
};

/**************************************************************************************************

Haar (herite de Transformation)
(Pas faite non plus)

**************************************************************************************************/

complex<double> Hn(const SignalComplexe, unsigned int);
complex<double> Hn_inv(const SignalComplexe, unsigned int);

int Psi(double x);

class Haar : public Transformation
{
public:
	void DirectTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void DirectTransformInplace(SignalComplexe & IOput);
	void InverseTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void InverseTransformInplace(SignalComplexe & IOput);
};

/**************************************************************************************************

Binomiale (herite de Transformation)
J'ai remarque que les chiffres etaient vite trop grands a cause du Cnk (a partir d'un signal d'une 20e de valeurs).
J'ai donc essaye avec des long et unsigned long sans meilleur resultat.

**************************************************************************************************/

//Renvoie -1 si n n'est pas une puissance de 2, et p si n=2^p
int puiss2(unsigned int, int p=0);

//	Calcul du n-ieme element de la trasformee de fourier de SC
complex<double> Bn(const SignalComplexe, unsigned int);

class Binomiale : public Transformation
{
public:
	void DirectTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void DirectTransformInplace(SignalComplexe & IOput);
	void InverseTransform(const SignalComplexe & Input, SignalComplexe & Output);
	void InverseTransformInplace(SignalComplexe & IOput);
};

/**************************************************************************************************

Exercice 19

**************************************************************************************************/

unsigned int conjugate(unsigned, unsigned int);

/**************************************************************************************************

Interface

**************************************************************************************************/

void BackToP(SignalComplexe &);

void PtoC(SignalComplexe &, char);




