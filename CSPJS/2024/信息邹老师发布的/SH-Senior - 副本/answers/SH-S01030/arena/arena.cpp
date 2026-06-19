#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*w;
}
const int MAXN=1e5+10;
int n,m,T;
int A[MAXN],c[MAXN],a[MAXN],ta[MAXN];
string s[131100];
int K,tw[21],k[MAXN];
int wine[21][MAXN];
void work(int N){
	int l=1;
	for(int i=1;i<=N;i++)wine[0][i]=i;
	while(N!=1){
		N=N/2;
		for(int i=1;i<=N;i++){
			if(s[l][i-1]=='0'){
				if(a[wine[l-1][2*i-1]]>=l){
					wine[l][i]=wine[l-1][2*i-1];
				}else wine[l][i]=wine[l-1][2*i];
			}else{
				if(a[wine[l-1][2*i]]>=l){
					wine[l][i]=wine[l-1][2*i];
				}else wine[l][i]=wine[l-1][2*i-1];
			}
		}
		l++;
	}
}
int vis[110];
long long sum=0;
void solve(int now,int tar,int ran,int num){
	if(now==tar){
		work(tar);
		if(!vis[wine[ran][1]]){
			vis[wine[ran][1]]=1;
			sum+=wine[ran][1];
//			cout<<num<<":"<<wine[ran][1]<<" can"<<endl;
		}
	}else{
		for(int i=0;i<=ran;i++){
			a[now+1]=i;
			solve(now+1,tar,ran,num);
		}
	}
}
int X[10];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)A[i]=read();
	for(int i=1;i<=m;i++)c[i]=read();
	tw[0]=1;K=-1;
	for(int i=1;i<=20;i++){
		tw[i]=tw[i-1]*2;
		if(K==-1&&tw[i]>=n)K=i;
	}
	for(int i=1;i<=K;i++)cin>>s[i];
	T=read();
	while(T--){
		X[0]=read();X[1]=read();X[2]=read();X[3]=read();
		for(int i=1;i<=n;i++){
			a[i]=A[i]^(X[i%4]);
			ta[i]=a[i];
		}
		int flag=0,N=0;
		for(int i=1;i<=m;i++){
			if(c[i]==1){
				k[i]=0;continue;
			}
			for(int j=20;j>=0;j--){
				if(tw[j]<c[i]){
					k[i]=j+1;break;
				}
			}
			N=max(N,c[i]);
			if(c[i]!=tw[k[i]]){
				flag=1;
			}
		}
		if(!flag){
			work(N);
			long long ans=0;
			for(int i=1;i<=m;i++){
				ans^=(i*1ll*wine[k[i]][1]);
			}
			printf("%lld\n",ans);
			continue;
		}
		long long ans=0;
		for(int i=1;i<=m;i++){
//			cout<<k[i]<<" "<<n<<" "<<tw[k[i]]<<endl;
			if(tw[k[i]]<=c[i]){
				ans^=(i*1ll*wine[k[i]][1]);
			}else{
//				cout<<"i:"<<i<<endl;
				sum=0;
				memset(vis,0,sizeof(vis));
				solve(c[i],tw[k[i]],k[i],i);
				ans^=(i*1ll*sum);
				for(int i=1;i<=n;i++)a[i]=ta[i];
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
} 
