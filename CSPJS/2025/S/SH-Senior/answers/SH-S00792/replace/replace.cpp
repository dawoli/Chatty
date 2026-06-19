#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
const int P=1e9+7;
const int B=26;
int n,q;
int ans[N];
string s1[N];
string s2[N];
string t1[N];
string t2[N];
int hashs[N][2];
int hasht[N][2];
int ksm(int a,int b,int P) {
	long long res=1;
	while(b) {
		if (b&1) res=(res*b)%P;
		b>>=1;
		a=(a*a)%P;
	}
	return res;
}
int gethash(string s) {
	int l=s.size();
	int a=0,b=0; 
	for(int i=1;i<=l;i++) {
		a+=(1ll*s[i]*ksm(B,i-1,P));
	}
	return a;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>s1[i];
		cin>>s2[i];
	}
	for (int i=1;i<=q;i++) {
		cin>>t1[i];
		cin>>t2[i];
		if (t1[i].size()!=t2[i].size()) {
			cout<<0<<endl;
			continue;
		}
		for (int j=0;j<=t1[i].size()-(t1[i].size()-s1[i].size()+1);j++) {
			for(int i1=1;i1<=n;i1++) {
				bool flag=1;
				for (int k=0;k<s1[i1].size();k++) {
					if (s1[i1][k]!=t1[i][j+k]) flag=0;continue;
				}
				for (int k=0;k<s2[i1].size();k++) {
					if (s2[i1][k]!=t2[i][j+k]) flag=0;continue;
				}
				for (int r=0;r<j;r++) {
					if (t1[i][r]!=t2[i][r]) flag=0;continue;
				}
				for (int r=j+s2[i].size();r<t1[i].size();r++) {
					if (t1[i][r]!=t2[i][r]) flag=0;continue;
				}
				if (flag==1)ans[i]++;
			}
			
		} 
		 
	}
	for (int i=1;i<=q;i++) {
		cout<<ans[i]<<endl;
	}
	return 0;
}

