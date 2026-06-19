#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x[500005],ans;
map<int,bool> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	m[0]=1;
	for(int i=1;i<=n;i++){
		if(m[x[i]^k]){
			ans++;
			m.clear();
		}
		m[x[i]]=1;
	}
	cout<<ans;
}
