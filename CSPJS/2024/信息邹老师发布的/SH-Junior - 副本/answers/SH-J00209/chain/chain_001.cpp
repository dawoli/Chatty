#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,q,tmp,r,c,l;
bool f,fans;
vector<ll> s[100005];
void dfs(int a,int peo,int per){
	if(f) return ;
	if(peo==r){
		if(a==c)  f=1;
		return ;
	}
	for(int x=0;x<s[per].size();x++)
		if(s[per][x]==a)
	    	for(int i=1;i<k&&(x+i)<s[per].size();i++)
				for(int j=1;j<=n;j++){
					if(j==per) continue;
					dfs(s[per][x+i],peo+1,j);
				}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(ll i=0;i<t;i++){
		cin>>n>>k>>q;
		for(ll j=1;j<=n;j++){
			cin>>l;
			for(ll x=0;x<l;x++){
				cin>>tmp;
				s[j].push_back(tmp);
			}
		}
		for(ll j=0;j<q;j++){
			cin>>r>>c;
			f=0;
			for(ll x=1;x<=n;x++)  dfs(1,0,x);
			if(fans==1)
			    cout<<endl;
			else
			    fans=1;
			cout<<f;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//1
//3 3 7
//5 1 2 3 4 1
//3 1 2 5
//3 5 1 6
//1 2
