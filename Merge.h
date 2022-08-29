typedef struct dados_vetor Dados;

Dados *create(int tam);
int size(const Dados *vector);
int at(const Dados *vector, int pos);
int get(const Dados *vector, int indc);
int set(Dados *vector, int index, int novo_valor);
void adicionar(Dados *vector, int valor);
void destroy(Dados **busc_vector);
void merge(Dados *vector, int inicio, int meio, int fim);
void mergesort(Dados *vector, int inicio, int fim);
void salva_dados(const Dados *vector);