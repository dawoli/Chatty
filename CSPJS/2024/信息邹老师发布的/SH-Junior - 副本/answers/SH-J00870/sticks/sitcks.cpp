#include <bits/stdc++.h>

using namespace std;

void func(){
    int n;
    cin>>n;
    /*
    1.use a lot of 8(7 sticks)
    2.{
        more 1: -8+10
        more 2: -8+18
        more 3: -8+22
        more 4: -8+20
        more 5: -8+28
        more 6: -8+68
        more 7: -8+8
    */
    int ans = 0;
    int eights = n/7-1;

    if (eights!=-1){
        for(int i = 0; i<eights; i++){
            ans = ans*10+8;
        }

        switch (n-(eights+1)*7){
        case 1:
            ans = 10*pow(10.0,eights) + ans;
            break;
        case 2:
            ans = 18*pow(10.0,eights) + ans;
            break;
        case 3:
            ans = 22*pow(10.0,eights) + ans;
            break;
        case 4:
            ans = 20*pow(10.0,eights) + ans;
            break;
        case 5:
            ans = 28*pow(10.0,eights) + ans;
            break;
        case 6:
            ans = 68*pow(10.0,eights) + ans;
            break;
        case 7:
            ans = 8*pow(10.0,eights)+ans;
            break;
        }
    }
    if (eights==-1){
        switch (n){
        case 1:
            ans = 0;
            break;
        case 2:
            ans = 1;
            break;
        case 3:
            ans = 7;
            break;
        case 4:
            ans = 4;
            break;
        case 5:
            ans = 2;
            break;
        case 6:
            ans = 6;
            break;
        }
    }

    if (ans==0)
        ans = -1;
    cout<<ans<<endl;
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        func();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
