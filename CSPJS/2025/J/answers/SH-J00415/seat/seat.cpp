#include <bits/stdc++.h>
using namespace std;
int a[1009];
bool cmp(int x1,int x2){
    return x1 > x2;
}
int findex(int kl,int n,int m){
    for(int i = 1;i <= n*m;i++){
        if(a[i] == kl){
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m*n;i++){
        cin >> a[i];
    }
    int k = a[1];
    sort(a+1,a+m*n+1,cmp);
    int ind = findex(k,n,m);
    int X = ind % n;
    int Y = ind / n;
    //cout << ind << ' ' << X << ' ' << Y << endl;
    if(ind % n != 0){
        if(Y % 2 == 0){
            cout << Y+1 <<' '<< X << endl;
        }
        if(Y % 2 == 1){
            cout << Y+1 <<' '<< n+1-X << endl;
        }
    }
    else{
        if(Y % 2 == 0){
            cout << Y <<' '<< X << endl;
        }
        if(Y % 2 == 1){
            cout << Y <<' '<< n-X << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
