#ifndef HOPITAL_H
#define HOPITAL_H
#include "Personnel.h"
#include <string>
#include <iostream>

using namespace std; 
class Hopital
{
public: 
	// Constructeur par parametres
	Hopital(string nom, Personnel* personnel);
	//Destructeur
	~Hopital();
	//Acceseur de lattribut nom
	string accederNom();
	//Acceseur de lattribut Personnel
	Personnel accederPersonnel();
	//Modificateur permettant de modifier le nom 
	void modifierNom(string nom);
	//Modificateur permettant de modifier le vecteur personnel
	void modifierPersonnel(Personnel* nouveau);
private:
	//Attributs privees 
	string nom_; 
	Personnel* personnel_; 
};
//Surcharge d'operateur pour affichage 
ostream& operator<<(ostream& out, const Hopital& hopital);
#endif
