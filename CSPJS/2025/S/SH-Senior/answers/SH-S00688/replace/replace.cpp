#include<iostream>
#include<ctime>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=200005,L=5000006;
ll const MOD=1000000087;
ll len[N],hash1[N],hash2[N],hashT1[L],hashT2[L],p[L];
ll inline substrHash1(int l,int r) {
	return (hashT1[r]-hashT1[l-1]*p[r-l+1]%MOD+MOD)%MOD;
}
ll inline substrHash2(int l,int r) {
	return (hashT2[r]-hashT2[l-1]*p[r-l+1]%MOD+MOD)%MOD;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++) {
		cin>>s1>>s2;
		len[i]=s1.size();
		for(int j=0;j<len[i];j++) hash1[i]=(hash1[i]*131+s1[j])%MOD;
		for(int j=0;j<len[i];j++) hash2[i]=(hash2[i]*131+s2[j])%MOD;
	}
	p[0]=1;
	for(int i=1;i<=5e6;i++) p[i]=p[i-1]*131%MOD;
	while(q--) {
		if(clock()>998) {
			cout<<0<<endl;
			continue;
		}
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			cout<<0<<endl;
			continue;
		}
		int m=t1.size(),leftmost=0,rightmost=0;
		for(int i=1;i<=m;i++) if(t1[i-1]!=t2[i-1]) leftmost=(leftmost?leftmost:i),rightmost=i;
		for(int i=1;i<=m;i++) hashT1[i]=(hashT1[i-1]*131+t1[i-1])%MOD;
		for(int i=1;i<=m;i++) hashT2[i]=(hashT2[i-1]*131+t2[i-1])%MOD;
		int ans=0;
		for(int l=1;l<=m;l++) {
			for(int i=1;i<=n;i++) {
				if(substrHash1(l,l+len[i]-1)!=hash1[i]) continue;
				if(substrHash2(l,l+len[i]-1)!=hash2[i]) continue;
				if(i>leftmost||i+len[i]-1<rightmost) continue;
				ans++;
			} 
		}
		for(int i=0;i<=m;i++) hashT1[i]=hashT2[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}

