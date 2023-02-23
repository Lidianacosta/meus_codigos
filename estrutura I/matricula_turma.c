#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_VAGAS 3
#define MAX_TURMAS 2

typedef struct aluno
{
    int mat;
    char nome[50];
    float notas[3];
    float media;
} Aluno;

typedef struct turma
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];

} Turma;

//=======================================================
//                    funções
Turma *cria_turma(char id);

void menu(void);

void imprime_turmas(Turma **turmas, int n);

void matricula_aluno(Turma *turma, int mat, char *nome);

// void lanca_notas(Turma *turma);

// void imprime_alunos(Turma *turma);



Turma *procura_turma(Turma **turmas, int n, char id);

//========================================================

int main()
{
    int op, i = 0, count, cont_alunos,cont_turmas,mat,cont_id;
    char id,nome[50];
    Turma **turmas = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));

    do
    {
        menu();
        printf("digite sua opção: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            if (i < MAX_TURMAS)
            {
                printf("digite o id da turma que deseja cadastrar: ");
                scanf(" %c", &id);
                turmas[i] = cria_turma(id);
                i++; 
            } 
            else
            {
                printf("nao ha mais vagas para criar turmas\n");
            }
            break;
        case 2:
                    imprime_turmas(turmas,i);
            break;
        case 3:
            for(cont_turmas = 0 ;cont_turmas<i;cont_turmas++){
                for(cont_alunos = 0 ;cont_alunos<MAX_VAGAS;cont_alunos++){

                  if (turmas[cont_turmas]->alunos[cont_alunos] == NULL){
             
                         printf("digite o id: ");
                         scanf(" %c",&id);
              	
		        	for(cont_id;cont_id<i;cont_id++){
			  	        if (turmas[cont_turmas]->id == id){
			  
            	
              	        printf("digite o nome do aluno: ");
               	        scanf(" %[^\n]s",nome);
                
                    	printf("digite a matricula : ");
                    	scanf("%d",&mat);
                    	//printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
             	  
             	        matricula_aluno(turmas[cont_id],mat,nome);
         	        	}  
		             }

                 }else{
                     printf("sem vagas nas turmas!");
                 }   

              }       
                
            }

       
        
        break;
        }
       
    } while (op != 6);

    for (count = 0; count < MAX_TURMAS; count++)
    {
        free(turmas[count]);
    }

    free(turmas);
    return 0;
}
//=======================================
//                funções
 void menu(void)
{
    printf("\nMENU:\n");
    printf("1 – Criar turma\n");
    printf("2 – Listar turmas\n");
    printf("3 – Matricular aluno\n");
    printf("4 – Lancar notas\n");
    printf("5 – Listar alunos\n");
    printf("6 – Sair\n");
}

Turma *cria_turma(char id)
{
    int count;   
    Turma *turma = (Turma *)malloc(MAX_VAGAS * sizeof(Turma));   
    turma->vagas = MAX_VAGAS;
    turma->id = id;
for (count = 0; count < MAX_VAGAS; count++)
    {
         turma->alunos[count] = NULL;
    }
    printf("Turma %c criada com sucesso!", id);
    return(turma);
}

void imprime_turmas(Turma **turmas, int n){
 int i,count,qtd_vagas;   
    printf("TURMAS: \n");
    for(i = 0; i < n; i++){
        qtd_vagas =0;
        for(count = 0 ;count <MAX_VAGAS;count++){
            if (turmas[i]->alunos[count] == NULL){
               qtd_vagas++;
            }   
        }
        turmas[i]->vagas = qtd_vagas;
        printf("%c: ",turmas[i]->id);
        printf("%d\n",turmas[i]->vagas);

    }
}

void matricula_aluno(Turma *turma, int mat, char *nome){
    //printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");

int cont_verifica_null,verifica_aluno_notas;

	for(cont_verifica_null = 0;cont_verifica_null <MAX_VAGAS;cont_verifica_null++){
	printf("a\t");
		if(turma->alunos[cont_verifica_null] == NULL){
	printf("aaaaaaaaa\t");
	
		turma->alunos[cont_verifica_null]->mat = mat;
		printf("aaaaaaaaa\t");
		
		strcpy(nome,turma->alunos[cont_verifica_null]->nome);
			printf("aaaaaaaaa\n");
			
			
			verifica_aluno_notas = cont_verifica_null;
		}

	}

for(cont_verifica_null = 0;cont_verifica_null <MAX_VAGAS;cont_verifica_null++){
		turma->alunos[verifica_aluno_notas]->notas[cont_verifica_null] = 0;	
	}
	
	printf("aluno cadastrado com sucesso!");
	
	turma->vagas-=1;
}




