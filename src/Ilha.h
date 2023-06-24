

#ifndef PRATICOTRABALHO_ILHA_H
#define PRATICOTRABALHO_ILHA_H

#include "Zona.h"
#include "Recursos.h"
#include <vector>

using namespace std;

class Ilha {

    const int linhas;
    const int colunas;
    vector<vector<Zona*>> ilhaBi;
    Recursos* recursos;
    bool find=false;
    int dia=1;

public:

    Ilha() = delete;
    Ilha(const int l, const int c);

    string getZonaTipo(const int l, const int c){
        return ilhaBi[l-1][c-1]->getTipoZona();
    }

    bool HaveflrAround(const int linha, const int coluna) const{
        if(coluna > 0 && coluna < this->colunas-1 && linha > 0 && linha < this->linhas-1){
            if(ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == 0 && coluna > 0 && coluna < this->colunas-1) {
            if(ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == 0 && coluna == 0) {
            if(ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(coluna == 0 && linha > 0 && linha < this->linhas-1) {
            if(ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()) {
                return true;
            }
        } else if(coluna == 0 && linha == this->linhas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna > 0 && coluna < this->colunas-1) {
            if(ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna+1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna+1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()){
                return true;
            }
        } else if(linha == 0 && coluna == this->colunas-1) {
            if(ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()) {
                return true;
            }
        } else if(coluna == this->colunas-1 && linha > 0 && linha < this->linhas-1) {
            if(ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()
               ||ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha+1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha+1][coluna]->HaveProduceThisDay()) {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna == this->colunas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoZona() == "flr"
               &&ilhaBi[linha-1][coluna]->HaveProduceThisDay()
               ||ilhaBi[linha][coluna-1]->getTipoZona() == "flr"
               &&ilhaBi[linha][coluna-1]->HaveProduceThisDay()) {
                return true;
            }
        }
        return false;
    }

    void vendeRecurso(const string type, const float quant) {
        if (quant > 0) {
            if (type == "ferro") {
                if (recursos->getFerro() >= quant) {
                    cout << "Pretende vender " << quant << " kg de Ferro por " << quant * 1 << " euros(S/N)? ";
                    char resp;
                    cin >> resp;
                    if (resp == 'S') {
                        recursos->withdrawFerro(quant);
                        recursos->addMoney(quant * 1);
                        cout << endl;
                        cout << quant * 1 << " euros recebidos." << endl;
                    }
                } else {
                    cout << "Nao tem essa quantidade de Ferro para vender." << endl;
                }
            } else if (type == "aco") {
                if (recursos->getBarraAco() >= quant) {
                    cout << "Pretende vender " << quant << "  de Aco por " << quant * 2 << " euros(S/N)? ";
                    char resp;
                    cin >> resp;
                    if (resp == 'S') {
                        recursos->withdrawAco(quant);
                        recursos->addMoney(quant * 2);
                        cout << endl;
                        cout << quant * 2 << " euros recebidos." << endl;
                    }
                } else {
                    cout << "Nao tem essa quantidade de Aco para vender." << endl;
                }
            } else if (type == "carvao") {
                if (recursos->getCarvao() >= quant) {
                    cout << "Pretende vender " << quant << " kg de Carvao por " << quant * 1 << " euros(S/N)? ";
                    char resp;
                    cin >> resp;
                    if (resp == 'S') {
                        recursos->withdrawCarvao(quant);
                        recursos->addMoney(quant * 1);
                        cout << endl;
                        cout << quant * 1 << " euros recebidos." << endl;
                    }
                } else {
                    cout << "Nao tem essa quantidade de Carvao para vender." << endl;
                }
            } else if (type == "mad") {
                if (recursos->getMadeira() >= quant) {
                    cout << "Pretende vender " << quant << " kg de Madeira por " << quant * 1 << " euros(S/N)? ";
                    char resp;
                    cin >> resp;
                    if (resp == 'S') {
                        recursos->withdrawMadeira(quant);
                        recursos->addMoney(quant * 1);
                        cout << endl;
                        cout << quant * 1 << " euros recebidos." << endl;
                    }
                } else {
                    cout << "Nao tem essa quantidade de Madeira para vender." << endl;
                }
            } else if (type == "viga") {
                if (recursos->getVigaMadeira() >= (int)quant) {
                    cout << "Pretende vender " << (int)quant << "  de Viga por " << (int)quant * 2 << " euros(S/N)? ";
                    char resp;
                    cin >> resp;
                    if (resp == 'S') {
                        recursos->withdrawVigas((int)quant);
                        recursos->addMoney((int)quant * 2);
                        cout << endl;
                        cout << (int)quant * 2 << " euros recebidos." << endl;
                    }
                } else {
                    cout << "Nao tem essa quantidade de Viga para vender." << endl;
                }
            } else if (type == "eletr") {
                if (recursos->getEletricidade() >= quant) {
                    cout << "Pretende vender " << quant << "  KWh de Eletricidade por " << quant * 1.5
                         << " euros(S/N)? ";
                    char resp;
                    cin >> resp;
                    if (resp == 'S') {
                        recursos->withdrawEletr(quant);
                        recursos->addMoney(quant * 1.5);
                        cout << endl;
                        cout << quant * 1.5 << " euros recebidos." << endl;
                    }
                } else {
                    cout << "Nao tem essa quantidade de Eletricidade para vender." << endl;
                }
            } else {
                cout << "Tipo de Recurso invalido." << endl;
            }
        } else {
            cout << "Quantidade invalida." << endl;
        }
    }

    bool HaveMnAround(const int linha, const int coluna) const{

        if(coluna > 0 && coluna < this->colunas-1 && linha > 0 && linha < this->linhas-1){
               if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC" // à esquerda e direita
               && ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF") {
                   return true;
               }
               else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               && ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                   return true;
               }
               else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               && ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF") {
                   return true;
               }
               else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               && ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"){
                   return true;
               } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                         ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                         ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                         ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
                   return true;
               }
        } else if(linha == 0 && coluna > 0 && coluna < this->colunas-1) {
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
              &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
              ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
              &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
              ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
              ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
              ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
              ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
              &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                     return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                     ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                     ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec") {
                                return true;
                   }
        }  else if(linha == 0 && coluna == 0) {
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
                      &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(coluna == 0 && linha > 0 && linha < this->linhas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
             &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
             &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(coluna == 0 && linha == this->linhas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
             &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
             ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna > 0 && coluna < this->colunas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha][coluna+1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "elec"
                    ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"){
                return true;
            }
        } else if(linha == 0 && coluna == this->colunas-1) {
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
                      &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(coluna == this->colunas-1 && linha > 0 && linha < this->linhas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnF"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF"
               &&ilhaBi[linha+1][coluna]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "elec") {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna == this->colunas-1) {
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnC"
               &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnF") {
                return true;
            } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "mnF"
                      &&ilhaBi[linha][coluna-1]->getTipoEdificio() == "mnC") {
                return true;
            } else if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "elec"
                      ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "elec") {
                return true;
            }
        }
        return false;
    }

    bool HavebatAround(const int linha, const int coluna) const{

        if(coluna > 0 && coluna < this->colunas-1 && linha > 0 && linha < this->linhas-1){
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna-1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna+1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha-1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha+1][coluna]->CapMaxReach((*e).getTipoEdificio())){
                return true;
            }
        } else if(linha == 0 && coluna > 0 && coluna < this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha+1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna-1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna+1]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        } else if(linha == 0 && coluna == 0) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha+1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna+1]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        } else if(coluna == 0 && linha > 0 && linha < this->linhas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna+1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna+1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha-1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha+1][coluna]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        } else if(coluna == 0 && linha == this->linhas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha-1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna+1]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna > 0 && coluna < this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna-1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna+1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha-1][coluna]->CapMaxReach((*e).getTipoEdificio())){
                return true;
            }
        } else if(linha == 0 && coluna == this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha+1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna-1]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        } else if(coluna == this->colunas-1 && linha > 0 && linha < this->linhas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna-1]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha-1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha+1][coluna]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna == this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "bat"
               && !ilhaBi[linha-1][coluna]->CapMaxReach((*e).getTipoEdificio())
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "bat"
               && !ilhaBi[linha][coluna-1]->CapMaxReach((*e).getTipoEdificio())) {
                return true;
            }
        }
        return false;
    }

    bool HavebarragemAround(const int linha, const int coluna) const{

        if(coluna > 0 && coluna < this->colunas-1 && linha > 0 && linha < this->linhas-1){
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "barg"){
                return true;
            }
        } else if(linha == 0 && coluna > 0 && coluna < this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "barg") {
                return true;
            }
        } else if(linha == 0 && coluna == 0) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "barg") {
                return true;
            }
        } else if(coluna == 0 && linha > 0 && linha < this->linhas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna+1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "barg") {
                return true;
            }
        } else if(coluna == 0 && linha == this->linhas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "barg") {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna > 0 && coluna < this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna+1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "barg"){
                return true;
            }
        } else if(linha == 0 && coluna == this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha+1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "barg") {
                return true;
            }
        } else if(coluna == this->colunas-1 && linha > 0 && linha < this->linhas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha][coluna-1]->getTipoEdificio() == "barg"
               ||ilhaBi[linha-1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha+1][coluna]->getTipoEdificio() == "barg") {
                return true;
            }
        } else if(linha == this->linhas-1 && coluna == this->colunas-1) {
            auto e = ilhaBi[linha][coluna];
            if(ilhaBi[linha-1][coluna]->getTipoEdificio() == "barg"
               ||ilhaBi[linha][coluna-1]->getTipoEdificio() == "barg") {
                return true;
            }
        }
        return false;
    }

    void contWorker(const string t) {
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                if (ilhaBi[i][j]->getTipoZona() == "pas") {
                    ilhaBi[i][j]->addTrabalhador(t,getDay());
                    find = true;
                }
                if(find){break;}
            }
            if(find){break;}
        }
        find=false;
    }

    void newDay(){
        dia++;
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                ilhaBi[i][j]->newDay();
            }
        }
    }

    void produzir() {
        for(int i=0; i<ilhaBi.size(); i++) {
            for(int j=0; j<ilhaBi[i].size();j++) {
                ilhaBi[i][j]->produzir();
            }
        }
    }

    void lvlUpEdi(const int linha, const int coluna) {
        ilhaBi[linha-1][coluna-1]->lvlEdi();
    }

    int getDay() const{
        return dia;
    }

    void moveWorker(const int id,const int linha, const int coluna) {
        if(ilhaBi[linha-1][coluna-1]->iHaveThisId(id)){
            find=true;
            cout << "Trabalhador ja se encontra na Zona pretendida." << endl;
        }
        if(!find) {
            for (int i = 0; i < ilhaBi.size(); i++) {
                for (int j = 0; j < ilhaBi[i].size(); j++) {
                    if (ilhaBi[i][j]->iHaveThisId(id)) {
                        find = true;
                        auto e = ilhaBi[i][j];
                        ilhaBi[linha - 1][coluna - 1]->moveToHere((*e).passWorkerRef(id));
                        (*e).removeWorker(id);
                    }
                }
            }
        }
        if(!find){
            cout << "Id inexistente..." << endl;
        }
        find = false;
    }

    void listZona(const int linha, const int coluna){
        cout << ilhaBi[linha-1][coluna-1]->getAsString();
    }

    void vendeEdificio(const int linha, const int coluna){
        ilhaBi[linha-1][coluna-1]->vendeEdificio();
    }

    void ligaEdi(const int linha, const int coluna){
        ilhaBi[linha-1][coluna-1]->ligaEdi();
    }

    void desligaEdi(const int linha, const int coluna){
        ilhaBi[linha-1][coluna-1]->desligaEdi();
    }

    void addEdi(const string tipo,const int linha, const int coluna) {
        ilhaBi[linha-1][coluna-1]->addEdificio(tipo);
    }

    void showIlha();

    void showIlha2();

    int random_l_h(const int min, const int max) {
        return min + rand() % (max-min+1);
    }


};
#endif //PRATICOTRABALHO_ILHA_H