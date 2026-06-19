#include<bits/stdc++.h>
using namespace std;
//bool flag1;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*w;
}
const int MAXN=2e5+10,inf=-1e18,MAXM=1e6;
int T,n,a[MAXN],m;
long long val[MAXM<<2],lazy[MAXM<<2];
void init(){
	m=0;
}

void push_up(int rt){
	val[rt]=max(val[rt<<1],val[rt<<1|1]);
}
void push_down(int rt){
	if(lazy[rt]){
		int ls=rt<<1,rs=rt<<1|1;
		if(val[ls]!=inf){
			lazy[ls]+=lazy[rt];val[ls]+=lazy[rt];
		}
		if(val[rs]!=inf){
			lazy[rs]+=lazy[rt];val[rs]+=lazy[rt];
		}
		lazy[rt]=0;
	}
}
void build(int rt,int l,int r){
	if(l==r){
		val[rt]=inf;lazy[rt]=0;return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	push_up(rt);
}
void update(int rt,int l,int r,int pos,long long add){
	if(l==r){
		val[rt]=max(val[rt],add);
		return ;
	}
	push_down(rt);
	int mid=(l+r)>>1;
	if(pos<=mid)update(rt<<1,l,mid,pos,add);
	else update(rt<<1|1,mid+1,r,pos,add);
	push_up(rt); 
}
long long query(int rt,int l,int r,int pos){
	if(l==r){
		return val[rt];
	}
	push_down(rt);
	int mid=(l+r)>>1;
	if(pos<=mid)return query(rt<<1,l,mid,pos);
	else return query(rt<<1|1,mid+1,r,pos);
}
//bool flag2;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
//	cout<<(&flag2-&flag1)/1024/1024<<endl;
	T=read();
	while(T--){
		init();
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read(); 
			m=max(a[i],m);
		}
		long long ans=0;
		for(int i=2;i<=n;i++)if(a[i]==a[i-1])ans+=a[i];
		build(1,0,m);
		update(1,0,m,a[0],0);
		for(int i=2;i<=n;i++){
//			cout<<"  "<<query(1,0,m,a[i])+a[i]<<" "<<val[1]<<endl;
			long long T=query(1,0,m,a[i])+a[i];
			if(a[i]==a[i-1]){
				lazy[1]+=a[i];
				val[1]+=a[i];
			}
			query(1,0,m,a[i-1]);
			update(1,0,m,a[i-1],max(val[1],T));
			
			
//			cout<<query(1,0,m,a[i])<<" "<<i<<" "<<a[i]<<endl;
			
			
//			cout<<i<<"  "<<query(1,0,m,7)<<endl;
		}
		ans=max(ans,val[1]);
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<i;j++){
//				dp[i][j]=max(dp[i-1][j]+(a[i]==a[i-1]?a[i]:0),dp[i][j]);
//			}
//			for(int j=1;j<(i-1);j++){
//				dp[i][i-1]=max(dp[i][i-1],dp[i-1][j]+(a[i]==a[j]?a[i]:0));
//			}
//		}
		printf("%lld\n",ans);
	}
	
	return 0;
} 
