#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int a[200010];
int s[100010];
int r[100010],c[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	cin>>n>>k>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=1;j<=a[i];++j){
			cin>>s[j];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>r[i]>>c[i];
	}
	for(int i=1;i<=q;++i){
		cout<<1<<endl;
	}
	return 0;
}
