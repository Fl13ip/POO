

#ifndef PRATICOTRABALHO_PASTAGEM_H
#define PRATICOTRABALHO_PASTAGEM_H

#include <cstring>
#include "Zona.h"

class Pastagem : public Zona{

    const string tipo;
public:
    Pastagem(int linha,int coluna) : Zona("pas",linha,coluna){};

};


#endif //PRATICOTRABALHO_PASTAGEM_H
