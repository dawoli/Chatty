#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;
struct p{
	char h,t;
	int l;
}s[100002][2002];
int size[100005];
int c,r;
bool a;
void dfs(char last,int step,int w){
	if(step==r-1){
		for(int i=1;i<=size[w];i++){
			if(s[w][i].h==last){
				for(int j=i;j<=size[w];j++){
					if(s[w][j].t==c&&j-i<=k){
						a=true;
						return;
					} 
				}
			}
		}
	}
	for(int i=1;i<=size[w];i++){
		if(s[w][i].h==last){
			for(int j=i;j<=size[w]&&j-i<=k;j++){
				if(w!=n) dfs(s[w][j].t,step+1,w);
				else dfs(s[w][j].t,step+1,1);
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l,x;
			cin>>l;
			size[i]=l;
			for(int j=1;j<=l;j++){
				cin>>x;
				s[i][j].t=x%10+'0';
				int y=1;
				while(x>=10){
					x/=10;
					y++;
				}
				s[i][j].h=x+'0';
				s[i][j].l=y;
			}
		}
		for(int i=1;i<=q;i++){
			a=false;
			cin>>r>>c;
//			dfs('1',0,1);
			if(a) cout<<1<<endl;
			else cout<<0<<endl;
 		} 
	}
	return 0;
}
