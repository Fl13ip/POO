
#include "Ilha.h"
#include "Deserto.h"
#include "Floresta.h"
#include "Pastagem.h"
#include "Montanha.h"
#include "Pantano.h"
#include "Favela.h"
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

Ilha::Ilha(const int l, const int c) : linhas(l), colunas(c) {
    recursos = new Recursos();

    for(int i=0; i<linhas; i++) {
        vector<Zona* > v1;
        int f = random_l_h(1,6);

        for(int j=0; j<colunas; j++) {

            f = random_l_h(1,6);
            switch (f) {
                case 1:
                    v1.push_back(new Deserto(i,j));
                    break;

                case 2:
                    v1.push_back(new Floresta(i,j));
                    break;

                case 3:
                    v1.push_back(new Pastagem(i,j));
                    break;

                case 4:
                    v1.push_back(new Montanha(i,j));
                    break;

                case 5:
                    v1.push_back(new Pantano(i,j));
                    break;

                case 6:
                    v1.push_back(new Favela(i,j));
                    break;

            }
        }
        ilhaBi.push_back(v1);
    }
    for(int i=0; i<ilhaBi.size(); i++) {
        for(int j=0; j<ilhaBi[i].size();j++) {
            ilhaBi[i][j]->pointToRecursos(recursos);
            ilhaBi[i][j]->pointToIlha(this);
        }
    }
}

void Ilha::showIlha() {
    cout << endl;
    cout << "Dia: " << getDay() << endl;
    cout << "Dinheiro: " << recursos->getMoney() << " euros" << endl;
    cout << "Madeira: " << recursos->getMadeira() << " kg" << endl;
    cout << "Ferro: " << recursos->getFerro() << " kg" << endl;
    cout << "Carvao: " << recursos->getCarvao() << " kg" << endl;
    cout << "Barras de Aco: " << recursos->getBarraAco() << " kg" << endl;
    cout << "Vigas de Madeira: " << recursos->getVigaMadeira() << endl;
    cout << "Eletricidade: " << recursos->getEletricidade() << " KWh" << endl;
    cout << endl;



    int z = 0;

    if (colunas == 3) cout << "-------------------------";
    if (colunas == 4) cout << "---------------------------------";
    if (colunas == 5) cout << "-----------------------------------------";
    if (colunas == 6) cout << "-------------------------------------------------" ;
    if (colunas == 7) cout << "---------------------------------------------------------" ;
    if (colunas == 8) cout << "-----------------------------------------------------------------" ;
    if (colunas == 9) cout << "-------------------------------------------------------------------------" ;
    if (colunas == 10) cout << "---------------------------------------------------------------------------------" ;
    if (colunas == 11) cout << "-----------------------------------------------------------------------------------------";
    if (colunas == 12) cout << "-------------------------------------------------------------------------------------------------" ;
    if (colunas == 13) cout << "---------------------------------------------------------------------------------------------------------" ;
    if (colunas == 14) cout << "-----------------------------------------------------------------------------------------------------------------" ;
    if (colunas == 15) cout << "-------------------------------------------------------------------------------------------------------------------------";
    if (colunas == 16) cout << "---------------------------------------------------------------------------------------------------------------------------------" ;
    cout << endl;
    for (int i = 0; i < linhas;) {
        for (int j = 0; j < colunas; j++) {
            if (z == 0) {
                if (j == 0) {
                    cout << "| ";
                }
                cout << " " << ilhaBi[i][j]->getTipoZona() << "  | ";
            }
            if (z == 1) {
                if (j == 0) {
                    cout << "| ";
                }
                if (ilhaBi[i][j]->getTipoEdificio() == " ") {
                    cout << ilhaBi[i][j]->getTipoEdificio() << "     | ";
                } else if(ilhaBi[i][j]->getTipoEdificio() == "barg" || ilhaBi[i][j]->getTipoEdificio() == "elec"){
                    cout << ilhaBi[i][j]->getTipoEdificio() << "   | ";
                } else {
                    cout << " " << ilhaBi[i][j]->getTipoEdificio() << "  | ";
                }
            }
            if (z == 2) {
                if (j == 0) {
                    cout << "| ";
                }
                if (ilhaBi[i][j]->NumbWorkers() == 0) {
                    cout << "      | ";
                }else{
                    cout << ilhaBi[i][j]->getTipoWorkers() << "      | ";
                }
            }
            if (z == 3) {
                if (j == 0) {
                    cout << "| ";
                }
                if (ilhaBi[i][j]->NumbWorkers() >= 0 && ilhaBi[i][j]->NumbWorkers() <= 9) {
                    cout <<"  " <<  ilhaBi[i][j]->NumbWorkers() << "   | ";
                }
                if (ilhaBi[i][j]->NumbWorkers() >= 10 && ilhaBi[i][j]->NumbWorkers() <= 99) {
                    cout <<" " << ilhaBi[i][j]->NumbWorkers() << "   | ";
                }
                if (ilhaBi[i][j]->NumbWorkers() >= 100 && ilhaBi[i][j]->NumbWorkers() <= 999) {
                    cout <<" " << ilhaBi[i][j]->NumbWorkers() << "  | ";
                }
            }

            if (j == (ilhaBi[i].size() - 1)) {
                z++;
            }
            if (z == 4) {
                i++;
                z = 0;
                cout <<"\n";
                if (colunas == 3) { cout << "-------------------------" ; }
                else if (colunas == 4) { cout << "---------------------------------" ; }
                else if (colunas == 5) { cout << "-----------------------------------------" ; }
                else if (colunas == 6) { cout << "-------------------------------------------------" ; }
                else if (colunas == 7) { cout << "---------------------------------------------------------" ; }
                else if (colunas == 8) {
                    cout << "-----------------------------------------------------------------" ;
                }
                else if (colunas == 9) {
                    cout << "-------------------------------------------------------------------------" ;
                }
                else if (colunas == 10) {
                    cout << "---------------------------------------------------------------------------------" ;
                }
                else if (colunas == 11) {
                    cout << "-----------------------------------------------------------------------------------------" ;
                }
                else if (colunas == 12) {
                    cout << "-------------------------------------------------------------------------------------------------" ;
                }
                else if (colunas == 13) {
                    cout << "---------------------------------------------------------------------------------------------------------" ;
                }
                else if (colunas == 14) {
                    cout << "-----------------------------------------------------------------------------------------------------------------" ;
                }
                else if (colunas == 15) {
                    cout << "-------------------------------------------------------------------------------------------------------------------------" ;
                }
                else if(colunas == 16)
                    cout << "---------------------------------------------------------------------------------------------------------------------------------" ;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Ilha::showIlha2() {
    cout << endl;
    cout << "Dia: " << getDay() << endl;
    cout << "Dinheiro: " << recursos->getMoney() << " euros" << endl;
    cout << "Madeira: " << recursos->getMadeira() << " kg" << endl;
    cout << "Ferro: " << recursos->getFerro() << " kg" << endl;
    cout << "Carvao: " << recursos->getCarvao() << " kg" << endl;
    cout << "Barras de Aco: " << recursos->getBarraAco() << " kg" << endl;
    cout << "Vigas de Madeira: " << recursos->getVigaMadeira() << endl;
    cout << "Eletricidade: " << recursos->getEletricidade() << " KWh" << endl;
    cout << endl;

    for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                cout << ilhaBi[i][j]->getTipoZona() << " - " << ilhaBi[i][j]->NumbWorkers()<< " / "
                << ilhaBi[i][j]->getNumEdificios() <<"     ";
            }
            cout << endl;
            cout << endl;
        }
        cout <<endl;
}