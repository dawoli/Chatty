#include <bits/stdc++.h>
using namespace std;
int a[23]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=22){
			cout<<a[n]<<endl;
			continue;
		}
		cout<<a[(n-16)%7+16];
		for(int i=0;i<(n-16)/7;i++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
