#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int Mod=998244353;
int a[N];
int b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	if(n==3){
		int mx=-1;
		for(int i=1;i<=3;i++){
			mx=max(mx,a[i]);
		}
		if(b[n]>mx*2) cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
