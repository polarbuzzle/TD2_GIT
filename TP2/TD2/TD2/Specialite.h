#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:
	Specialite();

	Specialite(const std::string& domaine, unsigned int niveau);

	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	//void information(const Specialite& specialite) const; // A MODIFIER... (si necessaire) 

	// _________TP2___________
private:
	std::string domaine_;
	unsigned int niveau_;
};

std::ostream& operator<<(std::ostream& o, const Specialite& specialite);

#endif