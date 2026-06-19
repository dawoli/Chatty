#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,c[505],ans,p[505];
string s;
long long x=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		scanf("%d",&c[i]);
		p[i]=i;
	}
	do{
		long long now=0,ge=0;
		for(long long i=1;i<=n;i++){
			if(c[p[i]]<=now){
				now++;
				continue;
			}
			if(s[i-1]=='0'){
				now++;
				continue;
			}
			ge++;
		}
		if(ge>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans%MOD<<endl;
	return 0;
}
