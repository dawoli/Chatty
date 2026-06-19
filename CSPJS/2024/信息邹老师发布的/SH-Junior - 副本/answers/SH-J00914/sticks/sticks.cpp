#include<bits/stdc++.h>
using namespace std;
int f[25]={88,-1,1,7,4,2,6,8,10,18,22,20,27,68};
int n,t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>14){
			int x=n/7-1;
			cout<<f[n%7+7];
			for(int i=1;i<=x;i++){
				cout<<8;
			}
			cout<<"\n";
		}else{
			cout<<f[n]<<"\n";
		}
	}
	return 0;
}
