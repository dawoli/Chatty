#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;

struct Node {
	int l;
	string st;
	string ed;
};

int n,q;
Node f[MAXN];
int t[MAXN]={};
int c[100]={};
string a,b;

bool cmp(Node x,Node y) {
	return x.l>y.l;
}

string sub(string tar,int x,int y) {
	string res="";
	for(register int i=x;i<=y;i++) {
		res=res+tar[i];
	}
	return res;
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(register int i=1;i<=n;i++) {
		cin>>f[i].st>>f[i].ed;
		f[i].l=f[i].st.size();
		for(register int j=0;j<f[i].l;j++) {
			c[f[i].st[j]-'a'+1]++;
			c[f[i].ed[j]-'a'+1]++;
		}
	}
	bool flag=false;
	for(register int i=3;i<=26;i++) {
		if(c[i]>0) {
			flag=true;
			break;
		}
	}
	if(flag) {
		sort(f+1,f+n+1,cmp);
		while(q--) {
			cin>>a>>b;
			int m=a.size();
			if(m!=b.size()) {
				cout<<0<<endl;
			}
			else {
				int ggg1,ggg2;
				for(register int i=0;i<m;i++) {
					if(a[i]!=b[i]) {
						ggg1=i;
						break;
					}
				}
				for(register int i=m-1;i>=0;i--) {
					if(a[i]!=b[i]) {
						ggg2=i;
						break;
					}
				}
				int rel=ggg2-ggg1+1; int ans=0;
				for(register int i=1;i<=n;i++) {
					if(f[i].l<rel) {
						break;
					}
					for(register int j=0;j<=ggg1;j++) {
						if(j+f[i].l-1>m-1) break;
						if(sub(a,j,j+f[i].l-1)==f[i].st && sub(a,0,j-1)+f[i].ed+sub(a,j+f[i].l,m-1)==b) {
							ans++;
						}
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	if(!flag) {
		int np=f[1].st.find("c");
		for(register int i=1;i<=n;i++) {
			t[i]=f[i].ed.find("b")-f[i].st.find("b");
		}
		while(q--) {
			cin>>a>>b;
			int m=a.size();
			if(m!=b.size()) {
				cout<<0<<endl;
			}
			else {
				int ans=0;
				int tmp=b.find("b")-a.find("b");
				for(register int i=1;i<=n;i++) {
					if(tmp==t[i] && a.find(f[i].st)!=np) {
						ans++;
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
