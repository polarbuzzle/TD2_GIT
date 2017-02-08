/**************************************************
 * Main.cpp
 * Date: 31 janvier 2017
**************************************************/

#include <string>
#include <iostream>
#include "Personnel.h"
#include "Hopital.h"

using namespace std;

int main()
{
	// C'est a vous de voir si vous devez allouer dynamiquement ou non les elements

	//1-  Creez 11 objets du type Infirmier � l'aide du constructeur par param�tre avec des valeurs de votre choix
	Infirmier inf0("Boucher", "Steven", 14);
	Infirmier inf1("Lambert", "Hermenegildeh", 17);
	Infirmier inf2("Pouliotte", "Anne", 10);
	Infirmier inf3("McGee", "Julie", 24);
	Infirmier inf4("Montagne", "Mr", 32);
	Infirmier inf5("Dubois", "Albert", 2);
	Infirmier inf6("Campagne", "Carmen", 22);
	Infirmier inf7("Farfelu", "Poilu", 30);
	Infirmier inf8("Matombe", "Jecreuse", 9);
	Infirmier inf9("Lafeuille", "Marie", 3);
	Infirmier infA("Janvier", "Paul", 27);

	//2-  Creez deux objets du type Personnel � l'aide du constructeur par d�faut
	Personnel perso1;
	Personnel perso2;

	//3 - Creez deux objects de type Hopital qui vont prendre chacun en parametre le nom de l'hopital et le personnel assigné
	Hopital SacreCoeur("Sacre-Coeur", &perso1);
	Hopital JeanTalon("Jean-Talon", &perso2);

	//4-  Ajoutez les 6 objets du type Infimier � au personnel de l'Hôpital Sacré-Coeur de Montréal
	SacreCoeur.accederPersonnel() += &inf0;
	SacreCoeur.accederPersonnel() += &inf1;
	SacreCoeur.accederPersonnel() += &inf2;
	SacreCoeur.accederPersonnel() += &inf3;
	SacreCoeur.accederPersonnel() += &inf4;
	SacreCoeur.accederPersonnel() += &inf5;
		

	//5-  Ajoutez les 5 objets qui restent du type Infimier � au personnel de l'Hôpital Jean-Talon
	JeanTalon.accederPersonnel() += &inf6;
	JeanTalon.accederPersonnel() += &inf7;
	JeanTalon.accederPersonnel() += &inf8;
	JeanTalon.accederPersonnel() += &inf9;
	JeanTalon.accederPersonnel() += &infA;

	//6-  Creez 7 objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Specialites : Chirurgie, Demartologie, Gastrologie, Sport, Podologie, Pediatrie, Psychiatrie
	Specialite sp0("Boucher d'experience", 100);
	Specialite sp1("Couturier de feu", 101 );
	Specialite sp2("Etoile de glace", 99 );
	Specialite sp3("Poisonier debutant",3 );
	Specialite sp4("Filet mignon", 69);
	Specialite sp5("Dieux en devenir",1000 );
	Specialite sp6("Jesus himself", 2 );
	
	//7- Creez 7 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	Medecin md0("Franc", 40, &sp0);
	Medecin md1("Sherlock", 30, &sp1);
	Medecin md2("Holmes", 35, &sp2);
	Medecin md3("Jean", 40, &sp3);
	Medecin md4("Jules", 40, &sp4);
	Medecin md5("Kyle", 2, &sp5);
	Medecin md6("House", 80, &sp6);

	//8- Creer un autre medecin Sherlock en utilisant l'opérateur = et en utilisant le medecin existante Sherlock.
	// Le horaire du deuxieme Sherlock devrai ensuite etre modifie pour une valeur differnte du premier Sherlock
	Medecin sherlock(md1);
	sherlock.modifierHoraires(10);

	//9- Creer un autre medecin Holmes en utilisant le constructeur de copie et en utilisant le medecin existante Holmes.
	// Le horaire du deuxieme Holmes devrai ensuite etre modifie pour une valeur differnte du premier Holmes
	Medecin holmes(md2);
	holmes.modifierHoraires(70);
	
	//10- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules
	SacreCoeur.accederPersonnel() += &md0;
	SacreCoeur.accederPersonnel() += &md1;
	SacreCoeur.accederPersonnel() += &md2;
	SacreCoeur.accederPersonnel() += &md3;
	SacreCoeur.accederPersonnel() += &md4;

	// Dr. Sherlock(2), Dr. Holmes(2), Dr. Kyle, Dr. House
	JeanTalon.accederPersonnel() += &sherlock;
	JeanTalon.accederPersonnel() += &holmes;
	JeanTalon.accederPersonnel() += &md5;
	JeanTalon.accederPersonnel() += &md6;

	//11- Retirer le medecin Jean et deux infirmiers de l'hopital Sacré-Coeur et ajouter les
	// a l'hopital Jean-talon
	SacreCoeur.accederPersonnel() -= &md3;
	SacreCoeur.accederPersonnel() -= &inf0;
	SacreCoeur.accederPersonnel() -= &inf1;
	JeanTalon.accederPersonnel() += &md3;
	JeanTalon.accederPersonnel() += &inf0;
	JeanTalon.accederPersonnel() += &inf1;

	//12- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon
	cout << SacreCoeur << endl;
	cout << JeanTalon << endl;

	return 0;
}