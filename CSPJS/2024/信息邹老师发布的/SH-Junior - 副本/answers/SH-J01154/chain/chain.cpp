#include<bits/stdc++.h>
using namespace std;
struct str{
	int t,frm;
};
int t,n,k,q,s[200005],r,c;
vector<str> es[200005];
bool flag;
void dfs(int x,int y,int f){
	if(x==r){
		if(y==1)
			flag=1;
		return;
	}
	for(int i=0;i<es[y].size();i++){
		if(es[y][i].frm!=f) dfs(x+1,es[y][i].t,es[y][i].frm);
		if(flag) return;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1,l;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[j];
				str st;
				for(int m=j-1;m>max(j-k,0);m--){
					st.frm=i; st.t=s[m];
					es[s[j]].push_back(st);
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			flag=0;
			dfs(0,c,0);
			cout<<flag<<endl;
		}
	}
	return 0;
}
