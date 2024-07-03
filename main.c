#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um elemento já está presente no vetor
int estaNoVetor(int elemento, int resultado[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (resultado[i] == elemento) {
            return 1; 
        }
    }
    return 0; 
}

int valNM(float num) // FUNCAO PARA VALIDAR O N E M
{
    if((int)num == num && (num>0 && num<=30)) return 1; // VALIDO = 1, INVALIDO = 0
     else return 0;
}
int isnat(float num) // FUNCAO PARA VALIDAR OS NUMEROS NATURAIS
{
     if((int)num == num && num>0) return 1; // VALIDO = 1, INVALIDO = 0
     else return 0;
}
void interF(int vetA[], int vetB[], int n, int m) // FUNCAO PARA INTERSECÇÃO DOS DOIS VETORES
{  
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vetA[i]==vetB[j])
            {
                printf("%d ", vetA[i]);
                break;
            }
        }
    }
    printf("\n");
}

void uniF(int vetor1[], int vetor2[], int tamanho1, int tamanho2) { // FUNCAO PARA UNIÃO DOS DOIS VETORES
    int resultado[tamanho2+tamanho1], tam = 0;
    for (int i = 0; i < tamanho1; i++) {
        // Adiciona o elemento ao vetor resultante se ainda não estiver presente
        if (!estaNoVetor(vetor1[i], resultado, tam)) {
            resultado[tam] = vetor1[i];
            (tam)++;
        }
    }

    for (int i = 0; i < tamanho2; i++) {
        // Adiciona o elemento ao vetor resultante se ainda não estiver presente
        if (!estaNoVetor(vetor2[i], resultado, tam)) {
            resultado[tam] = vetor2[i];
            (tam)++;
        }
    }
    
    for (int i=0; i<tam; i++) printf("%d ", resultado[i]);
    
    printf("\n");
    
}

void concF(int vetA[], int vetB[], int n, int m) // FUNCAO PARA CONCATENAR OS VETORES
{   int tam=n+m;
    int resultado[tam];
    for(int i=0; i<n; i++) resultado[i]=vetA[i];
    for(int i=0; i<m; i++) resultado[i+n]=vetB[i];
    for(int i=0; i<tam; i++) printf("%d ", resultado[i]);
    
    printf("\n");
}

void subF(int vetor1[], int vetor2[], int tamanho1, int tamanho2) { // FUNCAO PARA SUBTRAIR OS VETORES
    int resultado[tamanho2+tamanho1], tam = 0;
    for (int i = 0; i < tamanho1; i++) {
        // Adiciona o elemento ao vetor resultante se ainda não estiver presente
        if (!estaNoVetor(vetor1[i], vetor2, tamanho2)) {
            resultado[tam] = vetor1[i];
            (tam)++;
        }
    }
    
    for (int i=0; i<tam; i++) printf("%d ", resultado[i]);
    
    printf("\n");
    
}

int findF(int v1[], int tam, int n) { // FUNCAO PARA ACHAR UM ELEMENTO NOS VETORES
    int i;
    for (i = 0; i < tam && v1[i]!=n; i++);
    if(i<tam) return i;
    else return -1;
    
}

void escF(int v2[], int tam, int n) // FUNCAO PARA MULTIPLICAR O SEGUNDO VETOR POR UM ESCALAR
{int res;
    for(int i=0; i<tam; i++)
    {
        res=v2[i]*n;
        printf("%d ",res);
    }
}

int prodF(int v1[], int v2[], int tam) // FUNCAO PARA CALCULAR O PRODUTO ESCALAR DE 2 VETORES
{
    int res=0;
    for(int i=0; i<tam; i++)
    {
        res+=v2[i]*v1[i];
    }
    return res;
}

void cresF(int v1[], int tam) // FUNCAO PARA CLASSIFICAR O VETOR EM ORDEM CRESCENTE
{   int aux;
    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam-1; j++)
        {
            if(v1[i]<v1[j])
            {
                aux=v1[i];
                v1[i]=v1[j];
                v1[j]=aux;
            }
        }
    }
    for(int i=0; i<tam; i++)
    {
        printf("%d ", v1[i]);
    }
}

void intercalarF(int vetor1[], int tamanho1, int vetor2[], int tamanho2, int resultado[]) { // FUNCAO PARA INTERCALAR OS DOIS VETORES ORDENADOS
    int i = 0, j = 0, k = 0;
    // se forem do msm tamanho
    while (i < tamanho1 && j < tamanho2) {
        if (vetor1[i] < vetor2[j]) {
            resultado[k] = vetor1[i];
            i++;
        } else {
            resultado[k] = vetor2[j];
            j++;
        }
        k++;
    }
    // se A>B
    while (i < tamanho1) {
        resultado[k] = vetor1[i];
        i++;
        k++;
    }
    // se B>A
    while (j < tamanho2) {
        resultado[k] = vetor2[j];
        j++;
        k++;
    }
}

void armF(int v1[], int v2[], int tam) // FUNCAO PARA ARMAZENAR O VETOR B NO VETOR A
{
    for(int i=0; i<tam; i++)
    {
        v1[i]=v2[i];
    }
}

int main()
{
    int n,m,tam,esc; // DECLARACAO DE VARIAVEIS
    bool ord1=false, ord2=false;
    printf("Digite o tamanho do vetor A: "); // lENDO O N DO VETOR A
    scanf("%d", &n);
    while(valNM(n)!= 1)
        { // VALIDACAO DO N
        printf("Digite um número maior q 0 e menor ou igual a 30!\n");
        printf("Digite o tamanho do vetor A: ");
        scanf("%d", &n);
        }
    printf("Digite o tamanho do vetor B: "); // LENDO O M DO VETOR B
    scanf("%d", &m);
    while(valNM(m)!= 1)
        { // VALIDACAO DO M
        printf("Digite um número maior q 0 e menor ou igual a 30!\n");
        printf("Digite o tamanho do vetor B: ");
        scanf("%d", &m);
        }
    int vetA[n], vetB[m];
    for(int i=0; i<n; i++)
    { // LENDO O VETOR A
        printf("Digite o valor do vetor A na posicao [%d]: ",i);
        scanf("%d", &vetA[i]);
        while(isnat(vetA[i])!=1)
        { // VALIDACAO VETOR A
            printf("Digite um número natural!\n");
            printf("Digite o valor do vetor A na posicao [%d]: ",i);
            scanf("%d", &vetA[i]);
        }
    }
    for(int j=0; j<m; j++)
    { // LENDO O VETOR B
        printf("Digite o valor do vetor B na posicao [%d]: ",j);
        scanf("%d", &vetB[j]);
        while(isnat(vetB[j])!=1)
        { // VALIDACAO VETOR B
            printf("Digite um número natural!\n");
            printf("Digite o valor do vetor B na posicao [%d]: ",j);
            scanf("%d", &vetB[j]);
        }
    }
    int opc=0;
    while(opc!=-1)
    {   printf("\n-------------------------------------------\n");
        printf("\tOPERACOES COM VETORES\n");
        printf("1 para calcular a intersecçao dos dois vetores\n2 para calcular a uniao dos dois vetores\n3 para calcular a Concatenaçao dos dois vetores\n4 para calcular a subtraçao de dois vetores\n5 para pesquisar se um dado valor existe no primeiro vetor\n6 para multiplicar o segundo vetor por um escalar\n7 para calcular o produto escalar dos dois vetores\n8 para classificar o primeiro vetor em ordem crescente\n9 para classificar o segundo vetor em ordem crescente\n10 para intercalar os dois vetores ordenados\n11 para armazenar o vetor B no vetor A\n-1 para encerrar o programa\n");
        printf("\nDigite uma opçao: ");
        scanf("%d", &opc);
        printf("-------------------------------------------\n");
        if(opc==1)
        {
            printf("A intersecçao dos vetores é: ");
            interF(vetA,vetB,n,m);
        }
        else if(opc==2)
        {
            printf("A Uniao dos vetores é: ");
            uniF(vetA,vetB,n,m);
        }
        else if(opc==3)
        {
            printf("A Concatenaçao dos vetores é: ");
            concF(vetA,vetB,n,m);
        }
        else if(opc==4)
        {
            printf("Digite 1 para subtrair A-B\nDigite 2 para subtrair B-A\nSua opçao: ");
            scanf("%d", &esc);
            while(esc!=1 && esc!=2)
            {
                printf("Digite uma opçao valida!\n");
                printf("Digite 1 para subtrair A-B\nDigite 2 para subtrair B-A\nSua opçao: ");
                scanf("%d", &esc);
            }
            if(esc==1)
            {
                printf("A Subtraçao dos vetores A-B é: ");
                subF(vetA,vetB,n,m);
            }
            else if(esc==2)
            {
                printf("A Subtraçao dos vetores B-A é: ");
                subF(vetB,vetA,m,n);   
            }
        }
        else if(opc==5)
        {
            printf("Digite o número que voce deseja achar no primeiro vetor: ");
            scanf("%d", &esc);
            while(!isnat(esc))
            {
                printf("Digite um número natural!\n");
                printf("Digite o número que voce deseja achar no primeiro vetor: ");
                scanf("%d", &esc);
            }
            int find=findF(vetA,n,esc);
            if(find==-1) printf("O número digitado nao esta no vetor!\n");
            else printf("O número %d está na posicao [%d] do vetor\n",esc,find);
        } 
        else if(opc==6)
        {
            printf("Digite o escalar que voce deseja para multiplicar o segundo vetor: ");
            scanf("%d", &esc);
            while(!isnat(esc))
            {
                printf("Digite um número natural!\n");
                printf("Digite o escalar que voce deseja para multiplicar o segundo vetor: ");
                scanf("%d", &esc);
            }
            printf("O vetor apos a multiplicaçao pelo escalar: ");
            escF(vetB,m,esc);
        }
        else if(opc==7)
        {
            if(n!=m) printf("ERRO!\nPara calcular o produto vetorial os vetores tem que possuir o mesmo tamanho!\n");
            else printf("O produto vetorial dos dois vetores é: %d\n", prodF(vetA,vetB,n));
        }
        else if(opc==8)
        {
            printf("O primeiro vetor apos a ordenaçao crescente: ");
            cresF(vetA,n);
            ord1=true;
        }
        else if(opc==9)
        {
            printf("O segundo vetor apos a ordenaçao crescente: ");
            cresF(vetB,m);
            ord2=true;
        }
        else if(opc==10)
        {
            if(ord1 && ord2)
            {
                int resultado[n+m];
                intercalarF(vetA, n, vetB, m, resultado);
                printf("\n Vetor intercalado: ");
                for (int i = 0; i < n+m; i++) 
                {
                    printf("%d ", resultado[i]);
                }
            }
            else
            {
                printf("Acione a opçao de ordenar os dois vetores, antes de intercalar eles!");
            }
        }
        else if(opc==11)
        {
            if(m!=n)
            {
                printf("\nERRO!\nNao é possivel armazenar o vetor B no vetor A, pois os vetores possuem tamanhos diferentes!");
            }
            else
            {   
                printf("\nO vetor A após a operaçao: ");
                armF(vetA,vetB,n);
                for(int i=0; i<n; i++)
                {
                    printf("%d ", vetA[i]);
                }
            }
        }
        else if(opc==-1);
        else printf("\nDigite uma opçao valida!\n");
    }    
    return 0;
}
