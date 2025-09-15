#include <stdio.h>
#include "gbv.h"

//estrutura do superbloco
typedef struct {
    long qnt_documentos;
    long int offset_dire;

} superbloco;


int gbv_create(const char *filename) {

}
int gbv_open(Library *lib, const char *filename) {

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