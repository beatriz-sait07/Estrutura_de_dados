typedef struct _node_simples{
    int valor;
    struct _node_simples *next;
}Node_simples;

typedef struct _lista_simples{
    Node_simples *inicio;
    Node_simples *fim;
    int size;
}Lista;