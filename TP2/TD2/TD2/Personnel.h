/**********************************************
* Titre: Travail pratique #1 - Personnel.h
* Date: 8 Fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
* Description: Definition de la classe Personnel
*********************************************/
#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <vector>
#include "Medecin.h"
#include "Infirmier.h"

using namespace std;

class Personnel
{
public:
	// Constructeur par defaut
	Personnel();
	// Destructeur
	~Personnel();
	// Methodes publiques
	bool ajouterMedecin(Medecin* medecin);
	bool retirerMedecin(const std::string& nom);
	bool ajouterInfirmier(Infirmier* infirmier);
	bool retirerInfirmier(const std::string& nom);
	//surcharge d'operateurs += et -=
	Personnel& operator+=(Medecin* medecin);
	Personnel& operator-=(Medecin* medecin);
	Personnel& operator+=(Infirmier* infirmier);
	Personnel& operator-=(Infirmier* infirmier);
	//surcharge d'operateur <<
	friend std::ostream& operator<<(std::ostream& o, const Personnel& personnel);
private:
	//Attributs
	vector<Medecin*> medecins_;
	vector<Infirmier*> infirmiers_;
};


#endif