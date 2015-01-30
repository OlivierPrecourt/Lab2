#include "dynamicArray.h"
#include <stdexcept>

const int TAILLE_PAR_DEFAUT_TABLEAU = 100;

DynamicArray::~DynamicArray(){
	delete tabElement;
}

DynamicArray::DynamicArray(){
	tabElement = new int[TAILLE_PAR_DEFAUT_TABLEAU];
	capacite = TAILLE_PAR_DEFAUT_TABLEAU;

	for (int i = 0; i < TAILLE_PAR_DEFAUT_TABLEAU; i++){
		tabElement[i] = 0;
	}
}

DynamicArray::DynamicArray(unsigned int _capacite){
	tabElement = new int[_capacite];
	capacite = _capacite;

	for (int i = 0; i < _capacite; i++){
		tabElement[i] = 0;
	}
}

void DynamicArray::setElement(unsigned int _index, int _valeur){
	if (_index >= capacite){
		//on augmente la capacité
	}
	else {
		tabElement[_index] = _valeur;
	}
}

int DynamicArray::getElement(unsigned int _index) const {
	if (_index >= capacite){
		throw  std::runtime_error("l'element n'existe pas");
	}
	else {
		return tabElement[_index];
	}
}

int DynamicArray::getCapacite() const {
	return (int)capacite;
}

void DynamicArray::setCapacite(unsigned int _capacite){
	capacite = _capacite;
}

