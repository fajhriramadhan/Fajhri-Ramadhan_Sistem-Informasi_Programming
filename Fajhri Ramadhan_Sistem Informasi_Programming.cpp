// NAMA        : Fajhri Ramadhan A.
// NRP        : 5026221030
// Jurusan    : Sistem Informasi

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

using namespace std;
float mencari_V0(int jarak)
{
    /* Tulis fungsi mencari v0 kalian disini */
    float res = jarak;
    return sqrt(res*GRAVITASI);
}

float speed_dgn_loss(float v0)
{
    if (v0>=1 && v0<=10)
    {
        v0++;
    }else if(v0>=11 && v0<=20){
        v0+=3;
    }else{
        v0+=5;
    }    
    return v0;
}

int main() {
    int v;
    cin >> v;
    bool p=0;
    int xmaks=1,iterasi=1;
    float vt=0;
    while(!p){
        float vsem = mencari_V0(iterasi);
        vsem = speed_dgn_loss(vsem);
        if(vsem >v ){
            break;
        }
        if(xmaks<iterasi && vsem<=30){
            vt = vsem;
            xmaks = iterasi;
        }
        iterasi++;
    }
    cout<<xmaks<<" "<<vt<<endl;
    
}