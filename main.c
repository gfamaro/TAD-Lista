#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main()
{
    system("title CADASTRO DE PRODUTOS");
    TLista lista;

    FLVazia(&lista);

    if (!verificaVazia(lista))
        return 0;

    MENU(&lista);

    liberarLista(&lista);

    return 0;
}
