#include<bits/stdc++.h>
using namespace std;

int t;
int a[1005][2005];
int cnt[1005];

int fnd(int k,int vl){
	for(int i=1;i<=cnt[k];i++){
		if(a[k][i]==vl){
			return i;
		}
	}
	return -1;
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>cnt[i];
			for(int j=1;j<=cnt[i];j++){
				int s;
				cin>>s;
				a[i][j]=s;
			}
		}
		while(q--){
			int r,c;cin>>r>>c;
			int pos=0,st=1;
			bool cann=0;
			while(r--){
				pos++;
				int nxt=pos+1;
				if(pos>n){
					pos=1;
				}
				if(nxt>n){
					nxt=1;
				}
				if(fnd(pos,st)==-1){
					cann=0;
					break;
				}
				if(r==0){
					for(int i=fnd(pos,st)+1;i<=cnt[pos] && i<=fnd(pos,st)+k-1;i++){
						if(a[pos][i]==c){
							cann=1;
							break;
						}
					}
				}
				else{
					for(int i=fnd(pos,st)+1;i<=cnt[pos] && i<=fnd(pos,st)+k-1;i++){
						bool z=0;
						for(int j=1;j<=n;j++){
							if(i==j) continue;
							if(fnd(j,a[pos][i])!=-1){
								st=a[pos][i];
								z=1;
								break;
							}
						}
						if(z){
							break;
						}
					}
				}
			}
			cout<<cann<<"\n";
		}
	}
	return 0;
}
