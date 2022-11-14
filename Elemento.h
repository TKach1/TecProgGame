#pragma once

//elemento tirado dos videos disponibilizados no moodle
//template <class TE>class Elemento
//{
//private:
//	Elemento<TE>* pProx;
//	TE* item;
//public:
//	Elemento();
//	~Elemento();
//	void setpProx(Elemento<TE>* x) { this->pProx = x; }
//	void setItem(TE* it) { this->item = it; }
//	Elemento<TE>* getpProx() { return pProx; }
//	TE* getitem() {  return item; }
//
//};
//
//template<class TE>
//inline Elemento<TE>::Elemento()
//{
//	pProx = nullptr;
//	item = nullptr;
//}
//
//template<class TE>
//inline Elemento<TE>::~Elemento()
//{
//
//}
//


class Elemento
{
private:
	Elemento* pProx;
	Entidade* item;
public:
	Elemento();
	~Elemento();
	void setpProx(Elemento* x) { pProx = x; }
	void setItem(Entidade* it) { item = it; }
	Elemento* getpProx() { return pProx; }
	Entidade* getitem() {  return item; }

};


Elemento::Elemento()
{
	pProx = nullptr;
	item = nullptr;
}


Elemento::~Elemento()
{

}
