#include <iostream>

using namespace std;
bool peligro();
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
    peligro();
    return 0;
}
bool peligro(){
    int bala_velocidad_angulo[2]={},vx_bala,vy_bala;

    cout<<"ingrese la velocidad de la bala ";
    cin>>bala_velocidad_angulo[0];cout<<"ingrese el angulo de la bala ";


}
