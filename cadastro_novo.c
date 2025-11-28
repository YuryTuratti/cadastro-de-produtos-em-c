#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct produtos{
    char nome [255];
    float valor ;
    int estoque;
    int id;
};

//struct global 
struct produtos lista[255];
int totalprodutos = 0;


void addEspaco();
 
void limparBuffer();

int idUsados[1000] = {0}; // gerar um numero de 0 a 999
int gerirIDUnico();

void buscaId();

void cadastro();

void novoEstoque();

void removerProduto();

int main (){

    int opc;
    
    while(1){
    
        printf("_____----- BEM VINDO AO MENU -----_____ \n");
    
        printf(" 1 - cadastro \n");
        printf(" 2 - busca por id \n");
        printf(" 3 - atualizar estoque \n");
        printf(" 4 - remover produto ");
        addEspaco();
        scanf("%d", &opc);
        limparBuffer();

        while(opc < 1 || opc > 4){
            printf("escolha entre as opcoes enumeradas \n");
            scanf("%d", &opc);
            limparBuffer();
        }

        if (opc ==1 ){
            cadastro();
        }

        if (totalprodutos > 0){
            if (opc == 2){
                //buscar por id
                buscaId();
            }
            else if (opc == 3){
                //atualizar estoque
                novoEstoque();
            }
            else if (opc == 4){
                //remover produto 
                removerProduto();
            }
        }

        else if(totalprodutos == 0) {
            printf("para acessar as outras opcoes necessita ter ao menos um produto cadastrado");
        }

        addEspaco();
        printf("deseja retornar ao menu : \n");
        printf(" 1 - sim \n");
        printf(" 2 - nao \n");
        scanf("%d", &opc);
        limparBuffer();

        while(opc<1 || opc >2){
            printf("digite uma das opcoes listadas \n");
            scanf("%d", &opc);
            limparBuffer();
        }

         if(opc == 2){
            printf("saindo...");
            break;
        }

    }

    return 0;
}

void addEspaco()
{
    printf("\n---------------------\n"); // add barra divisoria
}

void limparBuffer()
{
    int c; // limpar buffer para nao dar erro
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int gerirIDUnico()
{
    int id;
    do
    {
        id = rand() % 1000; // IDs de 0 a 999
    } while (idUsados[id] == 1);

    idUsados[id] = 1; // marca o ID como usado
    return id;
}

void cadastro(){
    srand(time(NULL));

    int  quantidade;

    addEspaco();
    printf("\n  CADASTRO   \n");
    addEspaco();

    printf("qual a quantidade de produtos deseja cadastrar : \n");
    scanf("%d", &quantidade);
    limparBuffer();

    for(int i = 0 ; i < quantidade; i++){
        
        printf("nome : \n");
        fgets(lista[totalprodutos].nome,255,stdin);
        
        printf("valor : \n");
        scanf("%f", &lista[totalprodutos].valor);
        limparBuffer();

        while(lista[totalprodutos].valor <= 0){
           
            printf("o valor nao pode ser 0 ou negativo , digite novamente : \n");
            printf("valor : \n");
            scanf("%f", &lista[totalprodutos].valor);
            limparBuffer();
        }


        printf("estoque : \n");
        scanf("%d", &lista[totalprodutos].estoque);
        limparBuffer();

        while(lista[totalprodutos].estoque <=0 ){
           printf("estoque nao permitido , repita : \n");
            printf("estoque : \n");
            scanf("%d", &lista[totalprodutos].estoque);
            limparBuffer();

        }

        lista[totalprodutos].id = gerirIDUnico();
        totalprodutos++;
        

        for(int j = 0; j < quantidade ; j++){
            addEspaco();
            printf("produto %d  \n", j+1);
            printf("nome : %s ", lista[j].nome);
            printf("valor : %.2f \n", lista[j].valor);
            printf("estoque : %d \n", lista[j].estoque);
            printf("id: %d", lista[j].id);
            addEspaco();
        }


    }






}

void buscaId(){
    int idBuscado;
    int encontrados = 0;

    printf("digite o id do produto : \n");
    scanf("%d", &idBuscado);
    limparBuffer();

    for(int k = 0; k < totalprodutos ; k++){
        if(idBuscado == lista[k].id){
            printf("produto encontrado \n");
            printf("nome : %s ", lista[k].nome);
            printf("valor : %.2f \n", lista[k].valor);
            printf("estoque : %d \n", lista[k].estoque);
            encontrados++;
            break;
        }
        
        else if(encontrados == 0) {
            printf("id nao registrado \n");
        }
    }
}

void novoEstoque(){
    int idBuscado;
    int encontrados = 0;

    printf("digite o id do produto : \n");
    scanf("%d", &idBuscado);
    limparBuffer();

    for(int k = 0; k < totalprodutos ; k++){
        if(idBuscado == lista[k].id){
            printf("produto encontrado \n");
            printf("nome : %s ", lista[k].nome);
            printf("valor : %.2f \n", lista[k].valor);
            printf("estoque : %d \n", lista[k].estoque);
            encontrados++;

            printf("digite o nova quantia em estoque : \n");
            scanf("%d", &lista[k].estoque);
            printf("estoque atualizado");
            break;
        }
        
        else if(encontrados == 0) {
            printf("id nao registrado \n");
        }
    }
}

void removerProduto(){
    int idBuscado , k;
    int encontrados = 0;

    printf("digite o id do produto : \n");
    scanf("%d", &idBuscado);
    limparBuffer();

    for(k = 0; k < totalprodutos ; k++){
        if(idBuscado == lista[k].id){
            printf("produto encontrado \n");
            printf("nome : %s ", lista[k].nome);
            printf("valor : %.2f \n", lista[k].valor);
            printf("estoque : %d \n", lista[k].estoque);
            encontrados++;
            
            for(int j = k ; j < totalprodutos - 1 ;j++){
                
                lista[j]=lista[j + 1];
            }

            totalprodutos--;
            printf("produto removido com sucesso");
            break;
        }
        
        else if(encontrados == 0) {
            printf("id nao registrado \n");
        }
    }


}