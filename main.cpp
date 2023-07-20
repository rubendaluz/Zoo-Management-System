#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

class Data {
public:
    int dia;
    int mes;
    int ano;

    Data(int dia = 0, int mes = 0, int ano = 0) : dia(dia), mes(mes), ano(ano) {}
};

class Animal {
private:
    int numero;
    std::string nome;
    std::string especie;
    Data dataEntrada;
    bool tratado;
    // Tratador tratador;

public:
    Animal();
    Animal(int numero, const std::string& nome, const std::string& especie, const Data& dataEntrada)
        : numero(numero), nome(nome), especie(especie), dataEntrada(dataEntrada), tratado(false) {}

    int getNumero() const { return numero; }
    void setNumero(int numero) {this->numero = numero;}
    Data getDataEntrada() const {return dataEntrada;}
    void setData(Data data) {this->dataEntrada = data;}
    std::string getNome() const { return nome; }
    void setNome(std::string nome){ this->nome = nome;}
    std::string getEspecie() const { return especie; }
    void setEspecie(std::string especie){ this->especie = especie;}
    bool getStatus() const { return tratado;}
    void setTratado(bool tratado) { this->tratado = tratado; }

    void imprimirAnimal() const {
        std::cout << "Animal " << nome << " (numero " << numero << "), Especie: " << especie;
        std::cout << ", Data de Entrada: " << dataEntrada.dia << "/" << dataEntrada.mes << "/" << dataEntrada.ano;
        std::cout << ", " << (tratado ? "Tratado" : "Nao tratado") << "\n";
    }
};

class Tratador {
private:
    int numero;
    std::string nome;
    bool ativo;

public:
    Tratador(int numero, const std::string& nome, bool ativo = true)
        : numero(numero), nome(nome), ativo(ativo) {}

    int getNumero() const { return numero; }
    std::string getNome() const { return nome; }

    bool isAtivo() const { return ativo; }

    void imprimirTratador() const {
        std::cout << "Tratador " << nome << " (numero " << numero << "), " << (ativo ? "Ativo" : "Inativo") << "\n";
    }
};

class Visita {
private:
    int numero;
    Data dataVisita;

public:
    Visita(int numero, const Data& dataVisita) : numero(numero), dataVisita(dataVisita) {}

    int getNumero() const { return numero; }
    void setNumero(int numero) {this->numero = numero;}
    Data getData() const { return dataVisita;}
    void setData(Data data){this->dataVisita = data;}

    void imprimirVisita() const {
        std::cout << "Visita " << numero << ", Data: " << dataVisita.dia << "/" << dataVisita.mes << "/" << dataVisita.ano << "\n";
    }
};

class Zoo {
private:
    static const int MAX_ANIMAIS = 100;
    static const int MAX_TRATADORES = 50;
    static const int MAX_VISITAS = 100;

    std::vector<Animal> animais;
    std::vector<Tratador> tratadores;
    std::vector<Visita> visitas;

    int numAnimais;
    int numTratadores;
    int numVisitas;

public:
    Zoo() : numAnimais(0), numTratadores(0), numVisitas(0) {}

    Animal criarAnimal(){
        Animal animal;

        std::cout << "Insira o nome do animal: ";
        std::string nome;
        std::cin >> nome;
        animal.setNome(nome);
        animal.setNumero(rand());
        std::cout << "Insira o nome da especie do animal: ";
        std::string especie;
        std::cin >> especie;
        animal.setEspecie(especie);
        Data data;
        animal.setTratado(false);

        return animal;
    }

    void inserirAnimal(const Animal& animal) {
        if (numAnimais < MAX_ANIMAIS) {
            animais.push_back(animal);
            numAnimais++;
        } else {
            std::cout << "Ja atingiu o limite de animais que podem ser inseridos [" << MAX_ANIMAIS << "]!!\n";
        }
    }

    void inserirTratador(const Tratador& tratador) {
        if (numTratadores < MAX_TRATADORES) {
            tratadores.push_back(tratador);
            numTratadores++;
        } else {
            std::cout << "Ja atingiu o limite de tratadores que podem ser inseridos [" << MAX_TRATADORES << "]!!\n";
        }
    }

    void marcarVisita(const Visita& visita) {
        if (numVisitas < MAX_VISITAS) {
            visitas.push_back(visita);
            numVisitas++;
        } else {
            std::cout << "Ja atingiu o limite de visitas que podem ser marcadas [" << MAX_VISITAS << "]!!\n";
        }
    }

    void listarAnimais() const {
        std::cout << "\n---Lista de Animais---\n";
        for (const auto& animal : animais) {
            animal.imprimirAnimal();
            std::cout << "\n";
        }
    }

    void listarAnimaisPorEspecie() const {
        std::cout << "\n---Lista de Animais por Especie---\n";
        std::vector<std::string> especies;

        // Gather unique species names
        for (const auto& animal : animais) {
            if (std::find(especies.begin(), especies.end(), animal.getNome()) == especies.end()) {
                especies.push_back(animal.getNome());
            }
        }

        // Print animals grouped by species
        for (const auto& especie : especies) {
            std::cout << "Especie: " << especie << "\n";
            for (const auto& animal : animais) {
                if (animal.getNome() == especie) {
                    animal.imprimirAnimal();
                }
            }
            std::cout << "\n";
        }
    }

    void listarAnimaisPorAnoEntrada(int ano) const {
        std::cout << "\n---Lista de Animais por Ano de Entrada (" << ano << ")---\n";
        for (const auto& animal : animais) {
            if (animal.getDataEntrada().ano == ano) {
                animal.imprimirAnimal();
                std::cout << "\n";
            }
        }
    }

    void listarTratadoresAtivos() const {
        std::cout << "\n---Lista de Tratadores Ativos---\n";
        for (const auto& tratador : tratadores) {
            if (tratador.isAtivo()) {
                tratador.imprimirTratador();
            }
        }
    }

    void listarVisitasDia(const Data& data) const {
        std::cout << "\n---Lista de Visitas para o Dia " << data.dia << "/" << data.mes << "/" << data.ano << "---\n";
        for (const auto& visita : visitas) {
            if (visita.getData().dia == data.dia && visita.getData().mes == data.mes && visita.getData().ano == data.ano) {
                visita.imprimirVisita();
            }
        }
    }

    void listarVisitasAnimal(const Animal& animal) const {
        std::cout << "\n---Lista de Visitas para o Animal " << animal.getNome() << " (numero " << animal.getNumero() << ")---\n";
        for (const auto& visita : visitas) {
            visita.imprimirVisita();
        }
    }

    void listarVisitasTratador(const Tratador& tratador) const {
        std::cout << "\n---Lista de Visitas para o Tratador " << tratador.getNome() << " (numero " << tratador.getNumero() << ")---\n";
        for (const auto& visita : visitas) {
            visita.imprimirVisita();
        }
    }
};


//Animais
int menuVisitas();

int main(void){

    Zoo Zoo1;

    while (1)
    {   
        int nAnimal;
        int opcao = menuPrincipal();
        char confirmar_saida;
        if (opcao == 0) {
            printf("Pretende realmente sair? Se Sim insira[Y/y], se Nao insira[N/n]");
            fflush(stdin);
            scanf("%c", &confirmar_saida);
            if(confirmar_saida == 'Y' || confirmar_saida == 'y'){
                printf("Programa encerrado!!\n\n");
                break;
            }
        }
        switch (opcao){
            case 1:
                while(1){
                int opcao1= menuGestaoAnimais();
                if(opcao1 == 0){
                    break;
                }
                switch (opcao1)
                {
                    case 1:
                        Zoo1.inserirAnimal(Zoo1.criarAnimal());
                        break;
                    case 2:
                        printf("Insira o numero do animal que deseja: ");
                        fflush(stdin);
                        scanf("%d", &nAnimal); 
                        // alterarDadosAnimal(animais,nAnimal);
                        break;
                    case 3:
                        while(1){
                            char especie[255];
                            int nAnimal,ano,i, opcao2 = menuConsultasAnimais();
                            if (opcao2 == 0){
                                break;
                            }
                            switch (opcao2)
                            {
                            case 1:
                                printf("Insira o numero do animal desejado: ");
                                fflush(stdin);
                                scanf("%d", &nAnimal);
                                // consultarAnimal(nAnimal,animais);
                                break;
                            case 2:
                                Zoo1.listarAnimais();
                                break;
                            case 3:
                                printf("Insira especie desejada: ");
                                scanf("%s", especie);
                                Zoo1.listarAnimaisPorEspecie();
                                break;

                            case 4:
                                // i = animalMaisAntigo(animais);
                                printf("O animal mais antigo e o %s com o numero de identificacao [%d]\n", animais[i].nome, animais[i].numero);
                                break;
                            case 5:
                                // i = animalMaisNovo(animais);
                                printf("O animal mais novo e o %s com o numero de identificacao [%d]\n", animais[i].nome, animais[i].numero);
                                break;
                            case 6:
                                printf("Insira o ano desejado: ");
                                fflush(stdin);
                                scanf("%d", &ano);
                                Zoo1.listarAnimaisPorAnoEntrada();
                                break;
                            
                            default:
                                break;
                            }
                        }
                        break;  
                    default:
                        printf("Esta opcao nao existe ou e invalida!!!\n");
                        break;
                }
            }
                break;
            case 2:
                while(1){
                    int opcao;
                    if((opcao=menuGestaoTratadores())==0)
                        break;
                    switch (opcao)
                    {
                        case 1:
                            Zoo1.inserirTratador();
                            break;
                        case 2:
                            // Zoo1.alterarDadosTratador();
                            break;
                        case 3:
                            // alterarEstadoTratador(tratadores);
                            break;
                        case 4:
                            // Zoo1.consultarDadosTratador();
                            break;
                        case 5:
                            // Zoo1.listarTratadoresAtivos();
                            break;
                        case 6:
                            // pesquisarTratadorNome();
                            break;
                        default:
                            printf("Esta opcao e invalida ou nao existe!!\n");
                            break;
                    }
                }
                break;
            case 3:
                while(1){
                    int opcao;
                    if((opcao=menuVisitas()) == 0)
                        break;
                    switch (opcao)
                {
                    case 1:
                        // Zoo1.marcarVisita();
                        break;
                    case 2:
                        int dia, mes, ano;

                        std::cout << "Insira a data no formato dd/mm/aaaa: ";
                        std::string data;
                        std::cin >> data;

                        // Usamos um stringstream para extrair os valores de dia, mês e ano da string
                        std::stringstream ss(data);
                        char delimiter; // Usaremos para "consumir" as barras da data

                        ss >> dia >> delimiter >> mes >> delimiter >> ano;

                        // Verificamos se os valores estão corretos (opcional)
                        if (ss.fail() || delimiter != '/' || dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0) {
                            std::cout << "Data inválida. Certifique-se de que a data esteja no formato dd/mm/aaaa." << std::endl;
                            return 1; // Código de erro
                        }

                        // Criamos um objeto da classe Data e passamos os valores
                        Data data_formated(dia, mes, ano);
                        Zoo1.listarVisitasDia(data);
                        break;
                    // case 3:
                    //     // listarVisitasAnimal(visitas);
                    //     break;
                    // case 4:
                    //     // listarVisitasTratador(visitas);
                    //     break;
                    default:
                        printf("Esta opcao e invalida ou nao existe!!\n");
                        break;
                }
                }
                break;
            default:
                printf("Esta opcao e invalida ou nao existe!!\n");
                break;
        }
    }
    
    
    
    return 0;
}

//Menus: 
int menuPrincipal(){
    int opcao;

    puts("||------------MENU PRINCIPAL-------------||");
    puts("||      1 - Gestao de Animais            ||");
    puts("||      2 - Gestao de Tratores           ||");
    puts("||      3 - Marcacao/Consultas de Visitas||");
    puts("||      0 - Sair                         ||");
    puts("||---------------------------------------||");

    puts("Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;

}

int menuGestaoAnimais(){
    int opcao;

    puts("||---------MENU GESTAO ANIMAIS-----------||");
    puts("||      1 - Inserir Animal               ||");
    puts("||      2 - Alterar dados de um Animal   ||");
    puts("||      3 - Consultas                    ||");
    puts("||      0 - Sair                         ||");
    puts("||---------------------------------------||");

    puts("Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

int menuConsultasAnimais(){
    int opcao;

    puts("||-------------MENU CONSULTAS ANIMAIS-------------||");
    puts("||      1 - Consultar dados de um Animal          ||");
    puts("||      2 - Listar todos os animais               ||");
    puts("||      3 - Listar animais por especie            ||");
    puts("||      4 - Animal mais antigo no ZOO             ||");
    puts("||      5 - Animal mais novo no ZOO               ||");
    puts("||      6 - Listar animais por ano de entrada     ||");
    puts("||      0 - Sair                                  ||");
    puts("||------------------------------------------------||");

    puts("Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

int menuGestaoTratadores(){
    int opcao;

    puts("||--------MENU GESTAO TRATADORES---------||");
    puts("||      1 - Inserir novo tratador        ||");
    puts("||      2 - Alterar dados de tratador    ||");
    puts("||      3 - Mudar estado de tratador     ||");
    puts("||      4 - Consultar dados de tratador  ||");
    puts("||      5 - Listar tratadores ativos     ||");
    puts("||      6 - Pesquisar tratador por nome  ||");
    puts("||      0 - Sair                         ||");
    puts("||---------------------------------------||");

    puts("Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

int menuVisitas(){
    int opcao;

    puts("||--------MENU MARCACAO/CONSULTA DE VISITAS--------||");
    puts("||      1 - Marcar Visita                          ||");
    puts("||      2 - Listar visitas marcadas por dia        ||");
    puts("||      3 - Listar visitas marcadas de um animal   ||");
    puts("||      3 - Listar visitas marcadas de um tratador |");
    puts("||      0 - Sair                                   ||");
    puts("||-------------------------------------------------||");

    puts("Selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}
