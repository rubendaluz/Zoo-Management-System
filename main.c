#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANIMAIS 30
#define MAX_TRATADORES 10
#define MAX_VISITAS 100

//Variáveis globais
int numAnimal = 3; //Variavel que inicia a contagem do numero dos animais
int numTratadores = 1; //Variavel que inicia a contagem do numero de Tratadores
int numVisitas = 0; //Variavel que inicia a contagem do numero de visitas marcadas
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
    int ativo; //Pode ser: 1-Ativo || 0-Não Ativo
}TRATADOR;

typedef struct visita
{
    DATA data;
    HORA hora;
    ANIMAL animal;
    TRATADOR tratador;
}VISITA;

//Prototipos da funções
//Menus
int menuPrincipal();
int menuGestaoAnimais();
int menuConsultasAnimais();
int menuGestaoTratadores();
int menuVisitas();
//Funções para Animais
void inserirAnimal(ANIMAL animais[]);
int pesquisarAnimal(int nAnimal,ANIMAL animais[]);
void imprimirAnimal(int i, ANIMAL animais[]);
void alterarDadosAnimal(ANIMAL animais[],int nAnimal);
void consultarAnimal(int nAnimal, ANIMAL animais[]);
void listarAnimais(ANIMAL animais[]);
void listarAnimaisPorAnoEntrada(int ano,ANIMAL animais[]);
void listarAnimaisPorEspecie(ANIMAL animais[]);
void listarAnimaisEspecie(char especie[255], ANIMAL animais[]);
int animalMaisNovo(ANIMAL animais[]);
int animalMaisAntigo(ANIMAL animais[]);
//Funções para tratadores
void inserirTratador(TRATADOR *tratadores);
void alterarDadosTratador(TRATADOR *tratadores);
void alterarEstadoTratador(TRATADOR *tratadores);
void consultarDadosTratador(TRATADOR *tratadores);
void listarTratadoresAtivos(TRATADOR *tratadores);
void pesquisarTratadorNome(TRATADOR *tratadores);
int pesquisartratadorNumero(TRATADOR tratadores[], int numero);
//Funções para Visitas
void marcarVisita(VISITA visitas[],ANIMAL animais[], TRATADOR tratadores[]);
void listarVisitasDia(VISITA visitas[]);
void listarVisitasAnimal(VISITA visitas[]);
void listarVisitasTratador(VISITA visitas[]);


int main(void){

    //Arrays das estruturas
    ANIMAL animais[MAX_ANIMAIS],
    jefer={.nome = "Jefer\0",
            .numero = 1,
            .idade = 10,
            .especie = "Girafa\0",
            .data_entrada.ano = 2012,
            .data_entrada.mes = 10,
            .data_entrada.dia = 2},
    frida={.nome = "Frida\0",
            .numero = 2,
            .idade = 2,
            .especie = "Cegonha",
            .data_entrada.ano = 2015,
            .data_entrada.mes = 10,
            .data_entrada.dia = 2},
    dildo={.nome= "Dildo\0",
            .numero = 3,
            .idade = 1,
            .especie = "Girafa",
            .data_entrada.ano = 2012,
            .data_entrada.mes = 9,
            .data_entrada.dia = 2};

    animais[0]=jefer;
    animais[1]=frida;
    animais[2]=dildo;
    TRATADOR tratadores[MAX_TRATADORES], Queiroz = {
        .ativo = 1,
        .nome = "Queiroz",
        .numero = 1,
        .telemovel = 912445512
    };
    tratadores[0]= Queiroz;

    VISITA visitas[MAX_VISITAS];
    //Variaveis


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
                                consultarAnimal(nAnimal,animais);
                                break;
                            case 2:
                                listarAnimais(animais);
                                break;
                            case 3:
                                printf("Insira especie desejada: ");
                                scanf("%s", especie);
                                listarAnimaisEspecie(especie,animais);
                                break;

                            case 4:
                                i = animalMaisAntigo(animais);
                                printf("O animal mais antigo e o %s com o numero de identificacao [%d]\n", animais[i].nome, animais[i].numero);
                                break;
                            case 5:
                                i = animalMaisNovo(animais);
                                printf("O animal mais novo e o %s com o numero de identificacao [%d]\n", animais[i].nome, animais[i].numero);
                                break;
                            case 6:
                                printf("Insira o ano desejado: ");
                                fflush(stdin);
                                scanf("%d", &ano);
                                listarAnimaisPorAnoEntrada(ano,animais);
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
                            if(numTratadores<MAX_TRATADORES){
                                inserirTratador(tratadores);
                            }else{
                                printf("Não pode inserir mais tratadores pois já atingiu o limite maximo de tratadores\n");
                            }
                            break;
                        case 2:
                            alterarDadosTratador(tratadores);
                            break;
                        case 3:
                            alterarEstadoTratador(tratadores);
                            break;
                        case 4:
                            consultarDadosTratador(tratadores);
                            break;
                        case 5:
                            listarTratadoresAtivos(tratadores);
                            break;
                        case 6:
                            pesquisarTratadorNome(tratadores);
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
                        if(numVisitas < MAX_VISITAS){
                            marcarVisita(visitas,animais,tratadores);
                        }else{
                            printf("Já não pode marcar mais consultas pois o numero maximo de marcacoes ja foi atingido.\n");
                        }
                        break;
                    case 2:
                        listarVisitasDia(visitas);
                        break;
                    case 3:
                        listarVisitasAnimal(visitas);
                        break;
                    case 4:
                        listarVisitasTratador(visitas);
                        break;
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

/*Funções do menu de gestão de Animais*/
void inserirAnimal(ANIMAL animais[]){
    animais[numAnimal].numero = numAnimal;
    printf("Insira o nome do animal: ");
    scanf("%s", animais[numAnimal].nome);
    printf("Insira a sua especie: ");
    scanf("%s", animais[numAnimal].especie);
    printf("Insira a sua idade: ");
    scanf("%d", &animais[numAnimal].idade);
    printf("Insira a data de entrada do animal: ");
    scanf("%d%d%d", &animais[numAnimal].data_entrada.dia,
    &animais[numAnimal].data_entrada.mes,&animais[numAnimal].data_entrada.ano);
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
    printf("\tData de entrada: %d/%d/%d\n", animais[i].data_entrada.dia,
    animais[i].data_entrada.mes,animais[i].data_entrada.ano);
}

void alterarDadosAnimal(ANIMAL animais[],int nAnimal){
    int i = pesquisarAnimal(nAnimal,animais);
    if(i == 31){
        printf("Não existe nenhum animal com o numero [%d].\n", nAnimal);
    }else{
        inserirAnimal(animais);
    }
}

void consultarAnimal(int nAnimal, ANIMAL animais[]){
    int i = pesquisarAnimal(nAnimal,animais);
    imprimirAnimal(i,animais);
}

void listarAnimais(ANIMAL animais[]){
    int i;
    for(i=0;i<numAnimal;i++){
        imprimirAnimal(i,animais);
    }
}

void listarAnimaisPorEspecie(ANIMAL animais[]){
    int i,j,x=0;
    char especie[255];
    ANIMAL arrayOrdenado[MAX_ANIMAIS];
    for(i=0;i<numAnimal;i++){
        strcpy(especie,animais[i].especie);
        for(j=i+1;j<numAnimal;j++){
            if(strcmp(especie, animais[j].especie) == 0){
                arrayOrdenado[x] = animais[j];
            }
        } 
        if (i==numAnimal-1)break;    
    }

    for(i=0;i<numAnimal;i++){
        imprimirAnimal(i,arrayOrdenado);
    }
}

void listarAnimaisEspecie(char especie[255], ANIMAL animais[]){
    int i,j=0;
    for(i=0;i<numAnimal;i++){
        if(strcmpi(especie,animais[i].especie) == 0){
            imprimirAnimal(i,animais);
            j=1;
        }
    }
    if(j==0){
        printf("Não existem animais da especie: %s", especie);
    }
}

int animalMaisNovo(ANIMAL animais[]){
    ANIMAL mais_velho;
    int i,j;
    mais_velho = animais[0];
    for(i=1;i<numAnimal;i++){
        if(mais_velho.data_entrada.ano < animais[i].data_entrada.ano){
            mais_velho = animais[i];
            j=i;
        }else if (mais_velho.data_entrada.ano == animais[i].data_entrada.ano){ 
            if(mais_velho.data_entrada.mes < animais[i].data_entrada.mes){
                mais_velho = animais[i];
                j=i;
            }else if(mais_velho.data_entrada.mes == animais[i].data_entrada.mes){ 
                if(mais_velho.data_entrada.dia < animais[i].data_entrada.dia){
                    mais_velho = animais[i];
                    j=i;
                }
            }
        }
    }
    return j;
}

int animalMaisAntigo(ANIMAL animais[]){
    ANIMAL mais_novo;
    int i,j;
    mais_novo = animais[0];
    for(i=1;i<numAnimal;i++){
        if(mais_novo.data_entrada.ano > animais[i].data_entrada.ano){
            mais_novo = animais[i];
            j=i;
        }else if(mais_novo.data_entrada.ano == animais[i].data_entrada.ano){ 
            if(mais_novo.data_entrada.mes > animais[i].data_entrada.mes){
                mais_novo = animais[i];
                j=i;
            }else if(mais_novo.data_entrada.mes > animais[i].data_entrada.mes){ 
                if(mais_novo.data_entrada.dia > animais[i].data_entrada.dia){
                    mais_novo = animais[i];
                    j=i;
                }
            }
        }
    }
    return j;
}

void listarAnimaisPorAnoEntrada(int ano,ANIMAL animais[]){
    int i,j=0;
    for(i=0;i<numAnimal;i++){
        if(ano == animais[i].data_entrada.ano){
            imprimirAnimal(i,animais);
            j=1;
        }
    }
    if(j==0)
        printf("Não existem animais que deram entrada no ano %d.\n", ano);
}

//Funções referentes ao tratadores
// INSERIR NOVO TRATADOR
void inserirTratador(TRATADOR *tratadores){
    printf("Inserir novo tratador\n");
    tratadores[numTratadores].numero = numTratadores+1;
    printf("Nome: ");
    scanf("%s", tratadores[numTratadores].nome);
    printf("Telemovel: ");
    fflush(stdin);
    scanf("%d", &tratadores[numTratadores].telemovel);
    tratadores[numTratadores].ativo = 1;
    (numTratadores)++;
    printf("Tratador inserido com sucesso!\n");
    numTratadores++;
 }

// ALTERAR DADOS DE UM TRATADOR
void alterarDadosTratador(TRATADOR *tratadores){
    int numero,i,j;
    printf("Alterar dados de um tratador\n");
    printf("Numero do Tratador: ");
    fflush(stdin);
    scanf("%d", &numero);
    for (i = 0; i < numTratadores; i++)
    {
        if (tratadores[i].numero == numero)
        {
            j=1;
            int opcao;
            printf("O que pretende alterar?\n");
            printf("1 - Nome\n");
            printf("2 - Telemovel\n");
            printf("3 - Cancelar\n");
            printf(">Opcao: ");
            fflush(stdin);
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                printf("Insira o novo NOME: ");
                scanf("%s", tratadores[i].nome);
                printf("Nome do tratador atualizado com sucesso!\n");
                break;
            case 2:
                printf("Insira o novo TELEMOVEL: ");
                fflush(stdin);
                scanf("%d", &tratadores[i].telemovel);
                scanf("Telemovel do tratador atualizado com sucesso!\n");
                break;
            case 3:
                printf("Operacao cancelada.\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }
        }       
    }
    if(j!=1)
        printf("Tratador nao encontrado\n");
    
  }



// ALTERAR ESTADO DE UM TRATADOR
void alterarEstadoTratador(TRATADOR *tratadores){
    int numero,i,encontrado;
    printf("Ativar/Desativar um tratador\n");
    printf("Insira o numero do tratador: ");
    scanf("%d", &numero);
    for (i = 0; i < numTratadores; i++)
    {
        if (tratadores[i].numero == numero)
        {
            encontrado=1;
            printf("Ativo (1) ou nao ativo (0): ");
            fflush(stdin);
            scanf("%d", &tratadores[i].ativo);
            printf("Estado do tratador %s atualizado para %s com sucesso!\n", tratadores[i].nome, tratadores[i].ativo ? "ativo" : "nao ativo");
        }
    }
    if(encontrado!=1)
            printf("Tratador nao encontrado\n");
}


// CONSULTAR DADOS DE UM TRATADOR 
void consultarDadosTratador(TRATADOR *tratadores) { 
    int numero,encontrado = 0;
    printf("Consultar dados de um tratador\n");
    printf("Numero do tratador: ");
    scanf("%d", &numero);
    for (int i = 0; i < numTratadores; i++)
    {
        if (tratadores[i].numero == numero)
        {
            encontrado=1;
            printf("Nome: %s\n", tratadores[i].nome);
            printf("Telefone: %d\n", tratadores[i].telemovel);
            printf("Estado: %d\n", tratadores[i].ativo ? "Ativo" : "Nao ativo");
            return;
        }
    }
    if(encontrado!=1)
        printf("Tratador nao encontrado\n");
}

// LISTA DOS TRATADORES ATIVOS
void listarTratadoresAtivos(TRATADOR *tratadores) {
    int encontrado;
    printf("Lista dos tratadores ativos\n");
    for (int i = 0; i < numTratadores; i++) {
        if (tratadores[i].ativo == 1) {
            encontrado = 1;
            printf("Numero: %d\n", tratadores[i].numero);
            printf("Nome: %s\n", tratadores[i].nome);
            printf("Telemovel: %d\n", tratadores[i].telemovel);
            printf("Ativo: %d\n", tratadores[i].ativo);
        }
    }
    if(encontrado!=1)
        printf("Nao existem tratadores ativos\n");
}


// PESQUISAR TRATADOR POR NOME
void pesquisarTratadorNome(TRATADOR *tratadores) {
    char nome[50],resposta;
    int encontrado;

    do {
        printf("Pesquisar tratador por nome\n");
        printf("Nome: ");
        scanf("%s", nome);
        encontrado = 0;

        for (int i = 0; i < numTratadores; i++) {
            if (strcmp(tratadores[i].nome, nome) == 0) {
                printf("Numero: %d\n", tratadores[i].numero);
                printf("Nome: %s\n", tratadores[i].nome);
                printf("Telefone: %d\n", tratadores[i].telemovel);
                printf("Ativo: %d\n\n", tratadores[i].ativo);
                encontrado = 1;
                printf("Deseja pesquisar novamente? (S/N): ");
                scanf(" %c", &resposta);
            }
        }

        if (encontrado!=1) {
            printf("Nenhum tratador encontrado com o nome %s.\n", nome);
            printf("Deseja pesquisar novamente? (S/N): ");
            scanf(" %c", &resposta);
        }

    } while (resposta != 'N');
}

int pesquisartratadorNumero(TRATADOR tratadores[], int numero){
    char resposta;
    int encontrado;


    encontrado = 0;
    do{
        for (int i = 0; i < numTratadores; i++) {
            if (tratadores[i].numero == numero) {
                encontrado = 1;
                return i;
            }
        }

        if (encontrado!=1) {
            printf("Nenhum tratador encontrado com o numero %d.\n", numero);
            printf("Deseja inserir outro? (S/N): ");
            scanf(" %c", &resposta);
        }
        if(resposta == 'N')break;
    }while(resposta == 'S' || encontrado != 1);
    
    return 101;
}

void marcarVisita(VISITA visitas[],ANIMAL animais[], TRATADOR tratadores[]){
    int animal,tratador;
    int i_animal,i_tratador;
    printf("Insira a data para a qual pretende marcar a Visita. No formato [dd mm aaaa].\n");
    printf("Data: ");
    fflush(stdin);
    scanf("%d%d%d", &visitas[numVisitas].data.dia,&visitas[numVisitas].data.mes,&visitas[numVisitas].data.ano);
    printf("Insira agora a hora no formato [hh].\n");
    printf("Hora: ");
    fflush(stdin);
    scanf("%d", &visitas[numVisitas].hora.horas);
    printf("Insira o nome do Animal: ");
    fflush(stdin);
    scanf("%d", &animal);
    i_animal = pesquisarAnimal(animal,animais);
    if(i_animal != 31){
        visitas[numVisitas].animal = animais[i_animal];
        printf("insira o nome do tratador: ");
        fflush(stdin);
        scanf("%d",&tratador);
        i_tratador = pesquisartratadorNumero(tratadores,tratador);
        if(i_tratador != 101){
            visitas[numVisitas].tratador = tratadores[i_tratador];
        }
    }
    numVisitas++;
}

void listarVisitasDia(VISITA visitas[]){
    DATA data;
    int i,existem_visitas = 0;
    printf("Insira a data para que pretende no formato [dd mm aaaa].\n");
    printf("Data: ");
    scanf("%d%d%d", &data.dia, &data.mes, &data.ano);
    printf("Visitas para o dia [%d/%d/%d]:\n",data.dia, data.mes, data.ano);
    for(i=0;i<numVisitas;i++){
        if(visitas[i].data.dia == data.dia &&
        visitas[i].data.mes == data.mes &&
        visitas[i].data.ano == data.ano){
            printf("Visita-Hora:%d:00-Animal:%d, %s - Tratador: %s[%d].\n", 
            visitas[i].hora.horas, visitas[i].animal.numero, visitas[i].animal.nome,
            visitas[i].tratador.nome, visitas[i].tratador.telemovel);
            existem_visitas = 1;
        }
    }
    if(existem_visitas!=1){
        printf("Nao existem visitas para este dia.\n");
    }
}
void listarVisitasAnimal(VISITA visitas[]){
    char nome_animal[255];
    int i, existem_visitas = 0;
    printf("Insira o nome do animal: ");
    scanf("%s", nome_animal);
    printf("Visitas marcadas para o %s.\n", nome_animal);
    for(i=0;i<numVisitas;i++){
        if(strcmpi(nome_animal,visitas[i].animal.nome)==0){
            printf("Visita-Data:%d/%d/%d, %d:00-Animal:%d, %s - Tratador: %s[%d].\n",
            visitas[i].data.dia,visitas[i].data.mes, visitas[i].data.ano,visitas[i].hora.horas,
            visitas[i].animal.numero, visitas[i].animal.nome,visitas[i].tratador.nome, 
            visitas[i].tratador.telemovel);
            existem_visitas = 1;
        }
    }
    if(existem_visitas!=1){
        printf("Nao existem visitas para este animal.\n");
    }
}
void listarVisitasTratador(VISITA visitas[]){
    char nome_tratador[255];
    int i, existem_visitas = 0;
    printf("Insira o nome do tratador: ");
    scanf("%s", nome_tratador);
    printf("Visitas marcadas para o %s.\n", nome_tratador);
    for(i=0;i<numVisitas;i++){
        if(strcmpi(nome_tratador,visitas[i].tratador.nome)==0){
            printf("Visita-Data:%d/%d/%d, %d:00-Animal:%d, %s - Tratador: %s[%d].\n",
            visitas[i].data.dia,visitas[i].data.mes, visitas[i].data.ano,visitas[i].hora.horas,
            visitas[i].animal.numero, visitas[i].animal.nome,visitas[i].tratador.nome, 
            visitas[i].tratador.telemovel);
            existem_visitas = 1;
        }
    }
    if(existem_visitas!=1){
        printf("Nao existem visitas para este tratador.\n");
    }
}