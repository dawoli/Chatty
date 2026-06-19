#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MN=200005;
const int ML=5000005;
int n,q,a[MN];
int dp[2005][2005];
struct sss{
	string s1,s2;
} ss[MN];

string s1,s2;
int dpp(int s,int t) {
//	cout<<s<<" "<<t<<endl;
	if(dp[s][t]) return dp[s][t];
	if(s==t) {
		if(s1[s]!=s2[s]) return 0;
//		cout<<s<<" "<<t<<" - 1"<<endl;
		return 1;
	}
	int dpx=0;
	string tmps=s2.substr(s,t-s+1);
	string db=s1.substr(s,t-s+1);
	for(int i=1;i<=n;++i) {
		if(tmps==ss[i].s2&&db==ss[i].s1) dpx++;
	} 
	for(int i=s;i<t;++i) {
		if(s==t) break;
		dpx+=dpp(s,i)*dpp(i+1,t);
	}
//	cout<<s<<" "<<t<<" - "<<dpx<<endl; 
	return dp[s][t]=dpx;
}
 
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	
	scanf("%lld%lld",&n,&q);
	int sums;
	for(int i=1;i<=n;++i) {
		cin>>ss[i].s1>>ss[i].s2;
	} 
	for(int i=1;i<=q;++i) {
		cin>>s1>>s2;
		int l=s1.size();
		printf("%lld\n",dpp(0,l-1));
	}
	return 0;
} 
