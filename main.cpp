#include <iostream>
#include <math.h>

using namespace std;
int disparos(int x_1,int y_1,int x_2,int y_2,float tiempo,float velocidad, float angulo,int distancia);
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
    cout<<"*   1.Generar disparos (al menos tres) ofensivos que    *"<<endl;
    cout<< "*     comprometan la integridad del canon defensivo.    *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   2.Generar disparos (al menos tres) defensivos que   *"<<endl;
    cout<<"*     comprometan la integridad del canon ofensivo.     *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   3.Dado un disparo ofensivo, generar (al menos tres) * "<<endl;
          cout<<"*      disparos defensivos que impida que el canon      * "<<endl;
          cout<<"*      defensivo sea destruido sin importar si el canon * "<<endl;
          cout<<"*      ofensivo pueda ser destruido.                    *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*   4.Dado un disparo ofensivo, generar (al menos tres) *"<<endl;
          cout<<"*     disparo defensivos que impidan que los canones    *"<<endl;
          cout<<"*     defensivo y ofensivo puedan ser destruidos.       *"<<endl;
    cout<<"*                                                       *"<<endl;
    cout<<"*********************************************************"<<endl;
    cin>>opcion;
    float vx_bala,vy_bala;
    int cont=0,pos_x,pos_y;


    for (v=0;v<=100;v+=0.7){
        vx_bala=v*cos(angulo);
        vy_bala=v*sin(angulo);
        for (t=0;t<=100;t+=0.1){
            pos_x=pos_canon_ofensiva[0]+vx_bala*t;
            pos_y=pos_canon_ofensiva[1] +vy_bala*t - (4.901*(t*t));
            if (pos_y <0){
                break;
            }
            if(sqrt(pow(pos_canon_defenciva[0]-pos_x,2)+pow(pos_canon_defenciva[1]-pos_y,2))<=(0.05*distancia)){
                cout<<v<<","<<angulo<<","<<t<<endl;
                cont+=1;
            }
        if(cont==3){
            break;
        }

        }
    }
//    switch (opcion) {
//        case 1:

//        break;
//        case 2:

//        break;
//        case 3:

//        break;
//        case 4:

//        break;
//    }
    //cout<<distancia<<endl;

//    float vx_bala,vy_bala;

//    for (v=0;v>=100;v+=0.1){
//        vx_bala=v*cos(angulo);
//        vy_bala=v*sin(angulo);
//        for (t=0;t>=100;t+=0.1){

//        }
//    }

//    return 0;
}
int disparos(int x_1,int y_1,int x_2,int y_2,float tiempo,float velocidad, float angulo,float distancia){
    float vx_bala,vy_bala;
    int cont=0,pos_x,pos_y;


    for (velocidad=0;velocidad>=100;velocidad+=0.1){
        vx_bala=velocidad*cos(angulo);
        vy_bala=velocidad*sin(angulo);
        for (tiempo=0;tiempo>=100;tiempo+=0.1){
            pos_x=x_1 +vx_bala*tiempo;
            pos_y=y_1 +vy_bala*tiempo - (4.901*(tiempo*tiempo));
            if((((pos_x - x_2)^2)+((pos_y-y_2)^2)^(1/2))<=(0.05*distancia)){
                cout<<velocidad<<","<<angulo<<","<<tiempo<<endl;
                cont+=1;
            }
            if(cont==3){
                break;
            }

        }
    }
    return 0;
}
