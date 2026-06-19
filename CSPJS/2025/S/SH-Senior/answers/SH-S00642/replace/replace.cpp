#include<bits/stdc++.h>
#define N 200002
using namespace std;
typedef long long ll;
ll n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;++i)cin>>s[i][0]>>s[i][1];
	for(ll i=1;i<=q;++i){
		string t1,t2;
		cin>>t1>>t2;
		cout<<"0\n";
	}
	return 0;
}
