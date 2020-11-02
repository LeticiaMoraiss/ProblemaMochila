#include <iostream>
#include <stdlib.h>
using namespace std;

void mochila(int n, int *peso, int *valor, int pMax){
    int *a = new int[pMax];    //vetor peso
    int *temp = new int[pMax]; //vetor valor
    int aux; //auxiliar

    for (int i = 0; i <= pMax; i++){      // Tratativa de erro
        a[i] = 0;                        //  não permite pesos com 0
        temp[i] = -1;                   //   não permite valores negativos
    }



    for (int i = 1; i <= pMax; i++){ // de 1 até o peso maximo da mochila
        for (int j = 0; j < n; j++){ // de 0 até a qtd de itens da mochila
            if ((peso[j] <= i) && (a[i] < a[i - peso[j]] + valor[j])){  //Verificação para custo beneficio
                a[i] = a[i - peso[j]] + valor[j]; //Soma o valor total da mochils
                temp[i] = j;
            }
        }
    }

    aux = pMax;
    while ((aux > 0) && (temp[aux] != -1)){
        cout << "Colocou o item " << temp[aux] + 1 << " (R$ "<<valor[temp[aux]] << ", " << peso[temp[aux]] << " Kg) Espaco disponivel: " << aux - peso[temp[aux]] << "\n";
        aux -= peso[temp[aux]];
    }
    cout << "valor total: R$" << a[pMax] << "\n";
    delete[] temp;
    delete[] a;
}

int main() {
    int n, pMax;
    cout<<"Informe a quantidade de itens da mochila: ";
    cin>>n;
    int *peso = new int[n];
    int *valor = new int[n];
    for(int i=0; i<n; i++){
        cout << "Informe o peso do objeto " << i + 1 << ": ";
        cin >> peso[i];
        cout << "Informe o valor do objeto " << i + 1 << ": ";
        cin >> valor[i];
        cout << "\n";
    }
    cout << "Informe o peso maximo da mochila: ";
    cin >> pMax;
    cout << "\nCalculando... \n\n";
    mochila(n, peso, valor, pMax);
    system("pause");
    return 0;
}
