#include <iostream>
#include <math.h>

using namespace std;
bool peligro(int x,int y,int z,int w);
int main()
{
    int pos_canon_ofensiva[2]={};
    int pos_canon_defenciva[2]={};



    cout<<"ingrese la pos x del canon ofencivo ";
    cin>>pos_canon_ofensiva[0];cout<<"ingrese la pos y del canon ofencivo ";
    cin>>pos_canon_ofensiva[1];cout<<"ingrese la pos x del canon defencivo ";
    cin>>pos_canon_defenciva[0];cout<<"ingrese la pos y del canon defencivo ";
    cin>>pos_canon_defenciva[1];
    int distancia;
    distancia=pos_canon_defenciva[0]-pos_canon_ofensiva[0];
    cout<<distancia<<endl;

    if(peligro(pos_canon_ofensiva[0],pos_canon_ofensiva[1],pos_canon_defenciva[0],pos_canon_defenciva[1])==true){

    }

    return 0;
}
bool peligro(int x,int y,int z,int w){
    int bala_velocidad_angulo[2]={};
    float t=0,vx_bala,vy_bala;

    cout<<"ingrese la velocidad de la bala ";
    cin>>bala_velocidad_angulo[0];cout<<"ingrese el angulo de la bala ";
    cin>>bala_velocidad_angulo[1];
    vx_bala=bala_velocidad_angulo[0]* cos(bala_velocidad_angulo[1]);
    vy_bala=bala_velocidad_angulo[0]* sin(bala_velocidad_angulo[1]);
    int pos_x_bala, pos_y_bala;

    while(true){
        pos_x_bala=x+(vx_bala*t);
        pos_y_bala=y+(vy_bala*t)-((4.99)*(t*t));
        if(pos_y_bala<0){
            cout<<"no hay peligro";
            return false;
                }
        cout<<pos_x_bala<<","<<pos_y_bala<<endl;
        if(0<(((pos_x_bala-z)^2+(pos_y_bala-w)^2)^(1/2))&&(((pos_x_bala-z)^2+(pos_y_bala-w)^2)^(1/2))<=5){
            cout<<"el canon esta en peligro!";
            return true;
        }
        t+=0.5 ;

    }
}
