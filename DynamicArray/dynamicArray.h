#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(unsigned int _capacite);
	~DynamicArray();
	void setElement(unsigned int _index, int _valeur);
	int getElement(unsigned int index);
	unsigned int getCapacite();
	void setCapacite(unsigned int _capacite);
private:
	int* tabElement;
	unsigned int capacite;
};


#endif //DYNAMICARRAY_H_