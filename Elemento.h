#pragma once

//elemento tirado dos videos disponibilizados no moodle
template <class TE>class Elemento
{
private:
	Elemento<TE>* pProx;
	TE* item;
public:
	Elemento();
	~Elemento();
	void setpProx(Elemento<TE>* x) { this->pProx = x; }
	void setItem(TE* it) { this->item = it; }
	Elemento<TE>* getpProx() { return pProx; }
	TE* getitem() {  return item; }

};

template<class TE>
inline Elemento<TE>::Elemento()
{
	pProx = nullptr;
	item = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{

}

