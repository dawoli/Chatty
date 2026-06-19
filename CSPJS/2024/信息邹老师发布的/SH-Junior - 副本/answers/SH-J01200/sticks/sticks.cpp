#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n[60],en[30]={-1, -1,1,7,4,2,6,8,10,18,22, 20,28,68,88,108,188,228,208,288,688};
	cin>>T;
	for(int i=1;i<=T;i++){
        cin>>n[i];
	}
	for(int i=1;i<=T;i++){
        if(n[i]<=1)cout<<-1<<endl;
        else if(n[i]%7==0){
            for(int j=1;j<=n[i];j+=7){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n[i]==8)cout<<10<<endl;
        else if(n[i]%7==1){
            cout<<1<<0;
            for(int j=15;j<=n[i];j+=7){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n[i]<=20)cout<<en[n[i]]<<endl;
	}
	return 0; 
}
