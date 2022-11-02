#pragma once
#include "Elemento.h"

//Lista tirada dos videos disponibilizados no moodle
template <class TL> class Lista
{
private:
	Elemento<TL>* pPrim;
	Elemento<TL>* pUlt;
	int len;
public:
	Lista();
	~Lista();
	int getLen() { return len; }
	TL* getItem(int pos) {
		Elemento<TL>* temp = pPrim;
		if (pos == 0) {
			return temp->getitem();
		}
		for (int i = 0; i < pos; i++) {
			temp = temp->getpProx();
		}
		return temp->getitem();

	}

	void push(TL* it) {
		if (pPrim == nullptr) {
			pPrim = new Elemento<TL>;
			pPrim->setItem(it);
			pUlt = pPrim;
		}
		else {
			Elemento<TL>* temp = new Elemento<TL>;
			temp->setItem(it);
			pUlt->setpProx(temp);
			pUlt = temp;
		}
		len++;
	}

	void pop(TL* it);
};

template<class TL>
inline Lista<TL>::Lista()
{
	pPrim = nullptr;
	pUlt = nullptr;
	len = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{
}

template<class TL>
inline void Lista<TL>::pop(TL* it)
{
	Elemento<TL>* temp = pPrim;
	Elemento<TL>* tempAU = nullptr;
	while (temp->getitem() != it) {
		tempAU = temp;
		temp = temp->getpProx();
	}
	if (temp == pPrim) {
		pPrim = temp->getpProx();
	}
	else if (temp == pUlt) {
		tempAU->setpProx(nullptr);
		pUlt = tempAU;
	}
	else {
		tempAU->setpProx(temp->getpProx());
	}
	delete temp;
	len--;
}

