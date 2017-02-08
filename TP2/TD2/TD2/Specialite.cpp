/**************************************************
* Fichier : Specialite.cpp
* Auteur(s) : FERRON Samuel, FONTAINE Jean-Frederic
* Date: 08 Fevrier 2017
**************************************************/
#include "Specialite.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

using namespace std;

/*********************************************
*Fonctions:		Constructeur par default
*Descriptions:	Construit l'objet Specialite aves ses valeurs par defauts
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Specialite::Specialite() {
	domaine_ = "Inconnu";
	niveau_ = 0;
}

/*********************************************
*Fonctions:		Constructeur par parametre
*Descriptions:	Construit l'objet Specialite aves les valeurs entrees en parametres
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Specialite::Specialite(const std::string & domaine, unsigned int niveau): domaine_(domaine), niveau_(niveau)
{
}

/*********************************************
*Fonctions:		obtenir domaine
*Descriptions:	retourne le nom du domaine de la specialite
*Parametre:		Aucun
*Retour:		-(string)domaine_ : le nom de domaine de la specialite
*********************************************/
std::string Specialite::obtenirDomaine() const
{
	return domaine_;
}

/*********************************************
*Fonctions:		obtenir niveau
*Descriptions:	retourne le niveau de la specialite
*Parametre:		Aucun
*Retour:		-(unsigned int)niveau_ : le niveau de la specialite
*********************************************/
unsigned int Specialite::obtenirNiveau() const
{
	return niveau_;
}

/*********************************************
*Fonctions:		Modifier domaine
*Descriptions:	modifie le nom du domaine de la specialite
*Parametre:		-(const string&)domaine : le nouveau nom de domaine
*Retour:		Aucun
*********************************************/
void Specialite::modifierDomaine(const std::string& domaine)
{
	domaine_ = domaine;
}

/*********************************************
*Fonctions:		Modifier niveau
*Descriptions:	modifie le niveau de la specialite
*Parametre:		-(unsigned int)niveau : le nouveau niveau
*Retour:		Aucun
*********************************************/
void Specialite::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

/*********************************************
*Fonctions:		Operateur <<
*Descriptions:	Permet d'afficher la specialite
*Parametre:		-(ostream&)o : flux dans lequel on ajoute les messages
*Parametre:		-(const Specialite&)specialite : objet de type specialite a droite de l'operateur
*Retour:		-(ostream&)o : flux dans lequel on a ajoute les messages
*********************************************/
std::ostream& operator<<(std::ostream& o, const Specialite& specialite)
{
	o << " | " << specialite.obtenirDomaine() << AFFICHER_ESPACE(espace_domaine - specialite.obtenirDomaine().size());
	o << " | " << AFFICHER_ESPACE(espace_niveau - std::to_string(specialite.obtenirNiveau()).size()) << specialite.obtenirNiveau();
	o << AFFICHER_ESPACE(espace_niveau) << " | ";
	return o;
}
