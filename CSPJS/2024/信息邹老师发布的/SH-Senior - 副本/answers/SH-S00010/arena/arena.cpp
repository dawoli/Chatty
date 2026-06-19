#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
const int N=200009;
const int mod=998244353;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		s=s*10+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int n,m,K;
int x[N],a[N],c[N];
char s[30][N];
int d[4];
struct node{int id,lim;};
vector<node> v[20][N];
inline void solveBF(){
	int _=read();
	while(_--){
		d[0]=read(); d[1]=read(); d[2]=read(); d[3]=read();
		for(int i=1;i<=n;i++)a[i]=x[i]^d[i%4];
//		for(int i=1;i<=n;i++)cout<<a[i]<<' '; cout<<'\n';
		ll qwq=0;
		for(int t=1;t<=m;t++){
			int L=ceil(log2(c[t])),o=(1<<L);
			for(int i=1;i<=o;i++){
				v[0][i].clear();
				if(i<=c[t])v[0][i].push_back((node){i,a[i]});
				else v[0][i].push_back((node){i,0});
			}
			for(int k=1;k<=L;k++){
				for(int i=1,cnt=1;i<=o;i+=(1<<k),cnt++){
					v[k][i].clear();
					int stp=(1<<(k-1));
					if(s[k][cnt]=='0'){
						int mn0=0x3f3f3f3f;
						for(node now:v[k-1][i]){
							mn0=min(mn0,now.lim);
							if(now.id<=c[t]&&now.lim>=k)v[k][i].push_back(now);
							if(now.id>c[t])v[k][i].push_back((node){now.id,k});
						}
						if(mn0<k)for(node now:v[k-1][i+stp])v[k][i].push_back(now);
					}
					else{
						int mn1=0x3f3f3f3f;
						for(node now:v[k-1][i+stp]){
							mn1=min(mn1,now.lim);
							if(now.id<=c[t]&&now.lim>=k)v[k][i].push_back(now);
							if(now.id>c[t])v[k][i].push_back((node){now.id,k});
						}
						if(mn1<k)for(node now:v[k-1][i])v[k][i].push_back(now);
					}
					//从i,i+(1<<(k-1))中合并 
				}
			}
			int ans=0;
			for(node now:v[L][1])ans+=now.id;
			qwq^=((ll)t*ans);
		}
		cout<<qwq<<'\n';
	}
}
inline bool check(){
	for(int i=1;i<=m;i++){
		int ooo=ceil(log2(c[i]));
		if(c[i]!=(1<<ooo))return 0;
	}
	return 1;
}
ll aans[30];
inline void solveA(){
	int _=read();
	while(_--){
		d[0]=read(); d[1]=read(); d[2]=read(); d[3]=read();
		for(int i=1;i<=n;i++)a[i]=x[i]^d[i%4];
//		for(int i=1;i<=n;i++)cout<<a[i]<<' '; cout<<'\n';
		ll qwq=0;
		for(int L=0;L<=floor(log2(n));L++){
			int o=(1<<L);
			for(int i=1;i<=o;i++){
				v[0][i].clear();
				if(i<=o)v[0][i].push_back((node){i,a[i]});
				else v[0][i].push_back((node){i,0});
			}
			for(int k=1;k<=L;k++){
				for(int i=1,cnt=1;i<=o;i+=(1<<k),cnt++){
					v[k][i].clear();
					int stp=(1<<(k-1));
					if(s[k][cnt]=='0'){
						int mn0=0x3f3f3f3f;
						for(node now:v[k-1][i]){
							mn0=min(mn0,now.lim);
							if(now.id<=o&&now.lim>=k)v[k][i].push_back(now);
							if(now.id>o)v[k][i].push_back((node){now.id,k});
						}
						if(mn0<k)for(node now:v[k-1][i+stp])v[k][i].push_back(now);
					}
					else{
						int mn1=0x3f3f3f3f;
						for(node now:v[k-1][i+stp]){
							mn1=min(mn1,now.lim);
							if(now.id<=o&&now.lim>=k)v[k][i].push_back(now);
							if(now.id>o)v[k][i].push_back((node){now.id,k});
						}
						if(mn1<k)for(node now:v[k-1][i])v[k][i].push_back(now);
					}
					//从i,i+(1<<(k-1))中合并 
				}
			}
			for(node now:v[L][1])aans[L]+=now.id;
		}
		for(int t=1;t<=m;t++){
			int L=log2(c[t]);
			qwq^=(ll)t*aans[L];
		}
		cout<<qwq<<'\n';
	}
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=m;i++)c[i]=read();
	K=ceil(log2(n));
	for(int i=1;i<=K;i++)scanf("%s",s[i]+1);
	if(n<=5000&&m<=5000){solveBF(); return 0;}
	if(check()){solveA(); return 0;}
	return 0;
}
