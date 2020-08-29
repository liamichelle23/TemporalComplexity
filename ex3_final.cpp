#include <iostream>
using namespace std;

template<size_t m, size_t n> 
//O(m+n)
int MasAlto1(int (&horizonte)[m][n]){  // El template se usa para que los valores de m y n puedan cambiar.
    for (int i=0; i<m; i++){ //Se corre m veces.
        for (int j=0;j<n; j++){ //Se corre n veces. Representa las filas
            if (horizonte[i][j]==0){ return j;}
        }
    }
    return -1; //Significa que no encontró el edificio más alto
}

//O(log n)
int BusquedaBinaria(int a[],int inicio, int final){

    if(final<=inicio){return -1;} //Significa que no lo encontró
    int puntoMedio=(inicio+final)/2;
    
    if (inicio != final+1){
        int izquierda=BusquedaBinaria(a,inicio,puntoMedio-1); 
        int derecha=BusquedaBinaria(a,puntoMedio+1,final);
        if (a[puntoMedio]==0){ return puntoMedio;} //Significa que el edificio más alto se encuentra en el punto medio
        if (izquierda != -1){ return izquierda;} //El edificio más alto se encuentra del lado izquierdo
        if (derecha != -1){return derecha;} //El edificio más alto se encuentra del lado derecho
    }
    else{
        return -1;

    }
}


//O(m log n)
template<size_t m, size_t n> 
int MasAlto2(int (&horizonte)[m][n]){
    for (int i=0;i<m;i++){ //Se corre el método de BusquedaBinaria una vez por cada fila
        int bBinaria=BusquedaBinaria(horizonte[i],0,n);
        if (bBinaria==-1){ return -1;}
        else {return bBinaria;}
    }
}

int main(){

    int horizonte[6][5]={{1,1,1,1,0},
                       {0,1,1,0,1},
                       {0,0,0,0,1},
                       {0,0,0,0,1},
                       {0,0,0,0,0},
                       {0,0,0,0,0}};
    int masAlto1=MasAlto1(horizonte);
    int masAlto2=MasAlto2(horizonte);
    cout << "¿Cuál es el edificio más alto?" << endl;
    cout << "Con la forma O(m+n): " << masAlto1 << endl;
    cout << "Con la forma O(m log n): " << masAlto2 << endl; 

    return 0;
}
