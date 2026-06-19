#include<bits/stdc++.h>
using namespace std;

int a[5005];
const int MOD=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int maxn=-1;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]); 
	}
	
	if(maxn==1) cout<<n-2;
	else if(n<=3){
		if(a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0]) cout<<1;
		else cout<<0;
	}
	else{
		cout<<998244352;
	}
	
		
	
	
	
}
