/**********************************************
* Titre: Travail pratique #1 - Medecin.cpp
* Date: 10 janvier 2017
* Auteur: FERRON Samuel, FONTAINE Jean-Frederic
*Description: Impl�mentation de la classe Medecin
*********************************************/

#include"Medecin.h"
/*********************************************
*Fonctions:		Constructeur par default
*Descriptions:		Construit l'objet Medecin aves ses valeurs par defauts
*Parametre:		Aucun
*Retour:			Aucun
*********************************************/
Medecin::Medecin() {
	nom_ = "Inconnu";
	horaires_ = 0;
	specialite_ = nullptr;
}

/*********************************************
*Fonctions:		Medecin::Medecin
*Descriptions:	Constructeur par d�faut. Construit l'objet Specialite aves ses parametres
*Parametre:		-(string)nom : nom du medecin (IN)
				-(int)horaires : nombres d'heures associ� au medecin (IN)
-(Specialite*) : Specilit� du medecin (IN)
*Retour:		Aucun
*********************************************/