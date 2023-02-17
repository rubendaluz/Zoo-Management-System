#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANIMAIS 30
#define MAX_TRATADORES 10
#define MAX_VISITAS 100

//Variáveis globais
int numAnimal = 3; //Variavel que inicia a contagem do numero dos animais

//Estruturas 
typedef struct data{
    int dia, mes, ano;
}DATA;

typedef struct hora
{
    int horas, minutos;
}HORA;

typedef struct animal
{
    int numero;
    char nome[255];
    char especie[255];
    int idade;
    DATA data_entrada;
}ANIMAL;

typedef struct tratador
{
    int numero;
    char nome[255];
    int telemovel;
    int estado; //Pode ser: 1-Ativo || 0-Não Ativo
}TRATADOR;

typedef struct visita
{
    DATA data;
    HORA hora;
    ANIMAL animal;
    TRATADOR tratador;
}VISITA;

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
    puts("||      1 - Consultar dados Animal                ||");
    puts("||      2 - Listar todos os animais               ||");
    puts("||      2 - Listar animais por especie            ||");
    puts("||      3 - Listar amnimais com mais tempo no ZOO ||");
    puts("||      4 - Listar animais com menos tempo no ZOO ||");
    puts("||      5 - Listar animais por ano de entrada     ||");
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

/*Funções do menu de gestão de Animais*/

void inserirAnimal(ANIMAL animais[]){
    animais[numAnimal].numero = numAnimal;
    printf("Insira o nome do animal: ");
    scanf("%s", animais[numAnimal].nome);
    printf("Insira a sua especie: ");
    scanf("%s", animais[numAnimal].especie);
    printf("Insira a sua idade: ");
    scanf("%d", &animais[numAnimal].idade);
    numAnimal++;
}

int pesquisarAnimal(int nAnimal,ANIMAL animais[]){
    int i;
    for(i=0;i<numAnimal;i++){
        if(nAnimal == animais[i].numero){
            return i;
            puts("Encontrou!!");
        }
    }
    return 31;
}

void imprimirAnimal(int i, ANIMAL animais[]){
    printf("---Animal[%d]-------------------\n", i+1);
    printf("\tNome: %s\n", animais[i].nome);
    printf("\tEspecie: %s\n", animais[i].especie);
    printf("\tIdade: %d\n", animais[i].idade);
}

void alterarDadosAnimal(ANIMAL animais[],int nAnimal){
    int i = pesquisarAnimal(nAnimal,animais);
    if(i == 31){
        printf("Não existe nenhum animal com o numero [%d].\n", nAnimal);
    }else{
        printf("Insira o nome do animal: ");
        scanf("%s", animais[i].nome);
        printf("Insira a sua especie: ");
        scanf("%s", animais[i].especie);
        printf("Insira a sua idade: ");
        scanf("%d", &animais[i].idade);
    }
}

void consultarAnimal(int nAnimal, ANIMAL animais[]){
    int i = pesquisarAnimal(nAnimal,animais);
    imprimirAnimal(i,animais);
}

void listarAnimais(ANIMAL animais[]){
    int i;
    for(i=0;i<numAnimal;i++){
        printf("---Animal[%d]-------------------\n", i+1);
        printf("\tNome: %s\n", animais[i].nome);
        printf("\tEspecie: %s\n", animais[i].especie);
        printf("\tIdade: %d\n", animais[i].idade);
        //printf("\tData de entrada: %d/%d/%d\n", animais[i].data_entrada.dia, animais[i].data_entrada.mes, animais[i].data_entrada.ano);
    }
}

void listarAnimaisPorEspecie(ANIMAL animais[]){
    int i,j;
    char especie[255];
    for(i=0;i<numAnimal;i++){
        strcpy(especie,animais[i].especie);
        imprimirAnimal(i,animais);
        for(j=i+1;j<numAnimal;j++){
            if(strcmp(especie, animais[j].especie) == 0){
                imprimirAnimal(j,animais);
            }
        }
        i=j;    
    }
}

int main(void){

    //Arrays das estruturas
    ANIMAL animais[MAX_ANIMAIS],
    jefer={.nome = "Jefer\0",
            .numero = 1,
            .idade = 10,
            .especie = "Girafa\0"},
    frida={.nome = "Frida\0",
            .numero = 2,
            .idade = 2,
            .especie = "Tomate"},
    dildo={.nome= "Dildo\0",
            .numero = 3,
            .idade = 1,
            .especie = "Girafa"};

    animais[0]=jefer;
    animais[1]=frida;
    animais[2]=dildo;
    //TRATADOR tratadores[MAX_TRATADORES];
    //VISITA visitas[MAX_VISITAS];
    //Variaveis


    while (1)
    {   
        int nAnimal;
        int opcao = menuPrincipal();
        if (opcao == 0) {
            break;
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
                        if(numAnimal < MAX_ANIMAIS){
                            inserirAnimal(animais);
                        }else{
                            printf("Ja atingiu o limite de animais que podem ser inseridos[30]!!\n");
                        }
                        break;
                    case 2:
                        printf("Insira o numero do animal que deseja: ");
                        fflush(stdin);
                        scanf("%d", &nAnimal); 
                        alterarDadosAnimal(animais,nAnimal);
                        break;
                    case 3:
                        while(1){
                            int nAnimal, opcao2 = menuConsultasAnimais();
                            if (opcao2 == 0){
                                break;
                            }
                            switch (opcao2)
                            {
                            case 1:
                                printf("Insira o numero do animal desejado: ");
                                fflush(stdin);
                                scanf("%d", &nAnimal);
                                consultarAnimal(nAnimal,animais);
                                break;
                            case 2:
                                listarAnimais(animais);
                                break;
                            case 3:
                                listarAnimaisPorEspecie(animais);
                                break;
                            
                            default:
                                break;
                            }
                        }
                        break;  
                    default:
                        break;
                }
                }
            case 2:
                switch (menuGestaoTratadores())
                {
                    case 1:
                        /* code */
                        break;
                    
                    default:
                        break;
                }
                break;
            case 3:
                switch (menuVisitas())
                {
                    case 1:
                        /* code */
                        break;
                    
                    default:
                        break;
                }
                break;
            case 0:

                break;
            default:
                break;
        }
    }
    
    
    
    return 0;
}

