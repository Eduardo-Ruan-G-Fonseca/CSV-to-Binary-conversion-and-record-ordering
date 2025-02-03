/*
Trabalho feito por Eduardo Ruan, Lucas Oliveira, Matheus Megale - Grupo 11
Grupo 11, lms-jun22qtr-csv.7z, Atributos: Period (primário), Data_value (secundário), ordenação crescente
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Arquivo{
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

bool comparar_registros(const Arquivo& a, const Arquivo& b) {
  int comparacaoPeriod = strcmp(a.Period, b.Period);
  if (comparacaoPeriod != 0) {
    return comparacaoPeriod < 0;
  } else {
    return strcmp(a.Data_value, b.Data_value) < 0;
  }
}

void quick_sort(Arquivo* registros, int inicio, int fim) {
  if (inicio < fim) {
    Arquivo pivo = registros[fim];
    int i = inicio - 1;
    for (int j = inicio; j <= fim - 1; j++) {
      if (comparar_registros(registros[j], pivo)) {
        i++;
        swap(registros[i], registros[j]);
      }
    }
    swap(registros[i + 1], registros[fim]);
    int p = i + 1;
    quick_sort(registros, inicio, p - 1);
    quick_sort(registros, p + 1, fim);
  }
}

void mergeSortBloco(ifstream& entrada, ofstream& saida, int inicio, int fim) {

    int tamanho = fim - inicio + 1;
    Arquivo* registros = new Arquivo[tamanho];
    entrada.seekg(inicio * sizeof(Arquivo));
    for (int i = 0; i < tamanho; i++) {
        entrada.read(reinterpret_cast<char*>(&registros[i]), sizeof(Arquivo));
    }
    quick_sort(registros, 0, tamanho - 1);
    for (int i = 0; i < tamanho; i++) {
        saida.write(reinterpret_cast<const char*>(&registros[i]), sizeof(Arquivo));
    }
    delete[] registros;
}

void merge(int inicio, int meio, int fim) {

    ifstream entrada1("temp.dat", ios::binary);
    ofstream saida("merge.dat", ios::binary);
    int i = inicio;
    int j = meio + 1;
    while (i <= meio and j <= fim) {
        Arquivo regs1, regs2;
        entrada1.seekg(i * sizeof(Arquivo));
        entrada1.read(reinterpret_cast<char*>(&regs1), sizeof(Arquivo));
        entrada1.seekg(j * sizeof(Arquivo));
        entrada1.read(reinterpret_cast<char*>(&regs2), sizeof(Arquivo));
        if (comparar_registros(regs1, regs2)) {
        saida.write(reinterpret_cast<const char*>(&regs1), sizeof(Arquivo)); // Escrever o menor elemento no arquivo "merge.dat"
        i++;
        } else {
        saida.write(reinterpret_cast<const char*>(&regs2), sizeof(Arquivo));
        j++;
        }
    }
    while (i <= meio) {
        Arquivo regs1;
        entrada1.seekg(i * sizeof(Arquivo));
        entrada1.read(reinterpret_cast<char*>(&regs1), sizeof(Arquivo));
        saida.write(reinterpret_cast<const char*>(&regs1), sizeof(Arquivo));
        i++;
    }
    while (j <= fim) {
        Arquivo regs2;
        entrada1.seekg(j * sizeof(Arquivo));
        entrada1.read(reinterpret_cast<char*>(&regs2), sizeof(Arquivo));
        saida.write(reinterpret_cast<const char*>(&regs2), sizeof(Arquivo));
        j++;
    }

    entrada1.close();
    saida.close();
    ifstream entrada2("merge.dat", ios::binary);
    ofstream temp("lms-jun22qtr-csv_binario.dat", ios::binary | ios::app);
    for (int i = inicio; i <= fim; i++) {
        Arquivo regs;
        entrada2.read(reinterpret_cast<char*>(&regs), sizeof(Arquivo));
        temp.write(reinterpret_cast<const char*>(&regs), sizeof(Arquivo));
    }
    entrada2.close();
    temp.close();
}

void atualizaTemp(){
  ifstream entradaTemp("lms-jun22qtr-csv_binario.dat", ios::binary);
  ofstream temp("temp.dat", ios::binary);
  Arquivo registro;
  while(entradaTemp.read(reinterpret_cast<char *>(&registro), sizeof(Arquivo))){
    temp.write(reinterpret_cast<const char*>(&registro), sizeof(Arquivo));
  }
  entradaTemp.close();
  temp.close();
  ofstream arquivo("lms-jun22qtr-csv_binario.dat", ios::binary | ios::trunc);
  arquivo.close();
}

void mergeSort(ifstream& entrada, ofstream& saida, int num_registros, int tamanho_bloco) {
    for (int i = 0; i < num_registros; i += tamanho_bloco) {
        int fim = min(i + tamanho_bloco - 1, num_registros - 1);
        mergeSortBloco(entrada, saida, i, fim);
    }
    entrada.close();
    saida.close();

    int tam = tamanho_bloco;
    while (tam < num_registros) {
        int inicio = 0;
        while (inicio < num_registros) {
        int meio = inicio + tam - 1;
        int fim =  min(inicio + 2 * tam - 1, num_registros - 1);
        merge(inicio, meio, fim);
        inicio = inicio + 2 * tam;
        }
        tam = tam * 2;
        atualizaTemp();
    }
}

void imprimir(){
    ifstream entrada("temp.dat", ios::in | ios::binary);
    Arquivo registro;
    cout << endl;

    while (entrada.read(reinterpret_cast<char *>(&registro), sizeof(Arquivo)))
    {
        cout << "Series reference: " << registro.Series_reference << ",";
        cout << "Period: " << registro.Period << ",";
        cout << "Data value: " << registro.Data_value << ",";
        cout << "STATUS: " << registro.STATUS << ",";
        cout << "UNTIS: " << registro.UNITS << ",";
        cout << "MAGNTUDE: " << registro.MAGNTUDE << ",";
        cout << "Subject: " << registro.Subject << ",";
        cout << "Group: " << registro.Group << ",";
        cout << "Series_title_1: " << registro.Series_title_1 << ",";
        cout << "Series_title_2: " << registro.Series_title_2 << ",";
        cout << "Series_title_3: " << registro.Series_title_3 << ",";
        cout << "Series_title_4: " << registro.Series_title_4 << ",";
        cout << "Series_title_5: " << registro.Series_title_5 << endl;
    }

    cout << endl;
    entrada.close();
}

void criarCSV(){
    ifstream arquivo;
    arquivo.open("temp.dat", ios::binary);
    ofstream saida("ArquivoOrdenado.csv");
    Arquivo registro;
    int cont = 0;
    while (arquivo.read((char *) (&registro),sizeof(Arquivo))){
        cout << "Carregando linha " << cont << endl;
        saida << registro.Series_reference << ",";
        saida << registro.Period << ",";
        saida << registro.Data_value << ",";
        saida << registro.STATUS << ",";
        saida << registro.UNITS << ",";
        saida << registro.MAGNTUDE << ",";
        saida << registro.Subject << ",";
        saida << registro.Group << ",";
        saida << registro.Series_title_1 << ",";
        saida << registro.Series_title_2 << ",";
        saida << registro.Series_title_3 << ",";
        saida << registro.Series_title_4 << ",";
        saida << registro.Series_title_5 << endl;
        cont++;
    }
    arquivo.close();
    saida.close();
}

int main(){
    ifstream entrada("lms-jun22qtr-csv_binario.dat", ios::binary);
    ofstream saida("temp.dat", ios::binary);
    char resposta, respostaCSV;
    if(entrada){

      entrada.seekg(0, ios::end);
      int num_registros = entrada.tellg() / sizeof(Arquivo);
      entrada.seekg(0, ios::beg);
      int tamanho_bloco = 12640;
      cout << "Aguarde o fim da ordenação, isso pode levar alguns minutos ..." << endl;
      mergeSort(entrada, saida, num_registros, tamanho_bloco); 
      cout << " Ordenado com sucesso !! Deseja Imprimir o arquivo ordenado ? S/N ";
      cin >> resposta;
      if(resposta=='s' or resposta =='S'){
        imprimir();
      }
      cout << " Deseja criar um arquivo CSV com os dados ordenados ? S/N ";
      cin >> respostaCSV;
      if(respostaCSV == 's' or 'S'){
        criarCSV();
      }
    }else{
      cerr << "ARQUIVO NÃO FOI ABERTO CORRETAMENTE";
    }
    entrada.close();
    saida.close(); 
 
}
