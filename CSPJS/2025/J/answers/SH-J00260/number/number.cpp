#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long int lngth=s.size(),count=0;
    char sNum[lngth];
    for(int i=0;i<lngth;i++){
        sNum[i]=s[i];
    }
    int a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0;
    for(long long int i=0;i<lngth;i++){
        if(sNum[i]>='a' && sNum[i]<='z'){
            count++;
        }
        else{
            if(sNum[i]=='0'){
                a0++;
            }
            if(sNum[i]=='1'){
                a1++;
            }
            if(sNum[i]=='2'){
                a2++;
            }
            if(sNum[i]=='3'){
                a3++;
            }
            if(sNum[i]=='4'){
                a4++;
            }
            if(sNum[i]=='5'){
                a5++;
            }
            if(sNum[i]=='6'){
                a6++;
            }
            if(sNum[i]=='7'){
                a7++;
            }
            if(sNum[i]=='8'){
                a8++;
            }
            if(sNum[i]=='9'){
                a9++;
            }
        }
    }
    for(int i=0;i<a9;i++){
        cout<<9;
    }
    for(int i=0;i<a8;i++){
        cout<<8;
    }
    for(int i=0;i<a7;i++){
        cout<<7;
    }
    for(int i=0;i<a6;i++){
        cout<<6;
    }
    for(int i=0;i<a5;i++){
        cout<<5;
    }
    for(int i=0;i<a4;i++){
        cout<<4;
    }
    for(int i=0;i<a3;i++){
        cout<<3;
    }
    for(int i=0;i<a2;i++){
        cout<<2;
    }
    for(int i=0;i<a1;i++){
        cout<<1;
    }
    for(int i=0;i<a0;i++){
        cout<<0;
    }
    return 0;
}

