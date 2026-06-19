#include <bits/stdc++.h>
using namespace std;
int nt[10]={6,2,5,5,4,5,6,3,7,6};
int tnf[100]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int tns[10]={-1,-1,1,7,4,2,0,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<'8';
			}
			cout<<'\n';
		}else{
			if(n<=14){
				cout<<tnf[n]<<'\n';
			}else if((n-1)%7==0){
				cout<<'1'<<'0';
				for(int i=1;i<=(n-1)/7-1;i++){
					cout<<'8';
				}
				cout<<'\n';
			}else{
				cout<<-1<<'\n';
			}
		}
	}
	return 0;
}
