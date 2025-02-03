/*Trabalho feito por Eduardo Ruan, Lucas Oliveira, Matheus Megale - Grupo 11
Manipulações como adicinar dados, visualizar trechos, alterar dados, trocar dados de lugar, e impressão completa;
*/

#include <iostream>
#include <fstream>

using namespace std;


class Arquivo{
    private:
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
    public:
    void adicionarElemento();
    void visualizar();
    void alterarDados();
    void trocarElementos();
    void imprimeTudo();
};

void Arquivo::adicionarElemento(){
    fstream arquivo;
    Arquivo dados;

    cout << "Digite como deseja inserir!" << endl;
    cout << "Para inserir no INICIO, digite 'I'" << endl;
    cout << "Para inserir no FIM, digite 'F'" << endl;
    cout << "Para inserir em uma posição específica, digite 'P'" << endl;
    char digite;
    cin >> digite;
    if((digite == 'I') or (digite == 'i')){
        arquivo.open("lms-jun22qtr-csv_binario.dat", ios::binary | ios::out | ios::in);

        if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        }

        cout << "Preencha o resgistro" << endl;
        cout << "Series reference:" << endl;
        cin >> dados.Series_reference;
        cout << "Period:" << endl;
        cin >> dados.Period;
        cout << "Data value:" << endl;
        cin >> dados.Data_value;
        cout << "Status:" << endl;
        cin >> dados.STATUS;
        cout << "Units:" << endl;
        cin >> dados.UNITS;
        cout << "Magntude:" << endl;
        cin >> dados.MAGNTUDE;
        cout << "Subject:" << endl;
        cin.ignore();
        cin.getline(dados.Subject,200);
        cout << "Group:" << endl;
        cin.getline(dados.Group,100);
        cout << "Series title 1:" << endl;
        cin.getline(dados.Series_title_1,50);
        cout << "Series title 2:" << endl;
        cin.getline(dados.Series_title_2,50);
        cout << "Series title 3:" << endl;
        cin.getline(dados.Series_title_3,50);
        cout << "Series title 4:" << endl;
        cin.getline(dados.Series_title_4,50);
        cout << "Series title 5:" << endl;
        cin.getline(dados.Series_title_5,50);

        int tamanhoRegistro = sizeof(Arquivo);
        long long int tamanhoArquivo = 0;
        arquivo.seekg(0, ios::end);
        tamanhoArquivo = arquivo.tellg();

        for (int i = tamanhoArquivo - tamanhoRegistro; i >= 0; i -= tamanhoRegistro) {
            arquivo.seekg(i);
            Arquivo registro;
            arquivo.read(reinterpret_cast<char*>(&registro), tamanhoRegistro);
            arquivo.seekg(i + tamanhoRegistro);
            arquivo.write(reinterpret_cast<const char*>(&registro), tamanhoRegistro);
        }

        arquivo.seekp(0);
        arquivo.write(reinterpret_cast<const char*>(&dados), tamanhoRegistro);

        arquivo.close();

        cout << "Registro inserido com sucesso." << endl;
    }
    else if((digite == 'F') or (digite == 'f')){
        arquivo.open("lms-jun22qtr-csv_binario.dat", ios::binary | ios::in | ios::out | ios::app);

        if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        }

        cout << "Preencha o resgistro" << endl;
        cout << "Series reference:" << endl;
        cin >> dados.Series_reference;
        cout << "Period:" << endl;
        cin >> dados.Period;
        cout << "Data value:" << endl;
        cin >> dados.Data_value;
        cout << "Status:" << endl;
        cin >> dados.STATUS;
        cout << "Units:" << endl;
        cin >> dados.UNITS;
        cout << "Magntude:" << endl;
        cin >> dados.MAGNTUDE;
        cout << "Subject:" << endl;
        cin.ignore();
        cin.getline(dados.Subject,200);
        cout << "Group:" << endl;
        cin.getline(dados.Group,100);
        cout << "Series title 1:" << endl;
        cin.getline(dados.Series_title_1,50);
        cout << "Series title 2:" << endl;
        cin.getline(dados.Series_title_2,50);
        cout << "Series title 3:" << endl;
        cin.getline(dados.Series_title_3,50);
        cout << "Series title 4:" << endl;
        cin.getline(dados.Series_title_4,50);
        cout << "Series title 5:" << endl;
        cin.getline(dados.Series_title_5,50);

        arquivo.write(reinterpret_cast<const char*>(&dados), sizeof(Arquivo));

        arquivo.close();

        cout << "Registro adicionado no final do arquivo." << endl;
    }
    else if((digite == 'P') or (digite == 'p')){
        arquivo.open("lms-jun22qtr-csv_binario.dat", ios::binary | ios::in | ios::out);

        if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        }

        cout << "Digite a posição que deseja realizar a inserção no arquivo." << endl;
        int tamanhoRegistro = sizeof(Arquivo);
        long long tamanhoArquivo = 0;
        arquivo.seekg(0, ios::end);
        tamanhoArquivo = arquivo.tellg();
        cout << "Lembrando que a posição não pode ser menor que 0 e nem maior que o tamanho do arquivo, que atulamente é " <<  tamanhoArquivo/tamanhoRegistro-1 << endl;
        int posicao;
        cin >> posicao;
        if ((posicao >= 0) and (posicao <= tamanhoArquivo / tamanhoRegistro)) {
            for (int i = tamanhoArquivo - tamanhoRegistro; i >= posicao * tamanhoRegistro; i -= tamanhoRegistro) {
                arquivo.seekg(i);
                Arquivo registro;
                arquivo.read(reinterpret_cast<char*>(&registro), tamanhoRegistro);
                arquivo.seekp(i + tamanhoRegistro);
                arquivo.write(reinterpret_cast<const char*>(&registro), tamanhoRegistro);
            }
            arquivo.seekp(posicao * tamanhoRegistro);
            
            cout << "Preencha o resgistro" << endl;
            cout << "Series reference:" << endl;
            cin >> dados.Series_reference;
            cout << "Period:" << endl;
            cin >> dados.Period;
            cout << "Data value:" << endl;
            cin >> dados.Data_value;
            cout << "Status:" << endl;
            cin >> dados.STATUS;
            cout << "Units:" << endl;
            cin >> dados.UNITS;
            cout << "Magntude:" << endl;
            cin >> dados.MAGNTUDE;
            cout << "Subject:" << endl;
            cin.ignore();
            cin.getline(dados.Subject,200);
            cout << "Group:" << endl;
            cin.getline(dados.Group,100);
            cout << "Series title 1:" << endl;
            cin.getline(dados.Series_title_1,50);
            cout << "Series title 2:" << endl;
            cin.getline(dados.Series_title_2,50);
            cout << "Series title 3:" << endl;
            cin.getline(dados.Series_title_3,50);
            cout << "Series title 4:" << endl;
            cin.getline(dados.Series_title_4,50);
            cout << "Series title 5:" << endl;
            cin.getline(dados.Series_title_5,50);

            arquivo.write(reinterpret_cast<const char*>(&dados), tamanhoRegistro);

            cout << "Registro inserido na posição " << posicao << "." << endl;
        } else {
            cout << "Posição inválida." << endl;
        }

        arquivo.close();


    }

}

void Arquivo::visualizar(){
    Arquivo dados;
    ifstream arquivo;
    arquivo.open("lms-jun22qtr-csv_binario.dat", ios::binary);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
    }

     arquivo.seekg(0, ios::end);
    long long int tamanhoArquivo = arquivo.tellg();
    int tamanhoRegistro = sizeof(Arquivo);

    int posicaoInicial, posicaoFinal;
    cout << "Digite a posição inicial que do trecho será impresso" << endl;
    cout << "Lembrando quea posição inicial não pode ser menor que 0 e" << endl;
    cout << "a posição final não pode ser menor que o tamanho do arquivo, que nesse momento é " << tamanhoArquivo / tamanhoRegistro -1 << endl;
    cin >> posicaoInicial;
    cout << "Digite a posição final que do trecho que será impresso" << endl;
    cin >> posicaoFinal;


    if ((posicaoInicial >= 0) and (posicaoInicial < tamanhoArquivo / tamanhoRegistro) and (posicaoFinal >= posicaoInicial) and (posicaoFinal < tamanhoArquivo / tamanhoRegistro)) {

        arquivo.seekg(posicaoInicial * tamanhoRegistro);
        int numRegistros = posicaoFinal - posicaoInicial +1;


        for (int i = 0; i < numRegistros; i++) {
           
            arquivo.read(reinterpret_cast<char*>(&dados), tamanhoRegistro);

            cout << "Registro " << posicaoInicial + i << ":" << endl;
            cout << "Series reference:" << dados.Series_reference << ",";
            cout << "Period:" << dados.Period << ",";
            cout << "Data value:" << dados.Data_value << ",";
            cout << "Status:" << dados.STATUS << ",";
            cout << "Units:" << dados.UNITS << ",";
            cout << "Magnitude:" << dados.MAGNTUDE << ",";
            cout << "Subject:" << dados.Subject << ",";
            cout << "Group:" << dados.Group << ",";
            cout << "Series title 1:" << dados.Series_title_1 << ",";
            cout << "Series title 2:" << dados.Series_title_2 << ",";
            cout << "Series title 3:" << dados.Series_title_3 << ",";
            cout << "Series title 4:" << dados.Series_title_4 << ",";
            cout << "Series title 5:" << dados.Series_title_5 << endl;
        }

    }
    else {
        cout << "Posições inválidas." << endl;
    }
    arquivo.close();
}

void Arquivo::alterarDados(){
    fstream arquivo;
    Arquivo dados;

    arquivo.open("lms-jun22qtr-csv_binario.dat", ios::binary | ios::in | ios::out);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    int posicaoAlterar;

    arquivo.seekg(0, ios::end);
    long long int tamanhoArquivo = arquivo.tellg();
    int tamanhoRegistro = sizeof(Arquivo);

    cout << "Digite a posição do elemento que deseja alterar os dados" << endl;
    cout << "Lembrando que o intervalo de posiçõs válidas é de 0 à " << tamanhoArquivo / tamanhoRegistro << endl;
    cin >> posicaoAlterar;

    if ((posicaoAlterar >= 0) and (posicaoAlterar < tamanhoArquivo / tamanhoRegistro)) {
        arquivo.seekp(posicaoAlterar * tamanhoRegistro);
        arquivo.read(reinterpret_cast<char*>(&dados), tamanhoRegistro);

        cout << "Registro atual na posição " << posicaoAlterar << ":" << endl;
        cout << "Series reference:" << dados.Series_reference << ",";
        cout << "Period:" << dados.Period << ",";
        cout << "Data value:" << dados.Data_value << ",";
        cout << "Status:" << dados.STATUS << ",";
        cout << "Units:" << dados.UNITS << ",";
        cout << "Magnitude:" << dados.MAGNTUDE << ",";
        cout << "Subject:" << dados.Subject << ",";
        cout << "Group:" << dados.Group << ",";
        cout << "Series title 1:" << dados.Series_title_1 << ",";
        cout << "Series title 2:" << dados.Series_title_2 << ",";
        cout << "Series title 3:" << dados.Series_title_3 << ",";
        cout << "Series title 4:" << dados.Series_title_4 << ",";
        cout << "Series title 5:" << dados.Series_title_5 << endl;

        cout << "Preencha o resgistro" << endl;
        cout << "Series reference:" << endl;
        cin >> dados.Series_reference;
        cout << "Period:" << endl;
        cin >> dados.Period;
        cout << "Data value:" << endl;
        cin >> dados.Data_value;
        cout << "Status:" << endl;
        cin >> dados.STATUS;
        cout << "Units:" << endl;
        cin >> dados.UNITS;
        cout << "Magntude:" << endl;
        cin >> dados.MAGNTUDE;
        cout << "Subject:" << endl;
        cin.ignore();
        cin.getline(dados.Subject,200);
        cout << "Group:" << endl;
        cin.getline(dados.Group,100);
        cout << "Series title 1:" << endl;
        cin.getline(dados.Series_title_1,50);
        cout << "Series title 2:" << endl;
        cin.getline(dados.Series_title_2,50);
        cout << "Series title 3:" << endl;
        cin.getline(dados.Series_title_3,50);
        cout << "Series title 4:" << endl;
        cin.getline(dados.Series_title_4,50);
        cout << "Series title 5:" << endl;
        cin.getline(dados.Series_title_5,50);

        arquivo.seekp(posicaoAlterar * tamanhoRegistro);
        arquivo.write(reinterpret_cast<const char*>(&dados), tamanhoRegistro);

        cout << "Registro alterado com sucesso!" << endl;
    }
    else {
        cout << "Posição inválida." << endl;
    }
    arquivo.close();
}

void Arquivo::trocarElementos(){
    fstream arquivo;
    Arquivo dados, dadosAux;

    arquivo.open("lms-jun22qtr-csv_binario.dat", ios::binary | ios::in | ios::out);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    arquivo.seekg(0, ios::end);
    long long int tamanhoArquivo = arquivo.tellg();
    int tamanhoRegistro = sizeof(Arquivo);

    int posicaoTrocar, posicaoTrocado;
    cout << "Digite a posição do elemento que deseja trocar" << endl;
    cout << "Lembrando que o intervalo válido para as posições vai de 0 até "<<  tamanhoArquivo / tamanhoRegistro << endl;
    cin >> posicaoTrocar;
    cout << "Digite a posição do elemento que será trocado " << endl;
    cout << "Lembrando que o intervalo válido para as posições vai de 0 até "<<  tamanhoArquivo / tamanhoRegistro << endl;
    cin >> posicaoTrocado;

    if ((posicaoTrocar >= 0) and (posicaoTrocar <  tamanhoArquivo / tamanhoRegistro) and (posicaoTrocado >= 0) and (posicaoTrocado < tamanhoArquivo / tamanhoRegistro)) {
        int P1 = posicaoTrocar * tamanhoRegistro;
        int P2 = posicaoTrocado *  tamanhoRegistro;

        arquivo.seekg(P1);
        arquivo.read(reinterpret_cast<char*>(&dados), tamanhoRegistro);
        arquivo.seekg(P2);
        arquivo.read(reinterpret_cast<char*>(&dadosAux), tamanhoRegistro);

        arquivo.seekp(P1);
        arquivo.write(reinterpret_cast<const char*>(&dadosAux), tamanhoRegistro);
        arquivo.seekp(P2);
        arquivo.write(reinterpret_cast<const char*>(&dados), tamanhoRegistro);
        cout << "Elementos trocados com sucesso!" << endl;
    } 
    else {
        cout << "Posições inválidas." << endl;
    }

    arquivo.close();
}

void Arquivo::imprimeTudo(){
    ifstream arquivo("lms-jun22qtr-csv_binario.dat", ios::binary);
    Arquivo dados;
    while (arquivo.read((char *) (&dados),sizeof(Arquivo))) {
        cout << dados.Series_reference << ",";
        cout << dados.Period << ",";
        cout << dados.Data_value << ",";
        cout << dados.STATUS << ",";
        cout << dados.UNITS << ",";
        cout << dados.MAGNTUDE << ",";
        cout << dados.Subject << ",";
        cout << dados.Group << ",";
        cout << dados.Series_title_1 << ",";
        cout << dados.Series_title_2 << ",";
        cout << dados.Series_title_3 << ",";
        cout << dados.Series_title_4 << ",";
        cout << dados.Series_title_5 << endl;
    }
    arquivo.close();
}

int main(){
    int opcao = -1;
    Arquivo dados;
    bool fecha = false;


    while((opcao != 0) and !fecha){
        cout << "|---------------------------------------------------MENU--------------------------------------------------|" << endl;
        cout << "|                                                                                                         |" << endl;
        cout << "|              Digite [1] para adicionar um elemento                                                      |" << endl;
        cout << "|              Digite [2] para visualizar os registros entre posições                                     |" << endl;
        cout << "|              Digite [3] para alterar os dados de um registro em uma posição específica                  |" << endl;
        cout << "|              Digite [4] para trocar dois registros de posição                                           |" << endl;
        cout << "|              Digite [5] para para imprimir todos os registros do arquivo                                |" << endl;
        cout << "|              Digite [0] para sair do programa                                                           |" << endl;
        cout << "|                                                                                                         |" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------|" << endl;
        cin >> opcao;
        if(opcao == 0){
            cout << "Encerrando o programa !!";
            fecha = true;
        }
        else if(opcao == 1){
            dados.adicionarElemento();
        }
        else if(opcao == 2){
            dados.visualizar();
        }
        else if(opcao == 3){
            dados.alterarDados();
        }
        else if(opcao == 4){
            dados.trocarElementos();
        }
        else if(opcao == 5){
            dados.imprimeTudo();
        }
        else{
            cout << "Opção inávlida!" << endl;
        }
    }

    return 0;
}