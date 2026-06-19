#include <bits/stdc++.h>
using namespace std;
int x[6000];
int c[6000];
int N=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool is1=true;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i];
		c[i]=c[i-1]+x[i];
		if (x[i]!=1) is1=false;
	}
	if (is1==true){
		int cnt=0;
		for (int i=3;i<=n;i++){
			cnt=(cnt+(n+1-i)%N)%N;
		}
		cout<<cnt;
	}
	else if (n==3){
		int ma,num;
		num=c[n];
		ma=max(max(x[1],x[2]),x[3]);
		if (num>ma*2) cout<<1;
		else cout<<0;
	}
}
