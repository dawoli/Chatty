#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;

int T,n,k,q,r,c;
int l[MAXN]={};
vector<int> f[MAXN]={};

bool ljy(int begin,int la,int nw) {
	if(nw==r+1) {
		if(begin==c) return true;
		else return false;
	} 
	bool flag=false;
	for(int i=1;i<=n;i++) {
		if(i==la) continue;
		else {
			for(int j=1;j<l[i];j++) {
				if(f[i][j]==begin) {
					for(int l=j+1;l<=j+k-1;l++) {
						if(ljy(f[i][l],i,nw+1)) {
							flag=true;
							break;
						}
					}
				}
				if(flag) break;
			}
		} 
		if(flag) break;
	}
	return flag;
}

int main() {
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>k>>q; int x;
		for(int i=1;i<=n;i++) {
			cin>>l[i];
			f[i].clear();
			f[i].push_back(0);
			for(int j=1;j<=l[i];j++) {
				cin>>x;
				f[i].push_back(x);
			}
		}
		while(q--) {
			cin>>r>>c;
			if(r==1) {
				bool flag=false;
				for(int i=1;i<=n;i++) {
					for(int j=1;j<l[i];j++) {
						for(int l=j+1;l<=j+k-1;l++) {
							if(f[i][j]==1 && f[i][l]==c) {
								flag=true;
								break;
							}
						}
						if(flag) break;
					}
					if(flag) break;
				}
				if(flag) cout<<1<<endl;
				else cout<<0<<endl;
			}
			else if(r!=1) cout<<ljy(1,0,1)<<endl;
		}
	}
	return 0;
}
