#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int t;
int n,k,q;
int a[N][N];
int main(){
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
    	memset(a,0,sizeof(a));
    	cin>>n>>k>>q;
    	for(int i=1;i<=n;i++){
    		cin>>a[i][0];
    		for(int j=1;j<=a[i][0];j++){
    			cin>>a[i][j];
			}
		}
		for(int u=1;u<=q;u++){
			int r,c;
			cin>>r>>c;
			if(r==1){
				bool gt=false;
				for(int i=1;i<=n;i++){
					vector<int> pos;
					for(int j=1;j<=a[i][0];j++){
						if(a[i][j]==1){
							pos.push_back(j);
						}
						if(a[i][j]==c){
							for(auto v:pos){
								if(j!=v && j-v+1<=k){
									gt=true;
									break;
								}
							}
						}
					}
				}
				if(gt) cout<<1<<"\n";
				else cout<<0<<"\n";
			}
		}
	}
	return 0;
}
