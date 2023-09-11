
typedef struct aluno Aluno;

void ler_aluno(Aluno *a);

void menu(void);

void imprime_alunos(Aluno* a, int qtd_alunos);

void criar_alunos(Aluno* a, int qtd_alunos);

int busca_interpolada_mat(Aluno* a,int qtd_alunos, int mat);

int busca_interpolada_nome(Aluno* a,int qtd_alunos, char* nome);

void salva_alunos(Aluno* a,int qtd_alunos);
