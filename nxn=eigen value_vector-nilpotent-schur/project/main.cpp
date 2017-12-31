#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include<iostream>
#include <fstream>
#include <time.h>
#define N 100
#include <iomanip>
using namespace std;
vector<float>v;
int sayac=0;
void nilpotentmatris(){
ofstream dosya;
dosya.open("nilpotent.txt");
dosya<<"Matris :\n";
cout<<"Matrisin boyutunu giriniz:";
    int n,i,j,k,l,sayac=0;
    cin>>n;
    int matris[n][n],matris_yedek[n][n],matris_son[n][n];
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            matris[i][j]=-15+(rand() % 31);
            matris_yedek[i][j]=matris[i][j];
            matris_son[i][j]=matris[i][j];
            dosya<<setw(5)<<matris[i][j];
        }
        dosya<<"\n";
    }
dosya<<"\n Ara matrisler \n";
for(l=0; l<=n; l++)
    {
        if(l>=1)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    matris[i][j]=matris_son[i][j];
                }
            }
        }
    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                int top=0;
                for(k=0; k<n; k++)
                {
                    top=top+matris[i][k]*matris_yedek[k][j];
                }
                matris_son[i][j]=top;
                dosya<<setw(10)<<matris_son[i][j];
            }
            dosya<<"\n";
        }
        dosya<<"\n";
        }
        dosya<<"\nSon matris : \n";
for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
        dosya<<setw(10)<<matris_son[i][j];

        }
        dosya<<"\n";
        }
for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
if(matris_son[i][j]==0)
    sayac++;
}
  }
        if(sayac==n*n)
            dosya<<"Nilpotenttir.";
        else
            dosya<<"Nilpotent degildir.";
    }

float dtrmnnt(int dizi[N][N],int n)
{
    int a,b,c;
    int gecici[N][N];
    int i,j;

  int det=0;
  if(n==1)
  {
      return dizi[0][0];
  }
  else if(n==2)
  {
      det=(dizi[0][0]*dizi[1][1]-dizi[0][1]*dizi[1][0]);
      return det;
  }
  else
  {
    for(a=0;a<n;a++)
    {
       b = 0;
       c = 0;
       for(i=1;i<n;i++)
       {
         for( j=0;j<n;j++)
         {
            if(j==a)
                {
                    continue;
                }
                gecici[b][c] = dizi[i][j];
            c++;
                if(c==n-1)
                {
                      b++;
                      c= 0;
            }
             }
       }
       det=det+dizi[0][a]*pow(-1,a)*dtrmnnt(gecici,n-1);
    }
    return det;
  }
}
int cark(){
    int sayi,i,rastgele,isayi;
    do{
    cout<<"Kac sayi uretmek istersiniz\n";
    cin>>sayi;
    }
    while(sayi<=0);

    for(i=1;i<=sayi;i++){
        rastgele=rand()%241;
        cout<<"Cark "<<i<< "tur dondu "<<i<<"sayi : "<<rastgele<<"\n";
        isayi=rastgele;
    }
return isayi%4;
}

void schutteo(){
    int n,i,j,k;
    int matrisyeni[N][N];
    float sonuc;
    cout<<"nxn lik matris icin n degerini giriniz.\n";
    cin>>n;
    int matris[N][N];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<i+1<<". satir "<<j+1<<".sutun elemanini giriniz\n";
                cin>>matris[i][j];
            }
        }
ofstream dosya;
    dosya.open("schur.txt");
    dosya <<"Matris :\n" ;
        for( i =0;i<n;i++){
            for(j=0;j<n;j++){
                dosya<<setw(5)<<matris[i][j];
            }
                dosya<<"\n";
    }
    dosya<<"\n";
float sinir1=0,sinir2=0;
dosya<<"Matris elemanlarinin kareleri alinir\n";
        for( i =0;i<n;i++){
            for(j=0;j<n;j++){
                sinir1=sinir1+matris[i][j]*matris[i][j];
            }
    }
dosya<<"Kareler toplami :"<<sinir1<<"\n";
     if(n==1){
       v[0]=matris[0][0];
       dosya<<"Ozdeger : "<<matris[0][0];
          }
    else if(n==2){
        int a,b,c,d;
        float kok1,kok2;
        a=1;
        b=(-1)*(matris[0][0]+matris[1][1]);
        c=(matris[0][0]*matris[1][1])-(matris[1][0]*matris[0][1]);
        d=b*b-(4*a*c);
        if(d==0){
            kok1=(-b+sqrt(d))/(2*a);
            v.push_back(kok1);
            dosya<<"Ozdeger : "<<kok1<<"\n";
       }
        else {
            kok1=(-b+sqrt(d))/(2*a);
            kok2=(-b-sqrt(d))/(2*a);
            v.push_back(kok1);
            v.push_back(kok2);
            dosya<<"Ozdeger : "<<kok1<<" ve "<<kok2<<"\n";
        }
   }
    else{
       for(k=-100;k<100;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j)
                matrisyeni[i][j]=matris[i][j]-k;
                else
                matrisyeni[i][j]=matris[i][j];
            }
            }
            sonuc=dtrmnnt(matrisyeni,n);
             if(sonuc==0){
                    v.push_back(k);
                    sayac++;
                        }

                }
            for(i=0;i<sayac;i++)
                    dosya<<"Ozdegerler : "<<v[i]<<"  ";
            }
    for( i =0;i<sayac;i++)
            sinir2=sinir2+v[i]*v[i];
dosya<<"\nOzdegerlerin kareleri toplami"<<sinir2;
dosya<<"\nSinirimiz : |"<<"lamda|<= (sqrt)"<<sinir2<<" ve \n"<<"|f(x)|<=  (sqrt)"<<sinir1;
}

void ozdegerbul(){
    int matris[N][N];
    int n,i,j,k;
    float sonuc;
    ofstream dosya;
    dosya.open("ozdeger.txt");
    int matrisyeni[N][N];
    cout<<"nxn lik matris icin n degerini giriniz.\n";
    cin>>n;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<i+1<<". satir "<<j+1<<".sutun elemanini giriniz\n";
                cin>>matris[i][j];
            }
        }
    if(n<0){
        cout<<"Pozitif bir sayi giriniz.";
    }
    else if(n==1){
        dosya <<"Matris :\n"<<matris[0][0]<<"\n" ;
        dosya <<"Ozdeger :"<<matris[0][0];
   }
    else if(n==2){
        dosya <<"Matris :\n" ;
        for( i =0;i<n;i++){
            for(j=0;j<n;j++){
                dosya<<setw(10)<<matris[i][j];
                if(i==j)
                    dosya<<"-L";
            }
                dosya<<"\n";
        }
        int a,b,c,d;
        float kok1,kok2;
        a=1;
        b=(-1)*(matris[0][0]+matris[1][1]);
        c=(matris[0][0]*matris[1][1])-(matris[1][0]*matris[0][1]);
        d=b*b-(4*a*c);
        dosya<<"a :"<<a<<" b :"<<b<<" c:"<<c<<"\n";
        if(d==0){
            kok1=(-b+sqrt(d))/(2*a);
            v.push_back(kok1);
            dosya<<"Ozdeger : "<<v[0];
}
        else if(d>0) {
            kok1=(-b+sqrt(d))/(2*a);
            kok2=(-b-sqrt(d))/(2*a);
            v.push_back(kok1);
            v.push_back(kok2);
        dosya<<"Ozdeger : "<<v[0]<<" ve "<<v[1];
        }
        else{
            cout<<"Reel cözüm yoktur.\n";
        }
   }
    else{
    ofstream dosya;
    dosya.open("ozdeger.txt");
    dosya <<"Matris :\n" ;
        for( i =0;i<n;i++){
            for(j=0;j<n;j++){
                dosya<<setw(5)<<matris[i][j];
                if(i==j)
                    dosya<<"-L";
            }
                dosya<<"\n";
    }
    dosya<<"\n";
    for(k=-100;k<100;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j)
                matrisyeni[i][j]=matris[i][j]-k;
                else
                matrisyeni[i][j]=matris[i][j];
            }
            }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
            dosya<<setw(5)<<matrisyeni[i][j]<<" ";
            }
                dosya<<"\n";
            }
            dosya<<"\n";
        sonuc=dtrmnnt(matrisyeni,n);
        dosya<<"\nk'nin degeri: "<<k<<" Determinant : "<<sonuc<<"\n\n";
            if(sonuc==0){
                v.push_back(k);
                sayac++;
                        }
                }
    if(sayac==0)
        dosya<<"Reel Çözüm yoktur.";
    for(i=0;i<sayac;i++){
        dosya<<"Ozdeger : "<<v[i]<<"  ";
                            }
dosya.close();
    }
        }
void ozvektorbul(){
}
int main()
{
    int secilenislem=cark();
        switch(secilenislem){
    case 0:
        cout<<"Ozdegeri bulan fonksiyon secildi\n";
        ozdegerbul();
        break;
    case 1:
        cout<<"Schur Teoremini bulan fonksiyon secildi\n";
        schutteo();
        break;
    case 2:
        cout<<"Ozvektörü bulan fonksiyon secildi\n";
        ozvektorbul();
        break;
    case 3:
        cout<<"Nilpotentligi kontrol eden fonksiyon secildi\n";
        nilpotentmatris();
        break;

    }



    return 0;
}
