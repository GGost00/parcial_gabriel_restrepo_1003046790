#include <iostream>
#include <math.h>

using namespace std;
int disparos(int x_1,int y_1,int x_2,int y_2, float angulo,int distancia,float radio);
int tiros(int x_1,int y_1,int x_2,int y_2, float angulo,int distancia);
int main()
{
    int pos_canon_ofensiva[2]={};
    int pos_canon_defenciva[2]={};
    float t=0,v=0,a=0,angulo;
    int opcion;

    cout<<"ingrese la pos x del canon ofencivo ";
    cin>>pos_canon_ofensiva[0];cout<<"ingrese la pos y del canon ofencivo ";
    cin>>pos_canon_ofensiva[1];cout<<"ingrese la pos x del canon defencivo ";
    cin>>pos_canon_defenciva[0];cout<<"ingrese la pos y del canon defencivo ";
    cin>>pos_canon_defenciva[1];cout<<"ingrese el angulo que desesa verificar ";
    cin>>a;
    int distancia;
    angulo=a*M_PI/180;
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
    float vx_bala,vy_bala,angulop;
    int cont=0,pos_x,pos_y;
    angulop=(180-a)*M_PI/180;

    for (v=0;v<=100;v+=0.7){

        vx_bala=v*cos(angulop);
        vy_bala=v*sin(angulop);
        for (t=0;t<=100;t+=0.1){
            pos_x=pos_canon_defenciva[0]+vx_bala*t;
            pos_y=pos_canon_defenciva[1] +vy_bala*t - (4.901*(t*t));
            if (pos_y <0){
                break;
            }
            if(sqrt(pow(pos_canon_ofensiva[0]-pos_x,2)+pow(pos_canon_ofensiva[1]-pos_y,2))<=(0.025*distancia)){
                //cout<<v<<","<<angulo<<","<<t<<endl;
                cont+=1;
            }
        if(cont==3){
            break;
        }

        }
    }
    cout<<""<<endl;
   switch (opcion) {
        case 1:
            cout<<disparos(pos_canon_ofensiva[0],pos_canon_ofensiva[1],pos_canon_defenciva[0],pos_canon_defenciva[1],angulo,distancia,0.05);
            break;
        case 2:
            cout<<disparos(pos_canon_defenciva[0],pos_canon_defenciva[1],pos_canon_ofensiva[0],pos_canon_ofensiva[1],angulop,distancia,0.025);
            break;
        case 3:
            cout<<tiros(pos_canon_defenciva[0],pos_canon_defenciva[1],pos_canon_ofensiva[0],pos_canon_ofensiva[1], angulop,distancia);
            break;
//        case 4:

//        break;
    }

   return 0;
}
int disparos(int x_1,int y_1,int x_2,int y_2, float angulo,int distancia,float radio){
    float vx_bala,vy_bala,t=2,v=0;
    int cont=0,pos_x,pos_y;


    for (v=0;v<=100;v+=0.5){
        vx_bala=v*cos(angulo);
        vy_bala=v*sin(angulo);
        for (t=0;t<=100;t+=0.3){
            pos_x=x_1+vx_bala*t;
            pos_y=y_1 +vy_bala*t - (4.901*(t*t));
            if (pos_y <0){
                break;
            }
            if(sqrt(pow(x_2-pos_x,2)+pow(y_2-pos_y,2))<=(radio*distancia)){
                cout<<"velocidad= "<<v<<", Angulo= "<<angulo*180/M_PI<<",tiempo= "<<t<<endl;
                cont+=1;
            }
        if(cont==3){
            break;
        }

        }
    }
    return 0;
}
int tiros(int x_1,int y_1,int x_2,int y_2, float angulo,int distancia){
    float vx_bala,vy_bala,t=0,v=0,vx_balad,vy_balad,v_t;
    int cont=0,pos_x,pos_y;

    vx_bala=v*cos(angulo);
    vy_bala=v*sin(angulo);

    pos_x=x_1 +vx_bala*2.5;
    pos_y=y_1 +vy_bala*2.5 - (4.901*(4.25));

    vx_balad=abs((pos_x-x_2)/0.5);

    v_t=vx_balad*cos(angulo);
    if(sqrt(pow(x_2-pos_x,2)+pow(y_2-pos_y,2))<=(0.05*distancia)){
        cout<<"se afecto el canon defencivo";
    }
    if(sqrt(pow(x_1-pos_x,2)+pow(y_1-pos_y,2))<=(0.05*distancia)){
        cout<<"se afecto el canon ofensivo ";
        cont+=1;
    }
    else{
        cout<<"con un angulo de "<<angulo<<" se puede detener la bala en un tiempo igual a 0.5 s cuando ella pasa por "
                                       <<pos_x<<","<<pos_y<<"sin afectar a ningun cañon con una velocidad de "<<abs(v_t)<<endl;
    }




    return 0;
}
