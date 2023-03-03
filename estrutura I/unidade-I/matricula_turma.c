#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3  // total de vagas para os alunos
#define MAX_TURMAS 2 // total de turmas que existem

#define QTD_NOTAS 3 // quantidades de notas

typedef struct aluno // struct aluno guarda os dados que o aluno vai ter ao realizar sua matricula em uma turma
{
    int mat;
    char nome[50];
    float notas[QTD_NOTAS];
    float media;
} Aluno;

typedef struct turma // turmas para cadastra os alunos com uma struct aluno declarada dentro do seu corpo
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];

} Turma;

//=======================================================
//                    funções
void menu(void); // mostra um mini menu

Turma *cria_turma(char id); // funçao para criar uma turma

void imprime_turmas(Turma **turmas, int n); // imprime as turmas criadas e diz se a vagas nelas

void matricula_aluno(Turma *turma, int mat, char *nome); // matricula um aluno e inicializa sua notas com 0

Turma *procura_turma(Turma **turmas, int n, char id); // procura a turma que de acordo com o id que a pessoa digitou

void lanca_notas(Turma *turma); // pede as notas e ja faz a media do aluno 

void imprime_alunos(Turma *turma);  // mostra os  alunos que estao cadatrados na turma sua media ,matricula e nome

//========================================================

int main()
{
    int op, i = 0, count_free,count2_free, cont_turmas, mat;  // variaveis auxiliares  
    char id, nome[50];

    Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));    // crindo o ponteiro turma e alocando dinamicamente
    Turma *turma_procurada;  // ponteriro auxiliar para guarda a turma quando inicializar o processo de busca de turmas 

    do              // estrutura do-while para continuar o loop ate que a pessoa digite sair "6"
    {
        menu();  // mostra um mini menu
        printf("digite sua opcao: ");       // pede a op para pessoa e o guarda na variavel op
        scanf("%d", &op);
        printf("\n");

        switch (op)     //   escolhi usa pois achei mais organizado 
        {

        case 1:                        
            if (i < MAX_TURMAS) // verificando se a vaga para criar uma turma 
            {
                printf("digite o id da turma que deseja cadastrar: "); // pedindo o id e criando uma turma
                scanf(" %c", &id);
                turmas[i] = cria_turma(id);             // chamnado a funcao criar turma e armazenando em turmas na posiçao que estiver livre
                i++;
            }
            else            // caso nao aja  
            {
                printf("nao ha mais vagas para criar turmas\n");     
            }
            break;
        case 2:
            imprime_turmas(turmas, i);   // imprimindo se a vagas nas turmas 
            break;
        case 3:
            for (cont_turmas = 0; cont_turmas < i; cont_turmas++)   //  verificar quantas turmas foram criadas 
            {
                if (turmas[cont_turmas]->vagas != 0)    // se 
                {
                    printf("digite o id: ");
                    scanf(" %c", &id);

                    turma_procurada = procura_turma(turmas, i, id);     // chama a funçao procura e passa seus parametros 

                    if (turma_procurada == NULL)    // verifica se a turma foi retornada com sucesso 
                    {
                        printf("id invalido!");
                        break;
                    }

                    printf("digite o nome do aluno: "); // nome do aluno que deseja cadastra na hora 
                    scanf(" %[^\n]s", nome);

                    printf("digite a matricula : ");   // matricula do aluno que deseja cadastra na hora 
                    scanf("%d", &mat);

                    matricula_aluno(turma_procurada, mat, nome); // chama a funçao que se encarrega de matricular o novo aluno em uma turma ja criada
                    break;
                }
                else
                {
                    printf("sem vagas nas turmas!");    // mostra que nao tem mais vagas  
                    break;
                }
            }

            if (i == 0)    // verifica se foram criadas turmas 
            {
                printf("\nnenhuma turma cadastrada!\n");    // diz que nao tem nenhuma turma 
            }
            break;

        case 4:

            printf("digite o id: ");    // pedindo o id da turma que deseja cadastra as notas 
            scanf(" %c", &id);

            turma_procurada = procura_turma(turmas, i, id); // chama a funçao para procurar a  turma pelo id 

            if (turma_procurada == NULL)   // verifica se a turma foi retornada com sucesso
            {
                printf("TURMA INEXISTENTE!");
                break;
            }

            lanca_notas(turma_procurada);   // cadastra as notas de alunos matriculados em uma turma 

            break;
        case 5:
                printf("digite o id: ");  //pedindo o id da turma para imprimir os alunos e seus dados 
                scanf(" %c", &id);

                turma_procurada = procura_turma(turmas, i, id);// chama a funçao para procurar a  turma pelo id e guarda em uma variavel(ponteiro) turma auxiliar(turma_procurada) o endereço para a turma encontrada  

                if (turma_procurada == NULL)    // verifica se a turma foi retornada com sucesso
                {
                    printf("turma inexistente");
                    break;
                }
                imprime_alunos(turma_procurada);   // chama para imprimir os alunos e seus dados passando como parametro o endereço da turma encontrada 
            break;

        default:    // caso escolha a op que nao tem no menu
            printf("opcao invalida!");  
            break;
        }
    } while (op != 6);  // fim do do-while que se encerrar quando digite a op 6 que no menu diz sair 

    printf("Obrigado por usar este programa!"); // mostra que o programa foi encerrado 


    for (count_free = 0; count_free < MAX_TURMAS; count_free++) // liberando os espaços que alocou matriculando os alunos 
    {
        for(count2_free = 0 ;count2_free<MAX_VAGAS;count2_free++){
        free(turmas[count_free]->alunos[count2_free]);
    }}

    for (count_free = 0; count_free < MAX_TURMAS; count_free++)// liberando os espaços que alocou criando as turmas  
    {   
        free(turmas[count_free]);
    }

    free(turmas);   // / liberando os espaços que alocou para guardar as turmas 
    return 0;
}

//=======================================
//                funções
void menu(void)     // mini menu 
{
    printf("\nMENU:\n");
    printf("1 – Criar turma\n");
    printf("2 – Listar turmas\n");
    printf("3 – Matricular aluno\n");
    printf("4 – Lancar notas\n");
    printf("5 – Listar alunos\n");
    printf("6 – Sair\n\n");
}

Turma *cria_turma(char id)
{
    int count;
    Turma *turma = (Turma *)malloc(MAX_VAGAS * sizeof(Turma));  // alocando espaço para turma 
    turma->vagas = MAX_VAGAS;   // adicionando as vags 
    turma->id = id; // colocando seu id 
    for (count = 0; count < MAX_VAGAS; count++)   // prencher seu campos com null
    {
        turma->alunos[count] = NULL;
    }
    printf("Turma %c criada com sucesso!\n", id);   // dizendo que a turma foi criada com sucesso
    return (turma); // retornando a turma criada
}

void imprime_turmas(Turma **turmas, int n)  // mostra as turmas as vagas que tem nelas 
{
    int i, count, qtd_vagas;

    printf("\nTURMAS:\n");

    for (i = 0; i < n; i++)         
    {
        qtd_vagas = 0;// inicializa as qtd de vags a cada interaçao do for de fora 
        for (count = 0; count < MAX_VAGAS; count++)
        {
            if (turmas[i]->alunos[count] == NULL)   // verifica se ha vagas para alunos na turma
            {
                qtd_vagas++;    //somandos as vagas disponiveis 
            }
        }
        turmas[i]->vagas = qtd_vagas;   // adicionando as vagas disponiveis a turma
        printf("Turma %c – %d vagas disponíveis: \n", turmas[i]->id, turmas[i]->vagas); // mostra e as vagas 
    }
}

void matricula_aluno(Turma *turma, int mat, char *nome) // matricula alunos em uma turma 
{
    Aluno *criando_espaco_aluno = (Aluno *)malloc(sizeof(Aluno));   //alocando dinamicamente uma estrutura aluno 
    int cont_verifica_null, cont_inicializa; // variaveis auxiliares

    for (cont_inicializa = 0; cont_inicializa < QTD_NOTAS; cont_inicializa++)  // inicializando as suas notaas com zero  
    {
        criando_espaco_aluno->notas[cont_inicializa] = 0;
    }
    
    criando_espaco_aluno->media = 0;// inicializando a media com zero  
    criando_espaco_aluno->mat = mat; // passando a mantricula que foi pedida na main
    strcpy(criando_espaco_aluno->nome, nome);// passando o nome do aluno que foi pedido na main 

    for (cont_verifica_null = 0; cont_verifica_null < MAX_VAGAS; cont_verifica_null++)
    {
        if (turma->alunos[cont_verifica_null] == NULL)  // verifica se a turma->alunos tem lugar para colocar um novo aluno 
        {
            turma->alunos[cont_verifica_null] = criando_espaco_aluno;// colocando o aluno criado em um lugar no vertor de alunos de uma turma  
            break;
        }
    }

    printf("aluno cadastrado com sucesso!");    // mostra que o aluno foi cadastrados com sucesso 

    turma->vagas -= 1;      // reduzindo a qtd de vagas a cada novo aluno cadastrado 
}

Turma *procura_turma(Turma **turmas, int n, char id)    // uma funçao que ajuda a achar uma turma pelo seu id 
{
    int cont_turmas;

    for (cont_turmas = 0; cont_turmas < n; cont_turmas++)   // verifica se o id dado é igual ao da turma 
    {
        if (turmas[cont_turmas]->id == id)
        {
            return (turmas[cont_turmas]); // retorna a turma encontrada 
        }
    }

    return (NULL);  // retorna null se nao for encontrada a turma 
}

void lanca_notas(Turma *turma)      // pede as notas de uma turma 
{
    int cont_alunos, cont_notas;
    float soma = 0; // varialvel usada para soma as notas

    for (cont_alunos = 0; cont_alunos < MAX_VAGAS; cont_alunos++)  // for de fora para caminha de aluno em aluno  
    {
        if (turma->alunos[cont_alunos] != NULL)     // verificando se tem alunos  na turma 
        {
            printf("digite as notas do aluno : %s matricula: %d\n", turma->alunos[cont_alunos]->nome, turma->alunos[cont_alunos]->mat); // diz o nome e a matricula do aluno cadastrado na turma 

            for (cont_notas = 0; cont_notas < QTD_NOTAS; cont_notas++) // for de dentro para caminha entre as notas 
            {
                printf("digite  a nota n° %d: ", cont_notas + 1);   // pede as notas do aluno 
                scanf("%f", &turma->alunos[cont_alunos]->notas[cont_notas]);
            }
        }
    }

    for (cont_alunos = 0; cont_alunos < MAX_VAGAS; cont_alunos++)
    {
        if (turma->alunos[cont_alunos] != NULL) // verificando se tem aluno cadastrado na turma 
        {
            soma = 0;   // inicilizando soma com zero a cada interaçao do laço para nao misturar as notas dos alunos
            for (cont_notas = 0; cont_notas < QTD_NOTAS; cont_notas++)
            {
                soma += turma->alunos[cont_alunos]->notas[cont_notas];  // somando as notas
            }
            turma->alunos[cont_alunos]->media = soma / QTD_NOTAS; // fazendo a media e guardado a no campo media do aluno  
        }
    }
}

void imprime_alunos(Turma *turma)   // mostra todos os alunos matriculados em uma turma  
 {

    int cont_alunos,verifica_null=0;    // variaveis uma para o laço de repetiçao e outra para auxiliar

    for (cont_alunos = 0; cont_alunos < MAX_VAGAS; cont_alunos++)   // mostra os alunos cadastrados  
    {
        if (turma->alunos[cont_alunos] != NULL)     // verifica se tem alunos 
        {
            printf("nome: %s\n", turma->alunos[cont_alunos]->nome);
            printf("matricula: %d\n", turma->alunos[cont_alunos]->mat);
            printf("media: %f\n", turma->alunos[cont_alunos]->media);
                 verifica_null++;   // auxilia na verificação se tem alunos cadastrados 
        }
    }
         
        if(verifica_null == 0){      //verifica se tem alunos cadastrados 

            printf("nenhum aluno cadastrado");  
        }
}
