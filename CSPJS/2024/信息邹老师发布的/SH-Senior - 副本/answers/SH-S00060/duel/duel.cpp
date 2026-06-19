#include<bits/stdc++.h>
using namespace std;
long long n;
map<long long,long long> m;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		m[a]++;
	}
	long long ans=0;
	for(int i=1;i<=m.size();i++){
		ans=max(ans,m[i]);
	}
//	cout<<' '<<m[1]<<' '<<m[2]<<endl;
	cout<<ans;
	return 0;
}
