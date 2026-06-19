#include<bits/stdc++.h>
using namespace std;
int n,m;string s;int k;long long an[510];int ans;long long h=998244353;
int a[510];int b;bool c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	k=n;
	cin>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			k--;
			b++;
			c[i]=1;
		}
		
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=b&&c[i]==0){
			k--;
		}
	}

	an[2]=2;
	for(int i=3;i<=k;i++){
		an[i]=an[i-1]*i;
		ans=an[i]%h;
		an[i]=an[i]%h;
	}
	
	cout<<ans;
	
	return 0;
} 
