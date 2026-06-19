#include <bits/stdc++.h>
using namespace std;

int T,n,k,q;
int play[1005][10005];
int r[100005],c[100005];

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int aa=1;aa<=T;aa++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			for(int j=1;j<=a;j++) cin>>play[i][j];
		}
		for(int i=1;i<=q;i++) cin>>r[i]>>c[i];
	}
	return 0;
}
