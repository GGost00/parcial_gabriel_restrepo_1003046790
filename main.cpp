#include <iostream>
#include <math.h>

using namespace std;
int disparos(int x_1,int y_1,int x_2,int y_2,float tiempo,float velocidad, float angulo);
int main()
{
    int pos_canon_ofensiva[2]={};
    int pos_canon_defenciva[2]={};
    float t=0,v=0,angulo=45*M_PI/180;;
    int opcion;

    cout<<"ingrese la pos x del canon ofencivo ";
    cin>>pos_canon_ofensiva[0];cout<<"ingrese la pos y del canon ofencivo ";
    cin>>pos_canon_ofensiva[1];cout<<"ingrese la pos x del canon defencivo ";
    cin>>pos_canon_defenciva[0];cout<<"ingrese la pos y del canon defencivo ";
    cin>>pos_canon_defenciva[1];
    int distancia;
    distancia=pos_canon_defenciva[0]-pos_canon_ofensiva[0];
    cout<<"****************que caso quiere saber*******************"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   1.Generar disparos (al menos tres) ofensivos que    *"
          "*     comprometan la integridad del cañón defensivo.    *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   2.Generar disparos (al menos tres) defensivos que   *"
          "*     comprometan la integridad del cañón ofensivo.     *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   3.Dado un disparo ofensivo, generar (al menos tres) * "
          "*      disparos defensivos que impida que el cañón      * "
          "*      defensivo sea destruido sin importar si el cañón * "
          "*      ofensivo pueda ser destruido.                    *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   4.Dado un disparo ofensivo, generar (al menos tres) *"
          "*     disparo defensivos que impidan que los cañones    *"
          "*     defensivo y ofensivo puedan ser destruidos.       *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*********************************************************"<<endl;
    cin>>opcion;
    switch (opcion) {
        case 1:
        cout<<disparos(pos_canon_ofensiva[0],pos_canon_ofensiva[1],pos_canon_defenciva[0],pos_canon_defenciva[1],t,v,angulo);
        break;
        case 2:

        break;
        case 3:

        break;
        case 4:

        break;
    }
    //cout<<distancia<<endl;

    float vx_bala,vy_bala;

    for (v=0;v>=100;v+=0.1){
        vx_bala=v*cos(angulo);
        vy_bala=v*sin(angulo);
        for (t=0;t>=100;t+=0.1){

        }
    }

    return 0;
}
int disparos(int x_1,int y_1,int x_2,int y_2,float tiempo,float velocidad, float angulo){
    float vx_bala,vy_bala;


    for (velocidad=0;velocidad>=100;velocidad+=0.1){
        vx_bala=velocidad*cos(angulo);
        vy_bala=velocidad*sin(angulo);
        for (tiempo=0;tiempo>=100;tiempo+=0.1){

        }
    }
}
