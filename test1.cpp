#include "transformation.hpp"
#include <fstream>


int main()
{
	//	Declaration des variables
	string Entree, Sortie, Encore;
	char cVoulu, RouC;
	SignalReel R1;
	SignalComplexe C1;
	bool BonCodage = false;
	ifstream Lire;
	ofstream Ecrire;
	
	//	Depart de l'interface
	Recommence:
    
	//	Demande le nom du fichier a lire
	cout << endl << "Entrez le nom du fichier a lire : ";
	cin >> Entree;
	Lire.open(Entree);
	
	//	Demande le type de signal du fichier (et redemande tant qu'on ne rentre pas r ou c)
	cout << endl << "Est-ce un signal reel (= r) ou complexe (= c)? : ";
	do
	{
		cin >> RouC;
		if(RouC=='r')
		{
			R1.lecture(Lire);
			C1=R1;
			BonCodage = true;
		}
		if(RouC=='c')
		{
			C1.lecture(Lire);
			BonCodage = true;
		}
		if(RouC!='c' && RouC!='r')
			{cout << "Il faut entrer soit r , soit c : " << endl;}
	} while(!BonCodage);
	BonCodage = false;
	
	//	Verifie que le fichier est correct, sinon on demande si on recommence
	if(C1.lireN() == 0) {cout << "Mauvais fichier!" << endl; goto more;}
	
	//	Demande le type de codage voulu (et redemande tant qu'on ne rentre pas un codage pris en charge)
	cout << endl << "Entrez le type de codage voulu: f pour Fourier, b pour Binomial, p pour Point : ";
	do
	{
		cin >> cVoulu;
		if((cVoulu!='p') && (cVoulu!='b') && (cVoulu!='f') /* && (cVoulu!='h') */)
			cout << "Codage non pris en charge, recommencez : " << endl;
		else
			BonCodage = true;
	} while(!BonCodage);
	BonCodage = false;
	
	//	Demande le nom du fichier sur lequel ecrire
	cout << endl << "Entrez le nom du fichier de sortie : ";
	cin >> Sortie;
	cout << endl;
	Ecrire.open(Sortie);
	
	//	Transformations
	if(C1.lirecod() == cVoulu) {cout << "Rien a faire, deja le bon codage! " << endl;}
	else
		{BackToP(C1); PtoC(C1, cVoulu);}
	
	//	Ecriture
	C1.ecriture(Ecrire);
	
	//	Fermeture des fichiers
	Lire.close();
	Ecrire.close();
	
	more:
	//	On recommence?
	cout << endl << "Voulez vous continuer? (oui = continuer, autre chose = arreter)" << endl;
	cin >> Encore;
	
	if(Encore == "oui") goto Recommence;
	
	return 0;
}





