#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100009];
vector<int> s[100009];
struct Pos{
	int x,pos;
};
vector<Pos> p[100009];
struct Query{
	int r,c;
}qu[100009];
bool cmp(Query &a,Query &b){
	return a.r<b.r;
}
namespace sol1{
	bool dfs(int now,int stp,int tgt,int from){
		//cout<<now<<' '<<stp<<' '<<tgt<<' '<<from<<endl;
		if(stp==0) return (now==tgt);
		Pos nowpos;
		for(int i=0;i<p[now].size();i++){
			nowpos=p[now][i];
			//cout<<"    "<<nowpos.x<<' '<<nowpos.pos<<endl;
			if(nowpos.x==from) continue;
			for(int j=1;j<k;j++){
				if(nowpos.pos+j>s[nowpos.x].size()) break;
				if(dfs(s[nowpos.x][nowpos.pos+j-1],stp-1,tgt,nowpos.x)) return 1;
			}
		}
		return 0;
	}
	void solve(){
		for(int i=1;i<=q;i++){
			cout<<dfs(1,qu[i].r,qu[i].c,0)<<endl;
		}
	}
} 
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1,tmp;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>tmp;
				s[i].push_back(tmp);
				p[tmp].push_back((Pos){i,j});
			}
		}
		for(int i=1;i<=q;i++){
			cin>>qu[i].r>>qu[i].c;
		} 
		sol1::solve();
	}
	
	return 0;
}
