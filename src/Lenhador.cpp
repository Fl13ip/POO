

#include "Lenhador.h"
#include "Zona.h"

void Lenhador::newWorkDay() {
    Trabalhadores::newWorkDay();
    dayCount++;
    if(giveZonaRef()->getTipoZona() != "mnt") {
        if(aux){
            rest = false;
            cout << "O Lenhador de id " << getId() << " ,na zona " << giveZonaRef()->getTipoZona() << " ,esta de volta ao trabalho." << endl;
            dayCount = 0;
            aux = false;
        } else if(dayCount > 3) {
            rest = true;
            cout << "O Lenhador de id " << getId() << " ,na zona " << giveZonaRef()->getTipoZona() << " ,tirou o dia." << endl;
            aux = true;
        }
    } else {
        bool TrueFalse = (rand() % 100) < 5;
        if(aux){
            if(TrueFalse){
                cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                     getId() << " . Adeus!!" << endl;
                giveZonaRef()->fireWorker(getId());
            } else {
                rest = false;
                dayCount = 0;
                aux = false;
            }
        } else if(dayCount > 4) {
            if(TrueFalse){
                cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                     getId() << " . Adeus!!" << endl;
                giveZonaRef()->fireWorker(getId());
            } else {
                rest = true;
                aux = true;
            }
        }
    }
}