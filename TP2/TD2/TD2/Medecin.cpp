/**********************************************
* Titre: Travail pratique #1 - Medecin.cpp
* Date: 10 janvier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Implémentation de la classe Medecin
*********************************************/
#include "Medecin.h"
#include <iostream>
#include <iomanip>
#include "Const.h"
/*********************************************
*Fonctions:		Constructeur par default
*Descriptions:	Construit l'objet Medecin aves les paramètres entrés
*Parametre:		-(string&)nom	: nom du medecin (IN) 
				-(int)horaire	: nombre d'heures associé au medecin (IN)
				-(Specialite*)	: specialité du medecin 
*Retour:			Aucun
*********************************************/
Medecin::Medecin(const string& nom, int horaires, Specialite* specialite): nom_(nom), horaires_(horaires), specialite_(specialite){}

/*********************************************
*Fonctions:		Constructeur par copie
*Descriptions:	Construit l'objet Medecin par copie (deep) d'un autre medecin. 
*Parametre:		-(Medecin&) copie	: Medecin duquel on copie (deep) les informations. 
*Retour:			Aucun
*********************************************/
Medecin::Medecin(const Medecin& copie) {
	nom_ = copie.nom_;
	horaires_ = copie.horaires_;
	specialite_ = new Specialite; 
	*specialite_ = *copie.specialite_;
}
/*********************************************
*Fonctions:		Destructeur 
*Descriptions:	Detruit l'objet medecin 
*Parametre:			Aucun
*Retour:			Aucun
*********************************************/
Medecin::~Medecin() // A MODIFIER... (si necessaire)
{
}
/*********************************************
*Fonctions:			obtenirNom()		
*Descriptions:		Permet d'avoir accès au nom du Medecin 
*Parametre:			Aucun
*Retour:			(string)nom_	: nom du medecin
*********************************************/
string Medecin::obtenirNom() const
{
	return nom_;
}
/*********************************************
*Fonctions:			obtenirHoraires()
*Descriptions:		Permet d'avoir accès aux heures du Medecin
*Parametre:			Aucun
*Retour:			-(int)horaire_: nombre d'heure du medecin 
*********************************************/
int Medecin::obtenirHoraires() const
{
	return horaires_;
}
/*********************************************
*Fonctions:			obtenirSpecialite()
*Descriptions:		Permet d'avoir accès a la specialité du medecin
*Parametre:			Aucun
*Retour:			-(*specilite_)	: Pointeur déréférencé indiquant la specialité du medecin.
*********************************************/
Specialite Medecin::obtenirSpecialite() const
{
	return *specialite_;
}
/*********************************************
*Fonctions:			modifierNom()
*Descriptions:		Permet de modifier le nom d'un medecin 
*Parametre:			-(string&)	: Addresse de la string avec le nouveau nom. 
*Retour:			Aucun
*********************************************/
void Medecin::modifierNom(const string& nom)
{
	nom_ = nom;
}
/*********************************************
*Fonctions:			modifierHoraires()
*Descriptions:		Permet de modifier le nombe d'heure du medecin 
*Parametre:			-(int)horaire	: Nombre d'heure du medecin 
*Retour:			Aucun
*********************************************/
void Medecin::modifierHoraires(int horaires)
{
	horaires_ = horaires;
}
/*********************************************
*Fonctions:			modifierSpecialite()
*Descriptions:		Permet de modifier la specialite d'un medecin 
*Parametre:			-(Specialite*)specialite	: nouvelle specialite du medecin
*Retour:			Aucun
*********************************************/
void Medecin::modifierSpecialite(Specialite* specialite)
{
	specialite_ = specialite;
}
//
//void Medecin::information() const
//{
//	std::cout << "| " << nom_ << AFFICHER_ESPACE(espace_nom - nom_.size());
//	std::cout << " | " << AFFICHER_ESPACE(espace_horaires - std::to_string(horaires_).size()) << horaires_;
//	std::cout << AFFICHER_ESPACE(espace_horaires);
//	obtenirSpecialite().information();
//	std::cout << endl;
//}

/*********************************************
*Fonctions:			operator=()
*Descriptions:		Surcharge d'opérateur qui permet d'inoculer les caractéristique
					d'un medecin dans celle d'un autre. 
*Parametre:			-(Medecin&)specialite	: nouvelle specialite du medecin
*Retour:			-(Medecin&)				: retourne le medecin afin de pouvoir faire medecin1 = medecin2 = medecin3
*********************************************/
Medecin& Medecin::operator=(const Medecin& droit) {
	
	if (this != &droit) {
		horaires_ = droit.horaires_;
		specialite_ = droit.specialite_;
		nom_ = droit.nom_;
	}
	return *this; 
}
/*********************************************
*Fonctions:			operator==()
*Descriptions:		Surcharge d'opérateur qui permet de comparer si le nom 
					du medecin est pareil a celui qui est entre en parametre
*Parametre:			-(string&)nom2	: nom avec lequel effectue la comparaison. 
*Retour:			-(bool)			: vrai si les nom sont pareils, faut dans le cas inverse
*********************************************/
bool Medecin::operator==(const string& nom2) const {
	return(nom_ == nom2);
}
/*********************************************
*Fonctions:			operator==()
*Descriptions:		Surcharge d'opérateur qui permet de comparer si le nom
du medecin est pareil a celui qui est entre en parametre
*Parametre:			-(string&)nom2	: nom avec lequel effectue la comparaison.
					-(Medecin&)		: medecin avec lequel comparer le string. 
*Retour:			-(bool)			: vrai si les nom sont pareils, faut dans le cas inverse
*********************************************/
bool operator==(string nom, const Medecin& medecin) {

	return(nom == medecin.nom_);
}

/*********************************************
*Fonctions:			operator==()
*Descriptions:		Surcharge d'opérateur qui permet de comparer si le nom
					de deux medecins sont pareil. 
*Parametre:			-(Medecin&)med1		: premier medecin pour la comparaison 
					-(Medecin&)med2		: second medecin pour la comparaison 
*Retour:			-(bool)			: vrai si les nom sont pareils, faut dans le cas inverse
*********************************************/
bool operator==(const Medecin& med1, const Medecin& med2)  {
	return(med1.obtenirNom == med2.obtenirNom);
}
/*********************************************
*Fonctions:			operator<<()
*Descriptions:		Surcharge d'opérateur qui permet d'afficher les informations concernant un medecin 
*Parametre:			-(Medecin&)medecin	: Objet medecin duquel on affiche les informations
					-(ostream&)o		: Stream de sortie afin d'afficher
*Retour:			-(ostream&)			: stream d'affichage
*********************************************/
ostream& operator<<(ostream& out, const Medecin& medecin) {
	
		out << "| " << left << setw(espace_nom) << medecin.obtenirNom() << right << "| " << left << setw(espace_horaires) <<medecin.obtenirHoraires() << right << "| "
			<< left << setw(espace_domaine) << medecin.obtenirSpecialite().obtenirDomaine() << right << "| " << left << setw(espace_niveau) <<medecin.obtenirSpecialite().modifierNiveau()
			<< "|" << endl;
	
	return out; 
}