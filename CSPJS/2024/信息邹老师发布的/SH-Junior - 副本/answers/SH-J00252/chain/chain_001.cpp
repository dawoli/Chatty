#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,f,l,mx,g,x;
bool ck[200005];
vector<int> s[100005];
int jl(int a,int r,int p){
	if(r==1){
		for(int i=1;i<s[p][0];i++)
			if(s[p][i]==a)
				for(int j=1;j<k;j++)
					if(s[p][i+j]==c) return 1;
		return 0;
	}
	bool gk[200005];
	memset(gk,0,sizeof(gk));
	for(int i=1;i<s[p][0];i++)
		if(s[p][i]==a){
			for(int j=1;j<k;j++)
				if(!gk[s[p][i+j]]){
					for(int b=1;b<=n;b++){
						if(b==p) continue;
						if(jl(s[p][i+j],r-1,b)) return 1;
					}
					gk[s[p][i+j]]=1;
				}
		}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		memset(s,0,sizeof(s));
		memset(ck,0,sizeof(ck));
		for(int i=1;i<=n;i++){
			cin>>l;
			s[i].push_back(l);
			for(int j=1;j<=l;j++){
				cin>>x;
				s[i].push_back(x);
				ck[x]=1;
			}
		}
		while(q--){
			f=0;
			cin>>r>>c;
			if(ck[c]){
				for(int i=1;i<=n;i++)
					if(jl(1,r,i)){
						f=1;
						break;
					}
			}
			cout<<f<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
