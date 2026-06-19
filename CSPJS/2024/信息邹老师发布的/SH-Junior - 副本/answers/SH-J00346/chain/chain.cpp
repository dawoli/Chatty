#include<bits/stdc++.h>
using namespace std;
int len[100010];
int a[200010];
int start[100010];
int n,asd,maxlen;
void dfs(int r,int c,int end,int p){
	if(asd){
		return;
	}
	if(r==0){
		if(end==c){
			asd=1;
		} 
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==p){
			continue;
		}
		for(int j=start[i];j<start[i]+len[i];j++){
			if(a[j]==end){
				for(int k=j+1;k<start[i]+len[i];k++){
					if(k-j+1<2||k-j+1>maxlen){
						continue;
					}
					dfs(r-1,c,a[k],i);
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int q;
		cin>>n>>maxlen>>q;
		for(int i=1;i<=n;i++){
			cin>>len[i];
			start[i]=start[i-1]+len[i-1];
			for(int j=0;j<len[i];j++){
				cin>>a[start[i]+j];
			}
		}
		while(q--){
			asd=0;
			int r,c;
			cin>>r>>c;
			dfs(r,c,1,0);
			cout<<asd<<endl;
		}
	}
	return 0;
}
