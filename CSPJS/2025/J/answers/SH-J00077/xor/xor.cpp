#include <bits/stdc++.h>
using namespace std;

int a[50005]={};

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,cnt=0,k;
	cin>>n>>k;
	if(n==1&&!k){
		int x;
		cin>>x;
		if(!x){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
		}
	}
	else if(n==2&&!k){
		int x,y;
		cin>>x>>y;
		if(!x&&!y){
			cout<<3;
		}
		else if(!x&&y||!y&&x){
			cout<<2;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==k){
			++cnt;
		}
	}
	return 0;
}

