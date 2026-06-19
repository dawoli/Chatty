#include<bits/stdc++.h>
#define INF 1e9
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define gc getchar()
using namespace std;
typedef long long ll;
namespace fastIO{
	ll read(){
		ll x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-'){
				f=-1;
			}
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
int T,n,k,qu,l[100009],s[200009],bel[200009];
struct node{
	int x,l;
};
vector<int> e[200009];
vector<int> nll;
bool vst[200009];
queue<node> q;
queue<node> nl;
void add(int x,int l){
	for(int i=x-1;bel[i]==bel[x]&&(x-i)<k;i--){
//		if(vst[i]) continue;
		q.push({i,l+1});
	}
}
signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	T=read();
	while(T--){
		n=read(),k=read(),qu=read();
		int sum=0;
		rep(i,0,2e5){
			e[i]=nll;
		}
	
		rep(i,1,n){
			l[i]=read();
			rep(j,1,l[i]){
				bel[sum+j]=i;
				s[sum+j]=read();
				e[s[sum+j]].push_back(sum+j);
			}
			sum+=l[i];
		}
		while(qu--){
			int r=read(),c=read();
			q=nl;
			for(int i=0;i<e[c].size();i++){
				add(e[c][i],0);
			}
			int fnd=0;
			while(!q.empty()){
				int x=q.front().x,l=q.front().l;q.pop();
//				cout<<x<<" "<<l<<endl;
//				vst[x]=1;
				if(l>r) break;
				if(l==r&&s[x]==1){
					fnd=1;
					break;
				}
				for(int i=0;i<e[s[x]].size();i++){
					if(bel[e[s[x]][i]]==bel[x]) continue;
					add(e[s[x]][i],l);
				}
			}
			cout<<fnd<<endl;
//			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
	}
	return 0;
}

