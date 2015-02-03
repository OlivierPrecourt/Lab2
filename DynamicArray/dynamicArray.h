#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(unsigned int _capacite);
	~DynamicArray();
	bool operator==(const DynamicArray& _rhs) const;
	bool operator=(const DynamicArray& _rhs) const;
	DynamicArray & operator+=(const DynamicArray& _rhs) ;
	void setElement(unsigned int _index, int _valeur);
	int getElement(unsigned int index) const;
	int getCapacite() const;
	void setCapacite(unsigned int _capacite);
private:
	int* tabElement;
	unsigned int capacite;
};


#endif //DYNAMICARRAY_H_