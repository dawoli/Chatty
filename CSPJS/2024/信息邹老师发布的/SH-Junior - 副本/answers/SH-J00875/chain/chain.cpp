#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T-->0){
		int n,k,q,l[100010],nn[100010];
		map<char,int> pos[1000];
		string a[100010];
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				int aa;
				cin>>aa;
				a[i]+=aa+'0';
				pos[i][a[i][j]]=j;
			}
		}
		for(int i=1;i<=q;i++){
			int r,c;
			bool flag=0;
			cin>>r>>c;
			char cc=c+'0'; 
			if(r==1){
				for(int i=1;i<=n;i++){
					if(!a[i].find('1')||!a[i].find(cc)) continue;
					if(pos[i][cc]-pos[i]['1']<=k){
						nn[i]=1;
						flag=1;
						break;
					}
				}
			}
			if(nn[i]%2){
				cout<<1<<endl;
				continue; 
			}
			else cout<<0<<endl;
		}
	}
	
	return 0;
} 
