/**********************************************
* Titre: Travail pratique #1 - Medecin.cpp
* Date: 10 janvier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implémentation de la classe Medecin
*********************************************/
#ifndef MEDECIN_H
#define MEDECIN_H
#include <iostream>
#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:
	// Constructeurs par parametre
	Medecin(const Medecin& copie); // A MODIFIER... (si necessaire)
	Medecin(const string& nom, int horaires, Specialite* specialite); // A MODIFIER... (si necessaire)
	// Destructeur
	~Medecin(); // A MODIFIER... (si necessaire)
	
	// Methodes d'acces
	string obtenirNom() const;
	int obtenirHoraires() const;
	Specialite obtenirSpecialite() const;
	
	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierHoraires(int horaires);
	void modifierSpecialite(Specialite* specialite);

	//surcharge d'opérateur 
	Medecin& operator=(const Medecin& gauche); 
	friend bool operator==(string nom, const Medecin& medecin ) ;
	bool operator==(const string& nom2) const;
	
	
	//void information() const; // A MODIFIER... (si necessaire)
private:
	// Variables privees
	string nom_;
	int horaires_;
	Specialite* specialite_;
	
};
//Surcharge doperateur 
ostream& operator<<(ostream& o, const Medecin& medecin);
bool operator==(const Medecin& medecin1, const Medecin& medecin2);

#endif