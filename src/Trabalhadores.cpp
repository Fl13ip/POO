

#include "Trabalhadores.h"
#include "Zona.h"

int Trabalhadores::Serie=0;

Trabalhadores::Trabalhadores(const string tipo, const int price,const int contracDay) : tipo(tipo),price(price),
                                                                                        contracDay(contracDay){
    id=Serie+1;
    Serie++;
    zona = nullptr;
}

void Trabalhadores::entrarNaZona(Zona *abc) {
    zona = abc;
}
