//DEFINES DA PILHA
#define TAM_PILHA 10
#define VERD 1
#define FALSO 0
#define ERRO -1

//DEFINES DA FILA
#define  TAMANHO_DA_FILA 10

//STRUCT DA PILHA
struct pilha {
    float itens[TAM_PILHA];
    int topo;
    float dado;
};typedef struct pilha PILHA;

//STRUCT DA FILA
struct fila {
    float itens[TAMANHO_DA_FILA];
    int frente;
    int atras;
    float dado;
};typedef struct fila FILA;

//ASSINATURAS DOS MENUS
int menuTipo(int* tipoPF);
int menuPilha(int* op);//MENU PILHA
int menuFila(int* op);

//ASSINATURAS DAS FUNÇÕES DE PILHA

void iniciaPilha(int *Topo);
int pilhaVazia(int *Topo);
int pilhaCheia(int *Topo);
int push(float P[], int *Topo, float valor);
int pop(float P[], int *Topo, float *valor);
void exibirPilha(float P[], int *Topo);

//ASSINATURAS DAS FUNÇÕES DE FILA
int verificaFilaVazia (FILA *pq);
int verificaFilaCheia (FILA *pq);
void inserirItem (FILA *pq, int itemMain);
int tamanhaDaFila (FILA *pq);
float frenteDaFila (FILA *pq);
float removerDaFila(FILA *pq);
void exibirFila(FILA *pq);
void esvaziarFila(FILA *pq);

//FUNÇÕES DA PILHA ====================================================================================

int menuTipo(int* tipoPF) {
    printf("\nEscolha se deseja o tipo 1-Pilha || 2-Fila || 0-Fim\n\nOpção: ");
    scanf("%d", tipoPF);
    return(*tipoPF);
}

int menuPilha(int* op){
    printf("\n\n Menu\n 1-Inserir\n 2-Excluir\n 3-Exibir Vetor\n 4-Mudar tipo de fila ou pilha\n 0-Fim\n Opcao: ");
    scanf("%d", op);
    return(*op);
}

void iniciaPilha(int *Topo) {
    *Topo = -1;
}

int pilhaVazia(int *Topo) {
    if(*Topo == -1)  return(VERD);
    return(FALSO);
}
int pilhaCheia(int *Topo) {
    if(*Topo == TAM_PILHA -1) return(VERD);
    return(FALSO);
}

int push(float P[], int *Topo, float valor) {
    if(pilhaCheia(Topo)) {
        printf( "Erro -Ins. Pilha cheia");
        return(ERRO);
    }else{
        (*Topo)++;
        P[*Topo] = valor;
    }
    return(VERD);
}

int pop(float P[], int *Topo, float *valor) {
    if(pilhaVazia(Topo)) {
        printf("Erro -Pilha vazia");
        return(ERRO);
    }else{
        *valor = P[*Topo];
        (*Topo)--;
    }
    return(VERD);
}

void exibirPilha(float P[], int *Topo){
    int i;
    printf("\nExibir elementos preenchidos da Pilha\n");
    for(i=0;i<=*Topo;i++){
        printf( "\nElemento[%d]: %.2f ", i+1, P[i]);
    }
    printf( "\n");
}

//FUNÇÕES DA FILA =====================================================================================

int menuFila(int* op){
    printf("\n\n Menu\n 1-Inserir\n 2-Excluir\n 3-Exibir Vetor\n 4-Esvaziar a filar\n 5-Mudar tipo de fila ou pilha\n 0-Fim\n Opcao: ");
    scanf("%d", op);
    return(*op);
}

int verificaFilaVazia (FILA *pq){
    if(pq->frente != pq->atras){
        return 0;
    }else{
        return 1;
    }
}

int verificaFilaCheia (FILA *pq){
  if(pq->atras >= TAMANHO_DA_FILA){
        return 1;
    }else{
        return 0;
    }
}

void inserirItem (FILA *pq, int itemMain){
    if(verificaFilaCheia(pq)){
        printf("\n\n *****Não foi possível inserir o item pois a fila está cheia*****\n\n");
    }else{
        pq->itens[pq->atras++] = itemMain;
    }
}

int tamanhaDaFila (FILA *pq){
    return pq->atras;
}

//consulta o proximo item a ser acessado na fila
float frenteDaFila (FILA *pq){
    return pq->itens[0];
}

float removerDaFila(FILA *pq){
    int i;

    if (verificaFilaVazia(pq)){
        printf("\n\n A fila está vazia, não tem o que remover.");
        return 0;
    }

    float x = frenteDaFila(pq);

    for(i = 0;  i < tamanhaDaFila(pq); i++){
        pq->itens[i] = pq->itens[i+1];
    }

    pq->atras--;
    return x;
}

void exibirFila(FILA *pq){
    if(verificaFilaVazia(pq)){
        printf("\n\n A fila está vazia, não tem o que exibir.");
    }else{
        printf("\n\n-------Exibindo todos os elementos da fila-------");
        for(int i = 0; i < tamanhaDaFila(pq); i++){
            printf("\n Fila[%d]: %.2f", (pq->frente+i)+1, pq->itens[pq->frente+i]);
        }
        printf("\n\n");
    }
}

void esvaziarFila(FILA *pq){
    int tam = tamanhaDaFila(pq);
    int i;

    printf("\n----------Esvaziando a fila----------");
    for (i=0; i < tam; i++){
        printf("\n Item %.2f retirado da fila", removerDaFila(pq));
    }

}






