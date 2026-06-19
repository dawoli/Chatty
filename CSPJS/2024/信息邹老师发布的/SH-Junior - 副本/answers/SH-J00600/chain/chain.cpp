#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int a[10010][20010];
int b[10010];
bool check(int x){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=b[i];++j)
			if(a[i][j]==x)
				return false;
	return true;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>k>>q;
		for(int j=1;j<=n;++j){
			cin>>b[j];
			for(int p=1;p<=b[j];++p){
				cin>>a[j][p];
			}
		}
		for(int j=1;j<=q;++j){
			int r,c;
			cin>>r>>c;
			if(check(c)){
				cout<<0<<endl;
				continue;
			}
			if(r==1){
				int x=-1;
				bool f=true;
				for(int l=1;l<=n;++l){
					x=-1;
					for(int p=2;p<=b[l];++p){
						if(a[l][p]==1){
							x=p;
							continue;
						}
						if(a[l][p]==c&&x!=-1){
							if(p-x+1<=k){
								f=false;
								break;
							}
						}
					}
					if(!f)
						break;
				}
				if(f)
					cout<<0;
				else
					cout<<1;
			}else
				cout<<1;
			cout<<endl;
		}
	}
	return 0;
}
