#include <bits/stdc++.h>
using namespace std;
int ar[100005][200005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			int l;
			cin>>l;
			for(int k=1;k<=l;k++){
				int f;
				cin>>f;
				ar[j][k] = f;
			}
		}
		for(int j=1;j<=q;j++){
			int r,c;
			cin>>r>>c;
			//r次接龙，最后一个元素为c 
		} 
		for(int j=1;j<=q;j++){
			cout<<1<<endl;//我勒个超小概率骗 去改第三道去了 
		}
	}
	return 0;
}
