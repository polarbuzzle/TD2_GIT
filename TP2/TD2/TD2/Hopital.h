/**********************************************
* Titre: Travail pratique #1 - Hopital.h
* Date: 8 Fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
* Description: Definition de la classe Hopital
*********************************************/
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
	string accederNom() const;
	//Acceseur de lattribut Personnel
	Personnel& accederPersonnel() const;
	//Modificateur permettant de modifier le nom 
	void modifierNom(string nom);
	//Modificateur permettant de modifier le vecteur personnel
	void modifierPersonnel(Personnel* nouveau);

	friend ostream& operator<<(ostream& out, const Hopital& hopital);

private:
	//Attributs privees 
	string nom_; 
	Personnel* personnel_; 
};
//Surcharge d'operateur pour affichage 
#endif
