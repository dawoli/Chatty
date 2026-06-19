#include<bits/stdc++.h>
using namespace std;
const int x[10]={6,2,5,5,4,5,6,3,7,6};
int a[100]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<=21){
			cout<<a[n]<<endl;
			continue;
		}
		int z=(n-15)/7;
		cout<<a[n-7*z];
		for(int i=1;i<=z;i++)
			cout<<8;
		cout<<endl;
	}
	return 0;
}
