#include <bits/stdc++.h>
using namespace std;
int x[1001][2001];
int n,k,q;
bool search(int last,int no,int time){
	if(time==0){
		if(last==1)return true;
		else return false;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=2001&&x[i][j]!=0;j++){
			if(x[i][j]==last&&i!=no){
				for(int m=2;m<=k&&j-m+1>=1;m++){
					if(search(x[i][j-m+1],i,time-1)) return true;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++) cin>>x[i][j];
		}
		while(q--){
			int r,end;
			cin>>r>>end;
			if(search(end,-1,r)) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
} 
