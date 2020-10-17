#include <iostream>
#include <math.h>

using namespace std;
bool peligro(int x,int y,float*);
int main()
{
    int pos_canon_ofensiva[2]={};
    int pos_canon_defenciva[2]={};
    float t=2.5,vx_bala,vy_bala,angulo;
    float *p=&vx_bala;


    cout<<"ingrese la pos x del canon ofencivo ";
    cin>>pos_canon_ofensiva[0];cout<<"ingrese la pos y del canon ofencivo ";
    cin>>pos_canon_ofensiva[1];cout<<"ingrese la pos x del canon defencivo ";
    cin>>pos_canon_defenciva[0];cout<<"ingrese la pos y del canon defencivo ";
    cin>>pos_canon_defenciva[1];
    int distancia;
    distancia=pos_canon_defenciva[0]-pos_canon_ofensiva[0];
    cout<<distancia<<endl;
    if(peligro(pos_canon_ofensiva[0],pos_canon_ofensiva[1],p)==true){

    }

    return 0;
}
bool peligro(int x,int y,float *p){
    int bala_velocidad_angulo[2]={};
    float t=0,vx_bala,vy_bala;

    cout<<"ingrese la velocidad de la bala ";
    cin>>bala_velocidad_angulo[0];cout<<"ingrese el angulo de la bala ";
    cin>>bala_velocidad_angulo[1];
    vx_bala=bala_velocidad_angulo[0]* cos(bala_velocidad_angulo[1]);
    vy_bala=bala_velocidad_angulo[0]* sin(bala_velocidad_angulo[1]);
    int pos_x_bala, pos_y_bala;
    *p=vx_bala;
    p+=1;
    *p=vy_bala;

    while(true){
        pos_x_bala=x+(vx_bala*t);
        pos_y_bala=y+(vy_bala*t)-(1/2*(9.81)*(t*t));
        t+=0.2 ;
        if(0<(((pos_x_bala-x)^2+(pos_y_bala-y)^2)^(1/2))&&(((pos_x_bala-x)^2+(pos_y_bala-y)^2)^(1/2))<=5){
            cout<<"el canon esta en peligro!";
            return true;
        }
        if(t==100.0){
            cout<<"no hay peligro";
            return false;
        }

      }

}
