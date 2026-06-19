#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("chain1.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int maxl=-1,n,k,q,li;
		vector<bool> flag(100010,false);
		cin>>n>>k>>q;
		vector<int> chain[n+5];
		for(int i=0;i<n;i++){
			cin>>li;
			maxl=max(maxl,li);
			for(int j=0;j<li;j++){
				int c;
				cin>>c;
				flag[c]=true;
				chain[i][j]=c;
			}
		}
		for(int i=0;i<q;i++){
			int r,c;
			cin>>r>>c;
			if(!flag[c]){
				cout<<"0\n";
				continue;
			}
			if(r==1){
				int cnt=0,flag=0;
				for(int i=0;i<n;i++){
					for(int j=chain[i].size()-1;j;j--){
						if(chain[i][j]==c){
							cnt=k;
						}
						if(k&&chain[i][j]==1){
							flag=1;
							break;
						}
						k--;
					}
				}
				cout<<flag<<"\n";
			}
			cout<<1<<"\n";
		}
	}
	return 0;
}
