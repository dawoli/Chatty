#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=998244353;
int n,m,c[N],p[N],ans;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i-1]=i;
	}
	int tot=0;
	for(int i=0;i<n;i++){
		tot+=s[i]-'0';
	}
	if(tot<m){
		cout<<0;
		return 0;
	}
	do{
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')continue;
			if(i-cnt<c[p[i]])cnt++;
		}
		ans+=(cnt>=m);
		ans%=mod;
	}while(next_permutation(p,p+n));
	cout<<ans;
	return 0;
}
