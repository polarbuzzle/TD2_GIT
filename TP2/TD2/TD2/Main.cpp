/**************************************************
 * Fichier : Main.cpp
 * Auteur(s) : FERRON Samuel, FONTAINE Jean-Frederic
 * Date: 08 Fevrier 2017
**************************************************/

#include <string>
#include <iostream>
#include "Personnel.h"
#include "Hopital.h"

/**
TODO: Répondre au questions
1. Quelle est l’utilité de l’opérateur = et du constructeur par copie ?

L'opérateur = nous permet de faire une copie d'un objet. Sans constructeur par copie, ce sera le constructeur par copie
propre au compilateur g++ qui sera appelé. Ce constructeur effectue bien une constrcution par copie. Par contre, elle sera
de type shallow. Ceci peut s'averer un problème si l'objet detient des pointeurs car ceux-ci 
appelle le constructeur défault pour construire son objet, alors il s'agit d'une shallow copy. 
Le constructeur par copie nous permet donc de faire un deep copy lorsque nous utilisons l'operateur =

2. Dans quel cas est-il absolument nécessaire de les implémenter ?

Lorsque nous manipulons des objets qui possedent des pointeurs, nous avons l'obligation d'implementer 
un constructeur par copie. Sans le constructeur par copie, nous effectuons une shallow copy, alors les
objets qui sont copiés auront des pointeurs qui partagent les mêmes adresses. Ceci peut être dangereux
dans certaines situations.

3. Qu’est-ce qui différencie l’opérateur = du constructeur par copie ?

L'operateur = est une affectation alors que le constructeur par copie est un type de constructeur d'objet; il 
cree un objet de rien.

**/

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

	//8- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules
	SacreCoeur.accederPersonnel() += &md0;
	SacreCoeur.accederPersonnel() += &md1;
	SacreCoeur.accederPersonnel() += &md2;
	SacreCoeur.accederPersonnel() += &md3;
	SacreCoeur.accederPersonnel() += &md4;

	//9- Creez 2 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Dr. Kyle : en Sport
	// Dr. House : en Psychiatrie
	Medecin md5("Kyle", 2, &sp5);
	Medecin md6("House", 80, &sp6);

	//10- Creer un autre medecin Sherlock en utilisant l'opérateur = et en utilisant le medecin existante Sherlock.
	// Le horaire du deuxieme Sherlock devrai ensuite etre modifie pour une valeur differnte du premier Sherlock
	Medecin sherlock = md1;
	sherlock.modifierHoraires(10);

	Medecin holmes(md2);
	holmes.modifierHoraires(70);
	
	// 11 - Ajoutez les medecins : parmis le personnel de l'hopital Jean Talen : 
	// Dr. Sherlock , Dr. Holmes , Dr. Kyle, Dr. House
	// Dr. Sherlock et Dr. Holmes sont les deux objets crée à partir de l'opératteur =
	JeanTalon.accederPersonnel() += &sherlock;
	JeanTalon.accederPersonnel() += &holmes;
	JeanTalon.accederPersonnel() += &md5;
	JeanTalon.accederPersonnel() += &md6;

	//12- Retirer le medecin Jean et deux infirmiers de l'hopital Sacré-Coeur et ajouter les
	// a l'hopital Jean-talon
	SacreCoeur.accederPersonnel() -= &md3;
	SacreCoeur.accederPersonnel() -= &inf0;
	SacreCoeur.accederPersonnel() -= &inf1;
	JeanTalon.accederPersonnel() += &md3;
	JeanTalon.accederPersonnel() += &inf0;
	JeanTalon.accederPersonnel() += &inf1;

	//13- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon
	cout << SacreCoeur << endl;
	cout << JeanTalon << endl;

	return 0;
}