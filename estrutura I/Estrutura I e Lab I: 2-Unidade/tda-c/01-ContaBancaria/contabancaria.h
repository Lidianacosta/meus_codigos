typedef struct ContaBancaria ContaBancaria;

ContaBancaria* cria_conta(char* titular, int numero_conta, float saldo);

void deposita(ContaBancaria* conta, float valor_deposita);

void saca(ContaBancaria* conta, float valor_sacar);

void transfere(ContaBancaria* conta_trasfere, ContaBancaria* conta_recebe, float valor_trasferencia);

float saldo(ContaBancaria* conta);

void exclui_conta(ContaBancaria* conta);
