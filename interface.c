#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. ATUALIZAR");
    printf("  \n\t6. SAIR");
}

void MENU(TLista *lista){
    TProduto produto;
    int opcao=0;
    int i;

    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                system("cls");
                lerProduto(&produto);
                inserirCrescente(lista, produto);
                break;

            case 2:
                system("cls");
                printf("\n=========== Pesquisar produto ===========");
                printf("\nDigite o codigo: ");
                scanf("%d", &produto.codigo);
                printf("\n=========================================");

                TCelula* resultadoPesquisa = pesquisar(*lista, produto);

                if (resultadoPesquisa != NULL){
                    imprimirProduto(resultadoPesquisa -> prox -> item);
                } else
                    printf("\nProduto nao cadastrado");
                system("pause");
                break;

            case 3:
                system("cls");
                printf("\n============ Excluir produto ============");
                printf("\nDigite o codigo: ");
                scanf("%d", &produto.codigo);
                printf("=========================================");

                resultadoPesquisa = pesquisar(*lista, produto);

                if (resultadoPesquisa != NULL){
                    produto = resultadoPesquisa -> prox -> item;
                    excluir(lista, &produto);
                } else
                    printf("\nProduto nao cadastrado\n\n");
                system("pause");
                break;

            case 4:
                system("cls");
                if (lista -> tamanho > 0)
                    imprimir(*lista);
                else
                    printf("\nNenhum item cadastrado ainda.\n");
                system("pause");
                break;

            case 5:
                system("cls");
                printf("\n=========== Pesquisar produto ===========");
                getchar();
                printf("\nNome: ");
                fflush(stdin);
                fgets(produto.nome, 20, stdin);
                printf("=========================================");

                resultadoPesquisa = pesquisarPorNome(*lista, produto);

                if (resultadoPesquisa != NULL){
                    atualizar(lista, produto);
                } else
                    printf("\nProduto nao cadastrado\n");

                system("pause");
                break;

            case 6:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n");
                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            }

    } while(opcao != 6);
}
