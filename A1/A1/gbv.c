#include <stdio.h>
#include "gbv.h"

//estrutura do superbloco
typedef struct {
    int num_docs; //numero de documentos
    long int offset_dir; //posicao onde comeca o diretorio

} superblock;

int gbv_create(const char *filename) {
    FILE* file = fopen(filename, "wb");
    if (!file)
        return -1;

    //superbloco
    int num_docs = 0; //biblioteca comeca vazia
    long  offset_dir = sizeof(int) + sizeof(long); //que tamanho o superbloco deve comecar?

    //escreve no superbloco
    fwrite(&num_docs, sizeof(int), 1, file); //escreve numero de docs
    fwrite(&offset_dir, sizeof(long), 1, file); //escreve offset

    fclose(file);
    return 0; //retorna 0 em caso de sucesso
}

//alocar memoria parao vetor de documento
// a area de diretorio eh um vetor de struct documents
int gbv_open(Library *lib, const char *filename) {
    FILE* file = fopen(filename, "rb");

    int num_docs;
    long offset_dir;

    //le o superbloco
    fread(&num_docs, sizeof(int), 1, file);
    fread(&offset_dir, sizeof(long), 1, file);

    //


}

int gbv_add(Library *lib, const char *archive, const char *docname) {

}
int gbv_remove(Library *lib, const char *docname) {

}

int gbv_list(const Library *lib){

}

int gbv_view(const Library *lib, const char *docname) {

}

int gbv_order(Library *lib, const char *archive, const char *criteria) {
    
}