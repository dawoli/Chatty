#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    string ans[55];
    cin>>T;
    for (int i=1;i<=T;i++){
        cin>>n;
        if (n<15){
            if (n==1) ans[i]="-1";
            else if (n==1) ans[i]="-1";
            else if (n==2) ans[i]="1";
            else if (n==3) ans[i]="7";
            else if (n==4) ans[i]="4";
            else if (n==5) ans[i]="2";
            else if (n==6) ans[i]="6";
            else if (n==7) ans[i]="8";
            else if (n==8) ans[i]="10";
            else if (n==9) ans[i]="18";
            else if (n==10) ans[i]="22";
            else if (n==11) ans[i]="20";
            else if (n==12) ans[i]="28";
            else if (n==13) ans[i]="68";
            else if (n==14) ans[i]="88";
        }
        else{
            if (n%7==1) ans[i]="108";
            else if (n%7==2) ans[i]="188";
            else if (n%7==3) ans[i]="200";
            else if (n%7==4) ans[i]="208";
            else if (n%7==5) ans[i]="288";
            else if (n%7==6) ans[i]="688";
            else if (n%7==0) ans[i]="888";
            for (int j=1;j<=(n-1)/7-2;j++){
                ans[i]+='8';
            }
        }
    }
    for (int i=1;i<=T;i++) cout<<ans[i]<<endl;
    return 0;
}
