#include<bits/stdc++.h>
using namespace std;
int jielong[10001][20001];
map<int,int>mp;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,k,q;
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
			int l;
			cin>>l;
			mp[j]=l;
			for(int z=1;z<=l;z++) cin>>jielong[j][z];
		}
		for(int j=1;j<=q;j++){
			int r,c;
			cin>>r>>c;
			bool flag=0;
			for(int x=1;x<=n;x++){
				for(int y=1;y<=mp[n];y++){
					if(jielong[x][y]==1){
						for(int z=1;z<=k-1;z++){
							if(jielong[x][y+z]==c){
								flag=1;
								cout<<1<<endl;
								break;
							}
						}
					}
				}
			}
			if(flag==0) cout<<0<<endl;
		}
	}
}
