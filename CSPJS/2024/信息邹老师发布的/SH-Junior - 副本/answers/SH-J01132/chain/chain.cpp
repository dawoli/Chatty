#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int pt[N];
map<int,bool>mp;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			int l;
			scanf("%d",&l);
			for(int j=0;j<l;j++){
				scanf("%d",&pt[j]);
			}
			for(int l1=0;l1<l;l1++){
				if(pt[l1]==1){
					for(int r1=l1+1;r1<min(l-1,l1+k);r1++){
						mp[pt[r1]]=1;
					}
				}
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			cout<<mp[c]<<endl;
		}
	}	
	flcose(stdin);
	fclose(stdout);
	return 0;
}
