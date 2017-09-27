#include <iostream>

using namespace std;

void tamano(int *fa,int *ca,int *fb,int *cb){
    cout << "Ingrese en numero de filas de A" << endl;  //pedimos los valores
    cin >> *fa;
    cout << "Ingrese en numero de columnas de A" << endl;
    cin >> *ca;
    cout << "Ingrese en numero de filas de B" << endl;
    cin >> *fb;
    cout << "Ingrese en numero de columnas de B" << endl;
    cin >> *cb;
    if(*ca!=*fb){                                        //Para que la multiplicacion pueda realizarse el numero de columnas de A
        cout << "Estos tamaños no pueden ser multiplicados" << endl; //debe ser igual al numero de filas de B
    }
    return;
}

void iniMatri(int **m,int fil,int colum){
    for(int i=0;i<fil;i++){
        m[i]= new int[colum];

    }
}
void datos(**mA,int fil,int colum){
    for(int i=0;i<fil;i++){     //pedimos los datos
        for(int j=0;j<colum;j++){
            int var;
            cout << "Ingrese un numero para la matriz" << endl;
            cin >> var;
            mA[i][j]=var;
        }
    }
}
void elimMatri(int **m,int fil,int colum){
    for(int i=0;i<fil;i++){     //eliminamos el espacio separado para las listas dentro de la matriz
        delete[] m[i];
    }
}


int multM(int **ma, int **mb, int **mc,int a=0,int b=0,int c=0){
  if(a==3){        //multiplicacion recursiva
    return 0;
  }
  mc[a][b]+=(ma[a][c]*mb[c][b]);
  if(b==2){
    return multM(ma,mb,mc,++a);
  }
  if(c==2){
    return multM(ma,mb,mc,a,++b);
  }
  return multM(ma,mb,mc,a,b,++c);
}

int main(){
    int *fA = new int; //Creamos punteros para almacenar las filas y las columnas de las matrices
    int *cA = new int;
    int *fB = new int;
    int *cB = new int;
    tamano(fA,cA,fB,cB);
    int**mA = new int*[*fA]; //creamos una lista de punteros
    int**mB = new int*[*fB];
    int**mC = new int*[*fA];
    iniMatri(mA,*fA,*cA);
    iniMatri(mB,*fB,*cB); //inicializamos los punteros
    iniMatri(mC,*fA,*cB);
    multM(mA,mB,mC);
    elimMatri(mA,*fA,*cA);
    elimMatri(mB,*fB,*cB); //eliminamos el espacio de los punteros
    elimMatri(mA,*fA,*cA);
    delete[] mA;
    delete[] mB;
    delete[] mC;
    delete fA;
    delete cA;
    delete fB;
    delete cB;
    return 0;
}
