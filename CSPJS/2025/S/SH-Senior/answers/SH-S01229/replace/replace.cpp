#include <bits/stdc++.h>
using namespace std;
const int N=5e6+10,K=2e5+10;
int n,q;string s1[K],s2[K];int nx[N];
int kmp(string a,string b) {
	for (int i=2,j=0; a[i]; i++) {
		while (j && a[i]!=a[j+1]) j=nx[j];
		if (a[i]==a[j+1]) j++;
		nx[i]=j;
	}
	int ans=-1;
	for (int i=1,j=0; b[i]; i++) {
		while (j && b[i]!=a[j+1]) j=nx[j];
		if (b[i]==a[j+1]) j++;
		if (j==a.size()-1 && ans!=-1) return -1;
		if (j==a.size()-1) ans=i,j=nx[j];
	}
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}
	for (int i=1; i<=q; i++) {
		string q1,q2;cin>>q1>>q2;
		int ans=0;q1=' '+q1,q2=' '+q2;
		for (int j=1; j<=n; j++) {
			int a=kmp(s1[j],q1);
			int b=kmp(s2[j],q2);
			if (a==-1 || b==-1 || a!=b) continue;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
