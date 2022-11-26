#pragma once

#include "Entidade.hpp"

class Personagem :
    public Entidade
{
private:
    bool _isEnabled;
public:

    Personagem();
    ~Personagem();

    void setEnabled(bool e) { _isEnabled = e; }
    bool isEnabled(){ return _isEnabled; }

    virtual bool tomarDano() { return false; }
    virtual void initOBJ();
    virtual void executarOBJ();
};

