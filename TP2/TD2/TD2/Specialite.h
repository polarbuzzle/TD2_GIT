/**********************************************
* Titre: Travail pratique #1 - Specialite.h
* Date: 8 Fevrier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
* Description: Definition de la classe Specialite
*********************************************/
#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:
	//Constructeur par defeault
	Specialite();
	//Contructeur par parametre
	Specialite(const std::string& domaine, unsigned int niveau);
	//Accesseurs
	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;
	//Modificateurs
	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);
	//Attributs
private:
	std::string domaine_;
	unsigned int niveau_;
};
	//Surcharge d'operateur <<
std::ostream& operator<<(std::ostream& o, const Specialite& specialite);

#endif