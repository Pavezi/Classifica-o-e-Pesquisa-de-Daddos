printf(" IMPLEMENTAÇÃO ENDEREÇAMENTO ABERTO (EMMEMÓRIA PRINCIPAL) \n");
 typedef struct aluno {
int matricula;
float cr;
} TAluno;
typedef TAluno *Hash; //Hash é um vetor que será alocado dinamicamente
void inicializa(Hash *tab, int m) {
int i;
for (i = 0; i < m; i++) {
tab[i] = NULL;
}
}
int hash_linha(int mat, int m) {
return mat % m;
}
int hash(int mat, int m, int k) {
return (hash_linha(mat, m) + k) % m;
}
/*
* Função busca
RETORNO:
Se chave mat for encontrada, achou = 1,
função retorna endereço onde mat foi encontrada
Se chave mat não for encontrada, achou = 0, e há duas
possibilidades para valor retornado pela função:
endereço de algum compartimento livre encontrado durante a busca
-1 se não for encontrado endereço livre (tabela foi percorrida até
o final)
*/
int busca(Hash *tab, int m, int mat, int *achou) {
*achou = 0;
int end = -1;
int pos_livre = -1;
int k = 0;
while (k < m) {
end = hash(mat, m, k);
if (tab[end] != NULL && tab[end]->matricula == mat) {//encontrou chave
*achou = 1;
k = m; //força saída do loop
}
else {
if (tab[end] == NULL) {//encontrou endereço livre
pos_livre = end;
k = m; //força saída do loop
}
else k = k + 1; //continua procurando
}
}
if (*achou)
return end;
else
return pos_livre;
}
// Função assume que end é o endereço onde será efetuada a inserção
void insere(Hash *tab, int m, int mat, float cr) {
int achou;
int end = busca(tab, m, mat, &achou);
if (!achou) {
if (end != -1) {//Não achou a chave, mas achou posição livre
//Inserção será realizada nessa posição
tab[end] = aloca(mat, cr);
} else {
//Não foi encontrada posição livre durante a busca: overflow
printf("Ocorreu overflow. Inserção não realizada!\n");
}
} else {
printf("Matricula já existe. Inserção inválida! \n");
}
}
