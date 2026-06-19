#include <bits/stdc++.h>
using namespace std;

int s[10]={6,2,5,5,4,5,6,3,7,6};
int x[14]={-1,-1,1,7,4,2,6,8,10,18,40,20,28,68};
ifstream fin("sticks.in");
ofstream fout("sticks.out");

int main(){
    int T, n, i;
    fin >> T;
    while (T--){
        fin >> n;
        if(n<14) fout <<x[n]<<endl;
        if (n>=14 and n%7==0){
            for(i=0;i<n/7;i++){
                fout << 8;
            }
            fout << endl;
        }
        if (n>=14 and n%7==1){
            fout << 10;
            for(i=0;i<(n-8)/7;i++){
                fout << 8;
            }
            fout << endl;
        }
        if (n>=14 and n%7==2){
            fout << 1;
            for(i=0;i<(n-2)/7;i++){
                fout << 8;
            }
            fout << endl;
        }
        if (n>=14 and n%7==3){
            fout << 40;
            for(i=0;i<(n-10)/7;i++){
                fout << 8;
            }
            fout << endl;
        }
        if (n>=14 and n%7==4){
            fout << 20;
            for(i=0;i<(n-11)/7;i++){
                fout << 8;
            }
            fout << endl;
        }
        if (n>=14 and n%7==5){
            fout << 2;
            for(i=0;i<(n-2)/7;i++){
                fout << 8;
            }
            fout << endl;
        }
        if (n>=14 and n%7==6){
            fout << 6;
            for(i=0;i<(n-6)/7;i++){
                fout << 8;
            }
            fout << endl;
        }
    }
    return 0;
}
