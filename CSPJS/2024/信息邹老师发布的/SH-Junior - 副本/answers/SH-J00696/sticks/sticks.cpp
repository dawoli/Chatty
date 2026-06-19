#include<bits/stdc++.h>
using namespace std;
int t,n;
int match[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int ans;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=20){
			cout<<match[n]<<endl;
			continue;
		}
		int x=0;
		x=n%7+14;
		cout<<match[x];
		for(int i=1;i<=(n-x)/7;i++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
