#include<bits/stdc++.h>
using namespace std;
int n,q,st,ed;
string x,y,tx,ty,tz,tw;
map<string,string>mp;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mp[x]=y;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		st=-1;
		cin>>tx>>ty;
		if(tx.size()!=ty.size()){
			printf("0\n");
			continue;
		}
		for(int j=0;j<tx.size();j++){
			if(tx[j]!=ty[j]){
				if(st==-1)st=j;
				ed=j;
			}
		}
		for(int j=0;j<=st;j++){
			for(int k=ed;k<tx.size();k++){
				tz.clear();
				tw.clear();
				for(int l=j;l<=k;l++){
					tz.push_back(tx[l]);
					tw.push_back(ty[l]);
				}
				if(mp[tz]==tw)ans++;
			}	
		}
		printf("%lld\n",ans);
	}
	return 0;
}
