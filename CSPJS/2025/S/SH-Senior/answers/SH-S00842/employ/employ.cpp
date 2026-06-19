#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m,s[505],c[505];
const int mod=998244353;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){char f;
	cin>>f;s[i]=f-'0';
	}long long fac=1;
	for(int i=1;i<=n;i++)fac=fac*i%mod;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		vector<int>V;int ans=0;
		for(int i=1;i<=n;i++)V.push_back(i);
		for(int i=1;i<=fac;i++){
			int num=0,fu=0,j=1;
			for(int i:V){
				if(fu>=c[i]||!s[j])fu++;
				else num++;
				j++;
			}if(num>=m)ans++;
			next_permutation(V.begin(),V.end());
		}printf("%d",ans);
	}
	else printf("%lld",fac);
}
