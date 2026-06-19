#include<bits/stdc++.h>
using namespace std;
int T,n,sum=0; string s,ss;
int a[12]={8,0,2,4,7,1};
char c[12]={'8','0','2','4','7','1'};
int b[12]={7,6,5,4,3,2};
int f=0;
void dfs(int x,string s){
    ss=s;
    if(f) return;
    if(x==1) return;
    if(x==0){
        cout<<ss<<endl;
        f=1;
        return;
    }
    for(int i=0;i<6;i++){
        if(x>=b[i]){
            ss+=c[i];
            dfs(x-b[i],ss);
            if(f) return;
            ss=s;
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        f=0;
        if(n==8){
            cout<<10<<endl;
            continue;
        }
        if(n%7==1){
            cout<<10;
            int x=n-8;
            while(x){
                cout<<8;
                x-=7;
            }
            continue;
        }
        if(n==6){
            cout<<6<<endl;
            continue;
        }
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        dfs(n,s);
    }
    return 0;
}
