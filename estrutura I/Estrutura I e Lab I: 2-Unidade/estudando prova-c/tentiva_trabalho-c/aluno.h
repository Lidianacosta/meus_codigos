typedef struct aluno Aluno;

int ler_aluno(Aluno *a);

void menu(void);

void imprime_alunos(Aluno* a, int qtd_alunos);

void criar_alunos(Aluno* a, int qtd_alunos);

int busca_interpolada_mat(Aluno* a,int qtd_alunos, int mat);
