#include "Specialite.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

using namespace std

/*********************************************
*Fonctions:		Constructeur par default
*Descriptions:	Construit l'objet Specialite aves ses valeurs par defauts
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Specialite::Specialite()
{
	domaine_ = "Aucun";
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

std::ostream& operator<<(std::ostream& o, const Specialite& specialite)
{

}

//void Specialite::information(const Specialite& specialite) const // A MODIFIER... (si necessaire)
//{
//	cout << " | " << specialite.obtenirDomaine() << AFFICHER_ESPACE(espace_domaine - specialite.domaine_.size());
//	cout << " | " << AFFICHER_ESPACE(espace_niveau - std::to_string(specialite.niveau_).size()) << specialite.niveau_;
//
//	cout << AFFICHER_ESPACE(espace_niveau) << " | ";
//}