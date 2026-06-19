#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+1e6+10;
int n,t;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int c[51]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888};
int flag;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=50){
			cout<<c[n]<<"\n";
			continue;
		}
		if(n%7==0){
			for(register int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<"\n";
			continue;
		}
		if((n-1)%7==0){
			cout<<"10";
			for(register int i=1;i<n/7;i++){
				cout<<"8";
			}
			cout<<"\n";
			continue;
		}
		cout<<"-1\n";
	}
	return 0;
}
