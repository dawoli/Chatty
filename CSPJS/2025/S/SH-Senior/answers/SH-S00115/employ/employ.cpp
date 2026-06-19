#include<bits/stdc++.h>
using namespace std;
int n,m,c[12],mx,v[12],ss[12],z; 
char s[12];
long long dfs(int st){
	if(st>=n){
		int r=0,rr=0;
		for(int i=1;i<=n;i++){
			if(r<v[ss[i]]) rr++;
			if(c[i]=='0')
				r++;
		}
		if(rr>=m) return 1;
		else return 0;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			ss[++z]=i;
			sum+=dfs(st+1);
			sum%=998244353;
			z--;
			v[i]=0;
		}
	}
	return sum%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> s[i];
	for(int i=1;i<=m;i++)
		cin >> c[i];
	cout << dfs(0);
	return 0;
}
//不会。不会，不会。 
