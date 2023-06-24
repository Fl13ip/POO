

#ifndef PRATICOTRABALHO_PANTANO_H
#define PRATICOTRABALHO_PANTANO_H

#include "Zona.h"

class Pantano : public Zona{

    const string tipo;
public:
    Pantano(int linha,int coluna) : Zona("pnt",linha,coluna) {};



};


#endif //PRATICOTRABALHO_PANTANO_H
