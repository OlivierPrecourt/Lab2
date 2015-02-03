#include "dynamicArray.h"
#include <stdexcept>

using namespace std;

const int TAILLE_PAR_DEFAUT_TABLEAU = 100;
const string ERREUR_HORS_DE_INDEX = "l'element n'existe pas";
const string ERREUR_CAPACITE_INVALIDE = "capacite invalide";

DynamicArray::~DynamicArray(){
	delete[] tabElement;
}

DynamicArray::DynamicArray(){
	tabElement = new int[TAILLE_PAR_DEFAUT_TABLEAU];
	capacite = TAILLE_PAR_DEFAUT_TABLEAU;

	for (int i = 0; i < TAILLE_PAR_DEFAUT_TABLEAU; i++){
		tabElement[i] = 0;
	}
}

DynamicArray::DynamicArray(unsigned int _capacite){
	if (_capacite < 1) {
		throw invalid_argument(ERREUR_CAPACITE_INVALIDE);
	}
	else {
		tabElement = new int[_capacite];
		capacite = _capacite;

		for (int i = 0; i < _capacite; i++){
			tabElement[i] = 0;
		}
	}
}

void DynamicArray::setElement(unsigned int _index, int _valeur){
	
	if (_index < 0) {
		throw out_of_range(ERREUR_HORS_DE_INDEX);
	} else if (_index >= capacite){
		int *nouveauTableau = new int[_index + 1];

		for (int i = 0; i < capacite; i++){
			nouveauTableau[i] = tabElement[i];
		}

		for (int i = capacite; i < _index + 1; i++){
			nouveauTableau[i] = 0;
		}
		delete[] tabElement;
		tabElement = nouveauTableau;
		capacite = _index + 1;
	}

		tabElement[_index] = _valeur;
}

int DynamicArray::getElement(unsigned int _index) const {
	if (_index >= capacite){
		throw  out_of_range(ERREUR_HORS_DE_INDEX);
	}
	else {
		return tabElement[_index];
	}
}

int DynamicArray::getCapacite() const {
	return (int)capacite;
}

void DynamicArray::setCapacite(unsigned int _capacite){
	if (_capacite < 1) {
		throw invalid_argument(ERREUR_CAPACITE_INVALIDE);
	}
	else if (_capacite > capacite){
		int *nouveauTableau = new int[_capacite];

		for (int i = 0; i < capacite; i++){
			nouveauTableau[i] = tabElement[i];
		}

		for (int i = capacite; i < _capacite; i++){
			nouveauTableau[i] = 0;
		}

		delete[] tabElement;
		tabElement = nouveauTableau;
		capacite = _capacite;
	}
	else {
		int *nouveauTableau = new int[_capacite];

		for (int i = 0; i < _capacite; i++){
			nouveauTableau[i] = tabElement[i];
		}

		delete[] tabElement;
		tabElement = nouveauTableau;
		capacite = _capacite;
	}
}

