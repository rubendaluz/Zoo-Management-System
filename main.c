#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANIMAIS 30
#define MAX_TRATADORES 10
#define MAX_VISITAS 100

//Variáveis globais
int animais = 0; //Variavel que guarda o numero de animais que já foram inseridos.
int numAnimal = 0; //Variavel que inicia a contagem do numero dos animais

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

int menuConsultasAnimasis(){
    int opcao;

    puts("||-------------MENU CONSULTAS ANIMAIS-------------||");
    puts("||      1 - Consultar dados Animal                ||");
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
    scanf("%s", &animais[numAnimal].nome);
    printf("Insira a sua especie: ");
    scanf("%s", &animais[numAnimal].especie);
    printf("Insira a sua idade: ");
    scanf("%d");
    numAnimal++;
}

int main(void){

    //Arrays das estruturas
    ANIMAL animais[MAX_ANIMAIS];
    TRATADOR tratadores[MAX_TRATADORES];
    VISITA visitas[MAX_VISITAS];
    //Variaveis

    switch (menuPrincipal())
    {
        case 1:
            switch (menuGestaoAnimais())
            {
                case 1:
                    if(numAnimal < MAX_ANIMAIS){
                        inserirAnimal(animais);
                    }else{
                        printf("Ja atingiu o limite de animais que podem ser inseridos[30]!!\n");
                    }
                    break;
                
                default:
                    break;
            }
            break;
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
    
    return 0;
}