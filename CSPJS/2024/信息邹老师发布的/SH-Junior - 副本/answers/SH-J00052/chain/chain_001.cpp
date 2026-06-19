#include<bits/stdc++.h>
using namespace std;
struct S{
	int l;
	vector<int> s;
};
struct rw{
	int r,c;
};
int n,k,q;
vector<S> s,a;
vector<rw> r,b;
bool jl(int c,int mr,int r,int ln,int lp) {
	if(r>mr) return true;
	bool f=false;
	for(int j=0;j<n;j++) {
		if(j==lp) continue;
		for(int S=0;S<s[j].l-1;S++) {
			if(s[j].s[S]!=ln) continue;
			for(int E=S+1;E<s[j].l;E++) {
				if(E-S+1>k||(mr-r==0&&s[j].s[E]!=c)) continue;
				bool F;
				F=jl(c,mr,r+1,s[j].s[E],j);
				if(F) f=F;
			}
		}
	}
	return f;
}
int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++) {
		s=a;
		r=b;
		cin>>n>>k>>q;
		s.resize(n);
		r.resize(q);
		for(int j=0;j<n;j++) {
			cin>>s[j].l;
			s[j].s.resize(s[j].l);
			for(int k=0;k<s[j].l;k++) cin>>s[j].s[k];
		}
		for(int j=0;j<q;j++) {
			cin>>r[j].r>>r[j].c;
			bool f=jl(r[j].c,r[j].r,1,1,-1);
			if(f) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
