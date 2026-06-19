#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7;

int a[N][N],l[N];

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++)cin>>a[i][j];
			
		}
		for(int i=1;i<=q;i++){
			int c,r;
			cin>>c>>r;
			bool f=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=l[i];j++){
					if(a[i][j]==1){
						for(int o=1;o<k;o++){
							if(a[i][j+o]==c){
								cout<<1<<'\n';
								f=1;
							}
						}
					}
				}
			}
			if(f==1)continue;
			if((c+r)%3)cout<<0<<'\n';
			else cout<<1<<'\n';
		}
	}
	return 0;
} 
