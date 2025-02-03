/*Trabalho feito por Eduardo Ruan, Lucas Oliveira, Matheus Megale - Grupo 11
Converção do arquivo CSV (.csv) para arquivo bninário (.dat)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

struct registro{
    char Series_reference[30];
    char Period[15];
    char Data_value[15];
    char STATUS[15];
    char UNITS[15];
    int MAGNTUDE;
    char Subject[200];
    char Group[100];
    char Series_title_1[50];
    char Series_title_2[50];
    char Series_title_3[50];
    char Series_title_4[50];
    char Series_title_5[50];
};

int main(){
	ifstream entrada;
    entrada.open("lms-jun22qtr-csv.csv");
	ofstream saida("lms-jun22qtr-csv_binario.dat", ios::binary);
    string linha;
    registro campo;
    int cont = 1;

	if (!entrada){
        cout << "Erro ao abrir o arquivo de entrada" << endl;
    return 1;
    }else{
        getline(entrada,linha); // o cabeçalho não entra
        while(getline(entrada,linha)){
            cout << "Lendo linha " << cont << " !" << endl;
            stringstream linhastream(linha);
            string item;

            getline(linhastream, item, ',');
            strcpy(campo.Series_reference, item.c_str());

            getline(linhastream, item, ',');
            strcpy(campo.Period, item.c_str());

            getline(linhastream, item, ',');
            strcpy(campo.Data_value, item.c_str());

            getline(linhastream, item, ',');
            strcpy(campo.STATUS, item.c_str());

            getline(linhastream, item, ',');
            strcpy(campo.UNITS, item.c_str());

            getline(linhastream, item, ',');
            campo.MAGNTUDE = stoi(item);

            getline(linhastream, item, ',');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Subject, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Subject, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Subject, item.c_str());
            }

            getline(linhastream, item, ',');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Group, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Group, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Group, item.c_str());
            }

            getline(linhastream, item, ',');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_1, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_1, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Series_title_1, item.c_str());
            }

            getline(linhastream, item, ',');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_2, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_2, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Series_title_2, item.c_str());
            }

            getline(linhastream, item, ',');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_3, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_3, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Series_title_3, item.c_str());
            }

            getline(linhastream, item, ',');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_4, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_4, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Series_title_4, item.c_str());
            }

            getline(linhastream, item, '\n');
            if(item[0] == '\''){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\'') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_5, auxiliar.c_str());
            }
            else if(item[0] == '\"'){
                string auxiliar = item;
                    bool terminouCampo = false;
                    while(!terminouCampo) {
                        getline(linhastream, item, ',');
                        auxiliar += "," + item;
                        if(item[item.size()-1] == '\"') {
                            terminouCampo = true;
                        }
                    }
                    strcpy(campo.Series_title_5, auxiliar.c_str());
            }
            else {
                    strcpy(campo.Series_title_5, item.c_str());
            }

            saida.write((const char *) (&campo), sizeof(registro));
            cont++;

        }
        cout << "Arquivo convertido!";
        cout << "\nForam lidas " << cont << " linhas!" << endl;

    }
    entrada.close();
    saida.close();
return 0;
}