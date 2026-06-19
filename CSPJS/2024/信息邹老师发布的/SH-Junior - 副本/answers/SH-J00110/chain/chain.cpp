#include<bits/stdc++.h>
using namespace std;
int a[1010][2010];
int main(){
//	freopen("chain2.in","r",stdin);
//	freopen("chain.out","w",stdout);
	int t,n,k,q;
	cin>>t>>n>>k>>q;
	for(int t2=1;t2<=t;t++){
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++)
				cin>>a[i][j];
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			for(int i=1;i<=n;i++)
				for(int j=2;j<=2010;j++){
					if(a[i][j]==c){
						cout<<1<<endl;
						break;
					}
					if(j==2001) cout<<0<<endl;
				}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
