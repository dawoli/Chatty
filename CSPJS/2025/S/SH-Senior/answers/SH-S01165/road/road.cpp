#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+5,M=2e6+5,K=20;

int n,m,k;
struct Edge{
	int a,b,c;
	bool operator < (const Edge &t)const{
		return c<t.c; 
	}
}e[M];
Edge ke[K][N],se[M];
int v[K],fa[N+K],pos[K];

int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

LL work(int state){
	LL res=0;
	vector<int> ch;
	for(int i=1; i<=n+k; i++) fa[i]=i; 
	for(int j=0; j<k; j++)
		if(state>>j&1){
			res+=v[j+1];
			ch.push_back(j+1);
		}
	for(int i=0; i<=k; i++) pos[i]=1;
	int ccnt=ch.size();
//	cout<<res<<' '<<ccnt<<endl;
	for(int ecnt=1; ecnt<=ccnt*n; ecnt++){
		int p=-1;
		Edge now;
		for(auto t:ch){
			if(pos[t]<=n&&(p==-1||ke[t][pos[t]]<now)){
				p=t,now=ke[t][pos[t]];
			} 
		}
		pos[p]++,se[ecnt]=now;
	}
	int ia=1,ib=1,cnt=0;
	for(int ecnt=1; ecnt<=m+ccnt*n; ecnt++){
		Edge now;
		if(ia<=m&&(ib>ccnt*n||e[ia]<se[ib])) now=e[ia++];
		else now=se[ib++];
		int a=find(now.a),b=find(now.b);
		if(a!=b) fa[a]=b,res+=now.c;
		if(ecnt>(m+ccnt*n)/10&&!cnt){
			cnt++;
			bool suc=1;
			int anc=fa[1];
			for(int i=2; i<=n; i++)
				if(fa[i]!=anc){
					suc=0;
					break;
				}
			for(auto t:ch)
				if(fa[n+t]!=anc){
					suc=0;
					break;
				}
			if(suc){
				break;
			}
		}
		if(ecnt>(m+ccnt*n)/8&&cnt==1){
			cnt++;
			bool suc=1;
			int anc=fa[1];
			for(int i=2; i<=n; i++)
				if(fa[i]!=anc){
					suc=0;
					break;
				}
			for(auto t:ch)
				if(fa[n+t]!=anc){
					suc=0;
					break;
				}
			if(suc){
				break;
			}
		}
		if(ecnt>(m+ccnt*n)/4&&cnt==2){
			cnt++;
			bool suc=1;
			int anc=fa[1];
			for(int i=2; i<=n; i++)
				if(fa[i]!=anc){
					suc=0;
					break;
				}
			for(auto t:ch)
				if(fa[n+t]!=anc){
					suc=0;
					break;
				}
			if(suc){
				break;
			}
		}
		if(ecnt>(m+ccnt*n)/2&&cnt==3){
			cnt++;
			bool suc=1;
			int anc=fa[1];
			for(int i=2; i<=n; i++)
				if(fa[i]!=anc){
					suc=0;
					break;
				}
			for(auto t:ch)
				if(fa[n+t]!=anc){
					suc=0;
					break;
				}
			if(suc){
				break;
			}
		}
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int a,b,c;
		cin>>a>>b>>c; 
		e[i]={a,b,c};
	}
	sort(e+1,e+1+m);
	
	bool flag=1;
	for(int i=1; i<=k; i++){
		cin>>v[i];
		if(v[i]>0) flag=0;
		bool suc=0;
		for(int j=1; j<=n; j++){
			int c;
			cin>>c;
			if(!c) suc=1;
			ke[i][j]={n+i,j,c};
		}
		if(!suc) flag=0;
		sort(ke[i]+1,ke[i]+1+n);
	}
	
	LL res=1e18;
	if(flag) res=work((1<<k)-1);
	else{
		for(int i=0; i<1<<k; i++) res=min(res,work(i));
	}
	cout<<res<<endl;
	return 0;
}
