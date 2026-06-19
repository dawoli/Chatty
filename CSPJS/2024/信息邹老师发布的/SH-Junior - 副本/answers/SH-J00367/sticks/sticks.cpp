#include<bits/stdc++.h>
using namespace std;
int ans[100009];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ans[0]=-1;
	ans[1]=-1;
	ans[2]=1;
	ans[3]=7;
	ans[4]=4;
	ans[5]=2;
	ans[6]=6;
	ans[7]=8;
	ans[8]=10;
	ans[9]=18;
	ans[10]=22;
	ans[11]=20;
	ans[12]=28;
	ans[13]=68;
	ans[14]=88;
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		if(n<=14) cout<<ans[n]<<endl;
		else {
			int k=n/7;
			int m=n%7;
			k-=2;
			if(m==0) cout<<88;
			if(m==1) cout<<108;
			if(m==2) cout<<188;
			if(m==3) cout<<200;
			if(m==4) cout<<208;
			if(m==5) cout<<288;
			if(m==6) cout<<688;
			for(int i=0;i<k;i++) cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
