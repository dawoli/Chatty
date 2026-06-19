#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int b[100010];
int c[100010];
int t;
string s;
int p(int x){
	for(int i=1;i<=20;++i)
		if(pow(2,i)>=x)
			return i;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>b[i];
	for(int i=1;i<=m;++i)
		cin>>c[i];
	for(int i=1;i<=p(n);++i)
		cin>>s;
	cin>>t;
	for(int i=1;i<=t;++i){
		int as;
		int x[10];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int j=1;j<=n;++j){
			int ans=0;
			for(int k=1;k<=pow(2,p(j));++k){
				if(k<=j)
					a[k]=b[k]^x[k%4];
				else
					a[k]=p(j)+1;
				if(a[k]>=p(j))
					ans+=k;
			}
			if(j==1)
				as=ans;
			else
				as^=ans*j;
		}
		cout<<as<<endl;
	}
	return 0;
}
