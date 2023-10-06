#include <stdio.h>
#include <locale.h>
#include "contato.cpp"
#include "funcoes.c"


int main(void) {
  setlocale(LC_ALL,"Portuguese"); // comando para trabalhar com Portugês no código
  //variáveis para calcular o tempo de execução
  int escolha = 0;
  
  Contato* agenda[SIZE];
  iniciar_agenda(agenda);

  ler_agenda(agenda);

  char nome[MAX_CHAR];
  char email[MAX_CHAR];


  do{
    
    // imprime_menu();
    printf("digite a opção que deseja: ");
    escolha =  somente_numeros(); // para garantir que o usuário digite apenas números
    switch(escolha){
      case 1://inserir produto

        // printf("\n\ninserindo novo produto...\n");
        // printf("digite o nome do produto: ");
        // scanf(" %[^\n]",tipo);
        // minuscula(tipo);//para retirar os caracteres especiais e deixar o texto todo em minusculo
        // printf("digite o preço do produto: ");
        // scanf("%f",&preco);
        // printf("digite a data de validade do produto(DD/MM/AAAA): ");
        // scanf(" %[^\n]",validade);
        // printf("digite a data de fabricação do produto(DD/MM/AAAA): ");
        // scanf(" %[^\n]",fabricacao);
        // printf("digite a quantidade desse produto em estoque: ");
        // scanf("%d",&estoque);
        // printf("digite o nome do departamento em que esse produto vai estar: ");
        // scanf(" %[^\n]",nome_departamento);
        // minuscula(nome_departamento);
        // // if(verifica_departamento_existe(departamentos,nome_departamento) == 0){//verificando se o departamento digitado pertence no sistema
        // //   produto_buscado = busca_produto(departamentos, tipo);
        // // if(produto_buscado != NULL){ //verificando se o produto já existe no sistema
        //  //insere_novo_produto(departamentos,tipo,validade,fabricacao,estoque,nome_departamento,preco);
        // // }else{
        // //   printf("\no produto %s já existe no sistema\n",tipo);
        // // }
        // // }else{
        // //   printf("departamento não encontrado");
        // // }
        

        break;
      case 2://remover produto
      
        printf("removendo produto...\n");
        printf("digite o nome do contato que deseja retirar: ");
        scanf(" %[^\n]",nome);
        minuscula(nome);
        removeContato(agenda, nome);
  
        break;
      case 3://listar produtos cadastrados

        printf("\nListando os departamentos:\n\n");
        // lista_departamento_imprime(departamentos );
  
       break;
      case 4://editar produto

        printf("editando produto...\n");
        printf("digite o nome do contato que deseja editar: ");
        scanf(" %[^\n]",nome);
        minuscula(nome);
        //editar_produto(agenda,  nome);
        break;
      case 5://buscar produto

        printf("Buscando produto...\n");
        printf("digite o nome do contato que deseja buscar: ");
        scanf(" %[^\n]",nome);
        minuscula(nome);
        // //produto_buscado = busca_produto(departamentos, produto_procurado);
        // if(produto_buscado == NULL){//verifica se o produto que foi buscado existe
        //   printf("produto não encontrado");
        // }else{
        //   printf("nome do departamento que se encontra o produto: %s\n",produto_buscado->nome_departamento);
        //   printf("preço do produto: %.2f\n",produto_buscado->preco);
        //   printf("data de fabricação do produto: %s\n",produto_buscado->fabricacao);
        //   printf("data de validade do produto: %s\n",produto_buscado->validade);
        //   printf("quantidade disponivel em estoque: %d\n\n",produto_buscado->estoque);
        // }
  
        break;
      case 8://sair

        printf("\n|finalização do progama|\n");
        exportar(agenda);

        break;
      default:

        printf("\no numero digitado não está entre as opções\n\n");

        break;
    }
    
  }while(escolha!=8);

  // libera_memoria(departamentos); // libera a memoria alocada

  return 0;
}