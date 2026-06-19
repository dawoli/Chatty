#include<bits/stdc++.h>
using namespace std;
int T,n,kk,q,rr,c,ans;
vector<int> S[100009];
void wrk(int i,int j,int k,int r){
	if(r==0){
		for(int p=j-1;p>=max(0,j-k+1);p--){
			if(S[i][p]==1){
				ans=1;
				return;
			}
		}
		return;
	}
	for(int p=j-1;p>=max(0,j-k+1);p--){
		for(int x=1;x<=n;x++){
			if(x==i){
				continue;
			}
			for(int y=0;y<S[x].size();y++){
				if(S[x][y]==S[i][p]){
					wrk(x,y,k,r-1);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	cin>>T;
	while(T--){
		cin>>n>>kk>>q;
		for(int i=1;i<=n;i++){
			S[i].clear(); 
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				int num;
				cin>>num;
				S[i].push_back(num);
			}
		}
		while(q--){
			bool flg=0;
			ans=0;
			cin>>rr>>c;
			for(int i=1;i<=n;i++){
				for(int j=0;j<S[i].size();j++){
					if(S[i][j]==c){
						wrk(i,j,kk,rr-1);
						if(ans==1){
							flg=1;
							break;
						}
					}
					ans=0;
				}
				if(flg==1){
					break;
				}
			}
			if(flg==1){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
