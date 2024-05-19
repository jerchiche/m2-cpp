#include "transformation.hpp"
#include "signauxvaries.hpp"
#include <fstream>

using namespace std;

// Fonctions de l'exercice 15
double sin4096(double x){return sin(M_PI*x / (double)4096);}
double delta0(unsigned x){return (x == 0) ? 1 : 0;}


int main()
{
	srand(time(NULL));
	rand();
	
	// Exercice 15
	cout << "Exercice 15:" << endl;
	Fourier F;
	SignalComplexe SC;
	ofstream Exo15D0("TestExo15D0.dat");
	ofstream Exo15Sin("TestExo15Sin.dat");
	
	SignalReelDeterministe SDetSin(4096, sin4096), SDetD0(4096, delta0);
	SC = SDetD0;
	F.DirectTransformInplace(SC);
	SC.ecriture(Exo15D0);
	SC = SDetSin;
	F.DirectTransformInplace(SC);
	SC.ecriture(Exo15Sin);	
	
	// MvtBrownien et PontBrownien
	cout << endl << "MvtBrownien et PontBrownien:" << endl;
	ofstream EcrireMB("TestMB.dat");
	ofstream EcrirePB("TestPB.dat");
	ofstream EcrirePBF("TestPBF.dat");
	
	MvtBrownien M(512,1);
	PontBrownien P(512, 10);
	SC = P;
	F.DirectTransformInplace(SC);
	
	M.ecriture(EcrireMB);
	P.ecriture(EcrirePB);
	SC.ecriture(EcrirePBF);
	return 0;
}





