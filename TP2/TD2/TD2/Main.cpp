/**************************************************
 * Main.cpp
 * Date: 31 janvier 2017
**************************************************/

#include <string>
#include <iostream>
#include "Personnel.h"

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

	perso1 += &inf0;

	cout << perso1;

	//3 - Creez deux objects de type Hopital qui vont prendre chacun en parametre le nom de l'hopital et le personnel assigné
	// Hopital Sacré-Coeur de Montréal
	// Hôpital Jean-Talon
	// A COMPLETER...


	//4-  Ajoutez les 6 objets du type Infimier � au personnel de l'Hôpital Sacré-Coeur de Montréal
	

	//5-  Ajoutez les 5 objets qui restent du type Infimier � au personnel de l'Hôpital Jean-Talon
	// A COMPLETER...
	
	//6-  Creez 7 objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Specialites : Chirurgie, Demartologie, Gastrologie, Sport, Podologie, Pediatrie, Psychiatrie
	Specialite sp0();
	Specialite sp1();
	Specialite sp2();
	Specialite sp3();
	Specialite sp4();
	Specialite sp5();
	Specialite sp6();
	//7- Creez 7 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Dr. Franc : en Chirurgie
	// Dr. Sherlock : en Demartologie
	// Dr. Holmes : en Gastrologie
	// Dr. Jean : en Podologie
	// Dr. Jules : en Pediatrie
	// Dr. Kyle : en Sport
	// Dr. House : en Psychiatrie
	// A COMPLETER...

	//8- Creer un autre medecin Sherlock en utilisant l'opérateur = et en utilisant le medecin existante Sherlock.
	// Le horaire du deuxieme Sherlock devrai ensuite etre modifie pour une valeur differnte du premier Sherlock
	// A COMPLETER...

	//9- Creer un autre medecin Holmes en utilisant le constructeur de copie et en utilisant le medecin existante Holmes.
	// Le horaire du deuxieme Holmes devrai ensuite etre modifie pour une valeur differnte du premier Holmes
	// A COMPLETER...

	
	//10- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules
	// A COMPLETER...
	// Dr. Sherlock(2), Dr. Holmes(2), Dr. Kyle, Dr. House
	// A COMPLETER...
	


	//11- Retirer le medecin Jean et deux infirmiers de l'hopital Sacré-Coeur et ajouter les
	// a l'hopital Jean-talon


	//12- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon
	// A COMPLETER...

	return 0;
}