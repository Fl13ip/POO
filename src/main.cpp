#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Ilha.h"


int main() {





    int linha;
    int coluna;
    int id;
    int option;
    float quant;
    string tipo;
    bool go=false;
    fstream file2;


while(!go) {
    cout << "Que tamanho deseja dar a ilha? (3x3 - 8x16)" << endl;
    cout << "N de Linhas-> ";
    cin >> linha;
    cout << "N de Colunas-> ";
    cin >> coluna;
    if(linha < 3 || linha > 8 || coluna < 3 || coluna > 16){
        cout << "Dimensoes indesponiveis." << endl;
    } else {
        go = true;
    }
}

    Ilha I(linha,coluna);


    I.showIlha();
    char comand[100];
    string args[4];
    while(args[0] != "exit"){
        //I.showIlha();
        fflush(stdin);
        cout << "Digite um comando: ";
        cin.getline(comand,100);

        char *ptr;
        ptr = strtok(comand," , ");

        int i=0, argCount=0;
        while(ptr != NULL) {

            args[i] = ptr;
            ptr = strtok(NULL," , ");
            i++;
            argCount++;
        }

        if(args[0] == "next") {
            if(argCount == 1){
                cout << "Novo Dia!" << endl;
                I.produzir();
                I.newDay();
                I.showIlha();
            } else {
                cout << "Demasiados argumentos" << endl;
            }
        } else if(args[0] == "cont"){
            if(argCount == 2){
                if(args[1] == "len" || args[1] == "oper" || args[1] == "miner") {
                    I.contWorker(args[1]);
                    I.showIlha();
                } else {
                    cout << "Tipo de Trabalhador desconhecido" << endl;
                }
            } else if(argCount < 2){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "liga") {
            if(argCount == 3) {
                stringstream geek(args[1]);
                stringstream geek2(args[2]);
                int x,y;
                geek >> x;
                geek2 >> y;
                if(x <= linha && y <= coluna && x > 0 && y > 0){
                    I.ligaEdi(x,y);
                    I.showIlha();
                } else {
                    cout << "Dimensoes nao permitidas." << endl;
                }
            } else if(argCount < 3){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "cons") {
            if(argCount == 4) {
                if(args[1] == "barg" || args[1] == "elec"
                || args[1] == "mnC" || args[1] == "mnF"
                || args[1] == "fun" || args[1] == "serra"
                || args[1] == "bat") {

                    stringstream geek(args[2]);
                    stringstream geek2(args[3]);
                    int x,y;
                    geek >> x;
                    geek2 >> y;
                    if(x <= linha && y <= coluna && x > 0 && y > 0) {
                        I.addEdi(args[1],x,y);
                        I.showIlha();
                    } else {
                        cout << "Dimensoes nao permitidas." << endl;
                    }
                } else {
                    cout << "Tipo de Edificio desconhecido." << endl;
                }
            } else if(argCount < 4) {
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }

        } else if(args[0] == "des") {
            if(argCount == 3) {
                stringstream geek(args[1]);
                stringstream geek2(args[2]);
                int x,y;
                geek >> x;
                geek2 >> y;
                if(x <= linha && y <= coluna && x > 0 && y > 0){
                    I.desligaEdi(x,y);
                    I.showIlha();
                } else {
                    cout << "Dimensoes nao permitidas." << endl;
                }
            } else if(argCount < 3){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "move") {
            if(argCount == 4) {

                stringstream geek(args[1]);
                stringstream geek2(args[2]);
                stringstream geek3(args[3]);
                int x,y,z;
                geek >> x;
                geek2 >> y;
                geek3 >> z;
                if(x <= 0) {
                    cout << "Id indesponivel." << endl;
                } else {
                    if(y <= linha && z <= coluna && y > 0 && z > 0) {
                        I.moveWorker(x, y, z);
                        I.showIlha();
                    } else {
                        cout << "Dimensoes nao permitidas." << endl;
                    }
                }
            } else if(argCount < 4){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "vende"){
            if(argCount == 3){
                stringstream geek(args[1]);
                stringstream geek2(args[2]);
                int x,y;
                geek >> x;
                geek2 >> y;
                if(x != 0 && y != 0){
                    if(x <= linha && y <= coluna && x > 0 && y > 0){
                        I.vendeEdificio(x,y);
                        I.showIlha();
                    } else {
                        cout << "Dimensoes nao permitidas." << endl;
                    }
                } else if(args[1] == "ferro" || args[1] == "carvao"
                        || args[1] == "mad" || args[1] == "viga"
                        || args[1] == "eletr") {

                    stringstream geek3(args[2]);
                    geek3 >> x;
                    if(x > 0) {
                        I.vendeRecurso(args[1],x);
                        I.showIlha();
                    } else {
                        cout << "A quantidade tem de ser superior a 0." << endl;
                    }
                } else{
                    cout << "Tipo de recurso desconhecido." << endl;
                }
            } else if(argCount < 3){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "list") {
            if(argCount == 3) {
                stringstream geek(args[1]);
                stringstream geek2(args[2]);
                int x,y;
                geek >> x;
                geek2 >> y;
                if(x <= linha && y <= coluna && x > 0 && y > 0){
                    I.listZona(x, y);
                    I.showIlha();
                } else {
                    cout << "Dimensoes nao permitidas." << endl;
                }
            } else if(argCount < 3){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "save") {
            if(argCount == 2){
                stringstream geek(args[1]);
                int x;
                geek >> x;
                if(x != 0){
                    cout << "Nome do ficheiro indesponivel." << endl;
                } else {
                    cout << "Save Ficheiro." << endl;
                    cout << "Nome do Ficheiro -> " << args[1] << endl;
                }
            } else if(argCount < 2){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if(args[0] == "exec"){
            if(argCount == 2){
                stringstream geek(args[1]);
                int x;
                geek >> x;
                if(x != 0){
                    cout << "Nome do ficheiro indesponivel." << endl;
                } else {
                }
            } else if(argCount < 2){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        } else if (args[0] == "config") {
            file2.open("Config.txt", ios::in); //read
            if (file2.is_open()) {
                string linhafich;
                while (getline(file2, linhafich)) {
                    cout << linhafich << endl;

                }
                file2.close();
            }
        }else if(args[0] == "upgrade") {
            if(argCount == 3) {
                stringstream geek(args[1]);
                stringstream geek2(args[2]);
                int x,y;
                geek >> x;
                geek2 >> y;
                if(x <= linha && y <= coluna && x > 0 && y > 0){
                    I.lvlUpEdi(x,y);
                    I.showIlha();
                } else {
                    cout << "Dimensoes nao permitidas." << endl;
                }
            } else if(argCount < 3){
                cout << "Faltam argumentos para executar este comando." << endl;
            } else {
                cout << "Demasiados argumentos." << endl;
            }
        }

    }
}
