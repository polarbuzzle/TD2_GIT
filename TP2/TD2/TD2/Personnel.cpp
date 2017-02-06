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
*
*********************************************/
Personnel::Personnel() 
{
	//rien
};

Personnel::~Personnel() 
{
	for (unsigned i = 0; i < medecins_.size(); i++)
	{
		delete medecins_[i];
	}
	for (unsigned i = 0; i < infirmiers_.size(); i++)
	{
		delete infirmiers_[i];
	}
};
	
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	medecins_.push_back(new Medecin(*medecin));
	return true;
}

bool Personnel::retirerMedecin(const std::string& nom)  
{
	for (unsigned i = 0; i < medecins_.size(); i++)
	{
		if (nom == medecins_[i]->obtenirNom())
		{
			delete medecins_[i];
			medecins_.erase(medecins_.begin() + i);
		}
	}
	return false;
}

bool Personnel::ajouterInfirmier(Infirmier* infirmier) 
{
	// A MODIFIER...
	return true;
}

bool Personnel::retirerInfirmier(const std::string& nomComplet) 
{
	// A MODIFIER...
	return false;
}
	

void Personnel::information() const // A MODIFIER...
{
	this->afficherMedecins();
	this->afficherInfirmiers();
}

void Personnel::afficherMedecins() const // A MODIFIER... (si necessaire)
{
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	std::cout << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	std::cout << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;
		
	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < medecins_.size(); i++)
	{	
		medecins_[i]->information();
		std::cout << endl;
	}
	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	std::cout << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;
}

void Personnel::afficherInfirmiers() const // A MODIFIER... (si necessaire)
{
	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";
	std::cout << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
	
	std::cout << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		 << " | " << endl;
	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < infirmiers_.size(); i++)
	{
		infirmiers_[i]->information()
		std::cout << endl;
	}

	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size());
}