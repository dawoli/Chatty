#include<bits/stdc++.h>
using namespace std;
const long long N=509,M=998244353;
long long n,m,p[N],k[N];
bool pap[N];
long long ans=0;;
string s;
void solve(long long p){
	long long num=1;
	for(long long i=1;i<=p;i++)
		num=num*i%M;
	ans=ans+num%m;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++) pap[i]=s[i-1]-'0';
	for(long long i=1;i<=n;i++){
		cin>>p[i];
		k[p[i]]++;
	}
	for(long long i=0;i<=n;i++)
		if(k[i]>1)
			solve(k[i]);
	cout<<ans<<endl;
}


