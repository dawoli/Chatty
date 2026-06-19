#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int biao[20]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288};
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<20){
			cout<<biao[n]<<"\n";
			continue;
		}
		int lns=n%8;
		while(lns<12) lns+=8;
		cout<<biao[lns];
		for(int i=1;i<=(n-lns)/8;i++) cout<<8;
		cout<<endl;
	}
	return 0;
} 
