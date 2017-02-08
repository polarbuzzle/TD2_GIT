/**********************************************
* Titre: Travail pratique #1 - Medecin.cpp
* Date: 10 janvier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implémentation de la classe Hopital 
*********************************************/
#include "Hopital.h"
#include <string>
#include <iostream>


/*********************************************
*Fonctions:		Hopital()
*Descriptions:	Construit l'objet avec les parametres correspondant
*Parametre:		-(string)nom	: Nom de lhopital 
				-(Personnel)personnel	: Vecteur du personnel associe a cet hopital. 
*Retour:			Aucun
*********************************************/
Hopital::Hopital(string nom, Personnel* personnel) : nom_(nom), personnel_(personnel) {

}
/*********************************************
*Fonctions:		~Hopital()
*Descriptions:	Destructeur de lobjet hopital 
*Parametre:		Aucun 
*Retour:		Aucun
*********************************************/
Hopital::~Hopital() {

}

/*********************************************
*Fonctions:		accederNom()
*Descriptions:	Acceseur du nom de lhopital 
*Parametre:		Aucun
*Retour:		-(string)nom_	: Nom de l'hopital 
*********************************************/
string Hopital::accederNom() const {
	return nom_; 
}

/*********************************************
*Fonctions:		accederPersonnel()
*Descriptions:	Acceseur du vecteur de Personnel 
*Parametre:		Aucun
*Retour:		-(Personnel)personnel_	: vecteur du personnel associe a lhopitla 
*********************************************/
Personnel& Hopital::accederPersonnel() const{
	return *personnel_;
}
/*********************************************
*Fonctions:		modifierNom()
*Descriptions:	Permet de modifier le nom 
*Parametre:		-(string)nom	: Nouveau nom qu'on veut donner
*Retour:		-Aucun 
*********************************************/
void Hopital::modifierNom(string nom) {
	nom_ = nom;
}
/*********************************************
*Fonctions:		modifierPersonnel()
*Descriptions:	Permet de modifier le vecteur de personnel 
*Parametre:		-(Personnel*)personnel	: nouveau vecteur personnel
*Retour:		-Aucun
*********************************************/
void Hopital::modifierPersonnel(Personnel* nouveau) {
	personnel_ = nouveau; 
}
/*********************************************
*Fonctions:		operateur <<
*Descriptions:	Permet d'afficher le personnel de l'hopital
*Parametre:		-(Hopital&)hopital	: L'hopital que nous voulons afficher
*Parametre:		-(ostream&)out		: le flux a modiffier
*Retour:		-(ostream&)out		: le flux de retour
*********************************************/
ostream& operator<<(ostream& out, const Hopital& hopital) {
	out << hopital.accederPersonnel();
	return out;
}
