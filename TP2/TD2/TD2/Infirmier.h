/**********************************************
* Titre: Travail pratique #1 - Infirmier.h
* Date: 8 Fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
* Description: Definition de la classe Infirmier
*********************************************/
#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>

class Infirmier
{
public:
	Infirmier(); // A MODIFIER... (si necessaire)
	Infirmier(const std::string& nom, const std::string& prenom, unsigned int nbChambre); // A MODIFIER... (si necessaire)
	~Infirmier(); // A MODIFIER... (si necessaire)

	std::string obtenirNom() const; 
	std::string obtenirPrenom() const;
	unsigned int obtenirNbChambre() const;
	std::string Infirmier::obtenirNomComplet() const;

	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierNbChambre(unsigned int nbChambre);

	//void information() const; // A MODIFIER... (si necessaire)
	
	bool operator==(const Infirmier& infirmier) const;
	bool operator==(const std::string& nomComplet) const;
	friend bool operator==(const std::string& nomComplet, const Infirmier& infirmier);

private:
	std::string nom_;
	std::string prenom_;
	unsigned int nbChambre_;
};

std::ostream& operator<<(std::ostream& o, const Infirmier& infirmier);

#endif
