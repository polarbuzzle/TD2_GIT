#include "Infirmier.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/*********************************************
*Fonctions:		Constructeur par default
*Descriptions:	Construit l'objet Infirmier aves ses valeurs par defauts
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Infirmier::Infirmier()
{
	nom_ = "Inconnu";
	prenom_ = "Inconnu";
	nbChambre_ = 0;
}

/*********************************************
*Fonctions:		Constructeur par parametre
*Descriptions:	Construit l'objet Infirmier aves les valeurs entree en parametres
*Parametre:		-(string)nom : le nom de l'infirmier
				-(string)prenom : le prenom de l'infirmier
				-(unsigned int)-nbChambre : le nombre de chambre de l'infirmier
*Retour:		Aucun
*********************************************/
Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre): nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{
	nom_ = nom;
	prenom_ = prenom;
	nbChambre_ = nbChambre;
}

/*********************************************
*Fonctions:		Destructeur
*Descriptions:	Detruit l'objet
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Infirmier::~Infirmier()
{
	 //rien
}

/*********************************************
*Fonctions:		obtenir nom
*Descriptions:	retourne le nom de l'infirmier
*Parametre:		Aucun
*Retour:		-(string)nom_ : le nom de l'infirmier
*********************************************/
std::string Infirmier::obtenirNom() const
{
	return nom_;
}

/*********************************************
*Fonctions:		obtenir prenom
*Descriptions:	retourne le prenom de l'infirmier
*Parametre:		Aucun
*Retour:		-(string)prenom_ : le prenom de l'infirmier
*********************************************/
std::string Infirmier::obtenirPrenom() const
{
	return prenom_;
}

/*********************************************
*Fonctions:		obtenir nombre de chambre
*Descriptions:	retourne le nombre de chambre de l'infirmier
*Parametre:		Aucun
*Retour:		-(int)nbChambre_ : le nombre de chambre de l'infirmier
*********************************************/
unsigned int Infirmier::obtenirNbChambre() const
{
	return nbChambre_;
}

/*********************************************
*Fonctions:		obtenir nom complet
*Descriptions:	retourne le nom et le prenom de l'infirmier
*Parametre:		Aucun
*Retour:		-(string)nomComplet : le nom et le prenom de l'infirmier
*********************************************/
std::string Infirmier::obtenirNomComplet() const
{
	std::string nomComplet = prenom_ + "" + nom_;
	return nomComplet;
}

/*********************************************
*Fonctions:		Modifier nom
*Descriptions:	Permet de modifier le nom de l'infirmier
*Parametre:		-(string)nom : le nouveau nom de l'infirmier
*Retour:		Aucun
*********************************************/
void Infirmier::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

/*********************************************
*Fonctions:		Modifier prenom
*Descriptions:	Permet de modifier le prenom de l'infirmier
*Parametre:		-(stringpre)nom : le nouveau prenom de l'infirmier
*Retour:		Aucun
*********************************************/
void Infirmier::modifierPrenom(const std::string & prenom)
{
	prenom_ = prenom;
}

/*********************************************
*Fonctions:		Modifier nombre chambre
*Descriptions:	Permet de modifier le nombre de chambre de l'infirmier
*Parametre:		-(string)nbChambre : le nouveau nombre de chambre de l'infirmier
*Retour:		Aucun
*********************************************/
void Infirmier::modifierNbChambre(unsigned int nbChambre)
{
	nbChambre_ = nbChambre;
}

/*********************************************
*Fonctions:		Surcharge d'operateur <<
*Descriptions:	Permet d'afficher les informations de l'infirmier sur une ligne
*Parametre:		-(const Infirmier&)infirmier : l<infirmier que nous voulons afficher
*Retour:		-(ostream&)o : variable qui contient le stream
*********************************************/
std::ostream& operator<<(std::ostream& o, const Infirmier& infirmier)
{
	return o << "| " << std::setw(25) << std::left << infirmier.obtenirNomComplet() << std::right
		<< "| " << std::setw(25) << std::left << infirmier.obtenirNbChambre() << std::right << "|" << std::endl;
	
}

/*********************************************
*Fonctions:		Surcharge d'operateur ==
*Descriptions:	Permet de comparer deux objets infirmier ensemble
*Parametre:		-(const Infirmier&)infirmier : l'infirmier avec lequel nous voulons comparer
*Retour:		-(bool)estEgal : vrai ou faux qui confirme la comparaison
*********************************************/
bool Infirmier::operator==(const Infirmier& infirmier) const
{
	bool estEgal = this->obtenirNomComplet() == infirmier.obtenirNomComplet();
	return estEgal;
}

/*********************************************
*Fonctions:		Surcharge d'operateur ==
*Descriptions:	Permet de comparer un infirmier avec un nom complet
*Parametre:		-(const string&)nomComplet : le nom avec lequel on compare l'infirmier
*Retour:		-(bool)estEgal : vrai ou faux qui confirme la comparaison
*********************************************/
bool Infirmier::operator==(const std::string& nomComplet) const
{
	bool estEgal = this->obtenirNomComplet() == nomComplet;
	return estEgal;
}

/*********************************************
*Fonctions:		Surcharge d'operateur ==
*Descriptions:	Permet de comparer un infirmier avec un nom complet
*Parametre:		-(const string&)nomComplet : le nom avec lequel on compare l'infirmier
*Retour:		-(bool)estEgal : vrai ou faux qui confirme la comparaison
*********************************************/
bool operator==(const std::string& nomComplet, const Infirmier& infirmier)
{
	bool estEgal = infirmier.obtenirNomComplet() == nomComplet;
	return estEgal;
}

void Infirmier::information(const Infirmier& infirmier) const // A MODIFIER... (si necessaire)
{
	std::cout << "| " << infirmier.obtenirNomComplet() << AFFICHER_ESPACE(espace_nom - infirmier.obtenirNom().size());
	std::cout << " | " << AFFICHER_ESPACE(espace_chambre - std::to_string(infirmier.nbChambre_).size()/2);
	std::cout << infirmier.nbChambre_ << AFFICHER_ESPACE(espace_chambre);
	std::cout << "|" << std::endl;
}
