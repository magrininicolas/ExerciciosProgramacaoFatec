#ifndef ARVOREBINARIA_ARVOREBINARIA_H
#define ARVOREBINARIA_ARVOREBINARIA_H

// structs
struct no {
    struct no *esquerda;
    int dado;
    struct no *direita;
};

// Variáveis
extern struct no* inicio;
extern struct no* anterior;
extern struct no* direita;
extern struct no* esquerda;

// Protótipos
void adicionar(struct no *aonde, struct no *quem);
struct no *novoNo(int dado);
void inicializar();
void finalizar(struct no *aonde);

struct no* busca(struct no* arvore, int dado);
void excluir(struct no* arvore);

#endif //ARVOREBINARIA_ARVOREBINARIA_H

