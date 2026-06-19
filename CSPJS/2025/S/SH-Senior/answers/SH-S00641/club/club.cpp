#include<bits/stdc++.h>
using namespace std;
int n,q[100010];
struct node{int a,b,c;}edge[100010];
inline bool CMP(node u,node v){return u.a+u.b+u.c>v.a+v.b+v.c;}
inline bool is_A(){for(int i=1;i<=n;i++)if(edge[i].b!=0&&edge[i].c!=0)return 0;return 1;}
inline bool is_B(){for(int i=1;i<=n;i++)if(edge[i].c!=0)return 0;return 1;}
bool cmpA(int x,int y){return x>y;}
bool cmpB(node x,node y){return x.a>y.a;}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>edge[i].a>>edge[i].b>>edge[i].c;
	if(n==2){
		int x=edge[1].a+edge[2].b;
		int z=edge[1].a+edge[2].c;
		
		int y=edge[1].b+edge[2].c;
		int q=edge[1].b+edge[2].a;
		
		int u=edge[1].c+edge[2].b;
		int v=edge[1].c+edge[2].a;
		
		cout<<max(x,max(y,max(z,max(q,max(u,v)))))<<"\n";
		
	}
	if(is_A()){
		int Ans=0;
		for(int i=1;i<=n;i++)q[i]=edge[i].a;
		sort(q+1,q+n+1,cmpA);
		for(int i=1;i<=n/2;i++)Ans+=q[i];
		cout<<Ans<<"\n";
		return;		
	}
	
	if(is_B()){	
		sort(edge+1,edge+n+1,cmpB);
		int A=0,cc=0;
		for(int i=1;i<=n;i++){			
			int X=max(edge[i].a,edge[i].b);
			int Y=min(edge[i].a,edge[i].b);
			
			if(A<n/2)cc+=X,A++;
			else cc+=Y;
		}
		cout<<cc<<"\n";
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;while(T--)
	solve();
	return 0;
}
