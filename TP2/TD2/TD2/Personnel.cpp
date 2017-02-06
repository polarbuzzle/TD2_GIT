#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

/*********************************************
*Fonctions:		Constructeur par default
*Descriptions:	Construit l'objet Personnel aves ses valeurs par defauts
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Personnel::Personnel() 
{
	//rien
};

/*********************************************
*Fonctions:		Destructeur
*Descriptions:	Detruit l'objet Personnel
*Parametre:		Aucun
*Retour:		Aucun
*********************************************/
Personnel::~Personnel() 
{
	
};
	
/*********************************************
*Fonctions:		Ajouter medecin
*Descriptions:	Ajoute un medecin dans le vecteur medecins_
*Parametre:		-(Medecin*)medecin : pointeur de type medecin
*Retour:		-(bool)memeNom : booleen qui confirme si l'ajout a bien ete fait
*********************************************/
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	bool memeNom = false;

	for (unsigned i = 0; i < medecins_.size(); i++) {
		if (*medecins_[i] == *medecin)
			memeNom = true;
	}
	if (!memeNom)
		medecins_.push_back(medecin);
	return !memeNom;
}

/*********************************************
*Fonctions:		Retirer medecin
*Descriptions:	Enleve un medecin dans le vecteur medecins_
*Parametre:		-(string&)nom :nom du medecin que l'on veut retirer
*Retour:		-(bool)estRetire : booleen qui confirme si la supresison a bien ete fait
*********************************************/
bool Personnel::retirerMedecin(const std::string& nom)  
{
	bool estRetire = false;
	for (unsigned i = 0; i < medecins_.size(); i++)
	{
		if (*medecins_[i] == nom)
		{
			medecins_.erase(medecins_.begin() + i);
			estRetire = true;
		}
	}
	return estRetire;
}

/*********************************************
*Fonctions:		Ajouter infirmier
*Descriptions:	Ajoute un infirmier dans le vecteur infirmiers_
*Parametre:		-(Infirmier*)infirmier : pointeur de type infirmier
*Retour:		-(bool)memeNom : booleen qui confirme si l'ajout a bien ete fait
*********************************************/
bool Personnel::ajouterInfirmier(Infirmier* infirmier) 
{
	bool memeNom = false; 
	for (int i = 0; i < infirmiers_.size(); i++)
		if (*infirmiers_[i] == *infirmier) {
			memeNom = true;
		}
	if (!memeNom)
		infirmiers_.push_back(infirmier);
	return !memeNom;
}

/*********************************************
*Fonctions:		Retirer infirmier
*Descriptions:	Enleve un infirmier dans le vecteur infirmiers_
*Parametre:		-(string&)nom :nom de l'infirmier que l'on veut retirer
*Retour:		-(bool)estRetire : booleen qui confirme si la supresison a bien ete fait
*********************************************/
bool Personnel::retirerInfirmier(const std::string& nomComplet) 
{
	bool estRetire = false;
	for (int i = 0; i < infirmiers_.size(); i++) {
		if (infirmiers_[i]->obtenirNom == nomComplet) {
			infirmiers_.erase(infirmiers_.begin() + i); 
			estRetire = true;
		}
			
	}
	return estRetire;
}

/*********************************************
*Fonctions:		Surcharge d'operateur +=
*Descriptions:	permet d'ajouter un medecin dans le vecteur medecins_
*Parametre:		-(Medecin*)Medecin : le medecin que nous voulons ajouter
*Retour:		-(Personnel&)this : le personnel modiffie
*********************************************/
Personnel& Personnel::operator+=(Medecin* medecin)
{
	this->ajouterMedecin(medecin);
	return *this;
}

/*********************************************
*Fonctions:		Surcharge d'operateur -=
*Descriptions:	permet de retirer un medecin dans le vecteur medecins_
*Parametre:		-(Medecin*)Medecin : le medecin que nous voulons retirer
*Retour:		-(Personnel&)this : le personnel modiffie
*********************************************/
Personnel& Personnel::operator-=(Medecin* medecin)
{
	this->retirerMedecin(medecin->obtenirNom());
	return *this;
}

/*********************************************
*Fonctions:		Surcharge d'operateur +=
*Descriptions:	permet d'ajouter un infirmier dans le vecteur infirmiers_
*Parametre:		-(Infirmier*)infirmier : l'infirmier que nous voulons ajouter
*Retour:		-(Personnel&)this : le personnel modiffie
*********************************************/
Personnel& Personnel::operator+=(Infirmier* infirmier)
{
	this->ajouterInfirmier(infirmier);
	return *this;
}

/*********************************************
*Fonctions:		Surcharge d'operateur -=
*Descriptions:	permet de retirer un infirmier dans le vecteur infirmiers_
*Parametre:		-(Infirmier*)infirmier : l'infirmier que nous voulons retirer
*Retour:		-(Personnel&)this : le personnel modiffie
*********************************************/
Personnel& Personnel::operator-=(Infirmier* infirmier)
{
	this->retirerInfirmier(infirmier->obtenirNom());
	return *this;
}

std::ostream& operator<<(std::ostream& o, const Personnel& personnel)
{
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	o << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	o << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	o << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size())
		<< " | " << horaires << AFFICHER_ESPACE(2 * espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size())
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;

	o << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < personnel.medecins_.size(); i++)
	{
		o << *(personnel.medecins_[i]) << std::endl;
	}
	o << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	o << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;

	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";
	o << AFFICHER_ESPACE(espacement_infirmier / 2) << tabInf
		<< AFFICHER_ESPACE(espacement_infirmier / 2) << endl;
	o << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	o << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		<< " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		<< " | " << endl;
	o << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < personnel.infirmiers_.size(); i++)
	{
		o << *(personnel.infirmiers_[i]) << std::endl;
	}

	o << AFFICHER_LINE(espacement_infirmier + tabInf.size());

	return o;
}
	

//void Personnel::information() const // A MODIFIER...
//{
//	this->afficherMedecins();
//	this->afficherInfirmiers();
//}
//
//void Personnel::afficherMedecins() const // A MODIFIER... (si necessaire)
//{
//	string tabMed = "Tableau Medecins";
//	string nom = "Nom";
//	string horaires = "Horaires";
//	string domaine = "Domaine Specialite";
//	string niveau = "Niveau Specialite";
//
//	std::cout << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
//		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;
//
//	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
//
//	std::cout << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
//		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
//		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
//		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
//		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
//		<< "| " << endl;
//		
//	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
//	for (size_t i = 0; i < medecins_.size(); i++)
//	{	
//		std::cout << medecins_[i] << std::endl;
//	}
//	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
//	std::cout << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;
//}
//
//void Personnel::afficherInfirmiers() const // A MODIFIER... (si necessaire)
//{
//	string tabInf = "Tableau Infimiers";
//	string nomComplet = "Nom Complet";
//	string nbChambre = "Nombre de Chambre";
//	std::cout << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
//		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
//	std::cout << AFFICHER_LINE(espace	ment_infirmier + tabInf.size()) << endl;
//	
//	std::cout << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
//		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
//		 << " | " << endl;
//	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
//
//	for (size_t i = 0; i < infirmiers_.size(); i++)
//	{
//		std::cout << infirmiers_[i] << std::endl;
//	}
//
//	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size());
//}