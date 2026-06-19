#include<bits/stdc++.h>
#define int long long
#define ar2 array<int,2>
#define ar3 array<int,3>
const int N=100005,M=20,mod=1e9+7,inf=1ll<<40;
int bit(int x){
	return 1ll<<x;
}
int lowbit(int x){
	return x&(-x);
}
int add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
int sub(int x,int y){
	x-=y;
	if(x<0)x+=mod;
	return x; 
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int powmod(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		y/=2;
		x=mul(x,x); 
	}
	return ans;
}
using namespace std;
int n,m,K,a[N],c[N];
int d[M][N];
char ch[N];
int b[N],MX,MK;
vector<ar2> ve[N];
int cl(int l,int r,vector<int> &x,vector<ar2> &y){
//	return 0;
	int p1=lower_bound(y.begin(),y.end(),ar2{l,0})-y.begin();
	int p2=upper_bound(y.begin(),y.end(),ar2{r,inf})-y.begin()-1;
	if(p1>p2)return -1;
	int ans=x[p2];
	if(p1!=0)ans-=x[p1-1];
	if(ans!=0)return ans;
	return 0;
}
void print(int k){
	printf("kkk %d\n",k);
	printf("-- ");
	for(auto p:ve[k])printf("%d ",p[0]);
	puts("");
}
void dfs(int k,int l,int r,int rd,int id){
	ve[k].clear();
	if(l==r){
		if(l<=MX){
			ve[k].push_back({l,a[l]});
		}else{
			for(int i=0;i<=MK;i++)ve[k].push_back({l,i});
		}
//		print(k);
		return ;
	}
	int mid=(l+r)/2;
	dfs(k+k,l,mid,rd-1,2*id-1);
	dfs(k+k+1,mid+1,r,rd-1,2*id);
//	return ; 
	int xs=ve[k+k].size(),ys=ve[k+k+1].size();
	vector<int> x(xs),y(ys);
	
	for(int i=0;i<xs;i++){
		if(ve[k+k][i][1]<rd)x[i]=1;
		else x[i]=0;
		if(i!=0)x[i]+=x[i-1];
	} 
	for(int i=0;i<ys;i++){
		int flag=0;
		int val=ve[k+k+1][i][1],p=ve[k+k+1][i][0];
		if(d[rd][id]==0){
			if(val>=rd){
				if(cl(p+1,bit(MK),x,ve[k+k])!=-1)flag=1;
			}		
			if(cl(1,p-1,x,ve[k+k])>0)flag=1;
		}else{
			
			if(val>=rd){
//				printf("cl %d %d\n",1,p-1);
				if(cl(1,p-1,x,ve[k+k])!=-1)flag=1;
			}		
			if(cl(p+1,bit(MK),x,ve[k+k])>0)flag=1;
		}
		if(flag)ve[k].push_back(ve[k+k+1][i]);
	}
//	return;
	swap(xs,ys);
	swap(x,y);
	swap(ve[k+k],ve[k+k+1]);
	for(int i=0;i<xs;i++){
		if(ve[k+k][i][1]<rd)x[i]=1;
		else x[i]=0;
		if(i!=0)x[i]+=x[i-1];
	} 
	for(int i=0;i<ys;i++){
		int flag=0;
		int val=ve[k+k+1][i][1],p=ve[k+k+1][i][0];
		if(d[rd][id]==0){
			if(val>=rd){
				if(cl(p+1,bit(MK),x,ve[k+k])!=-1)flag=1;
			}		
			if(cl(1,p-1,x,ve[k+k])>0)flag=1;
		}else{
			if(val>=rd){
				if(cl(1,p-1,x,ve[k+k])!=-1)flag=1;
			}		
			if(cl(p+1,bit(MK),x,ve[k+k])>0)flag=1;
		}
		if(flag)ve[k].push_back(ve[k+k+1][i]);
	}
	
	sort(ve[k].begin(),ve[k].end());
//	print(k);
}
int cal(int x){
//	printf("cal %d\n",x);
	MX=x;
	int k=0;
	while(bit(k)<x)k++;
	MK=k;
	dfs(1,1,bit(k),k,1);
	int ans=0;
	int siz=ve[1].size();
	for(int i=0;i<siz;i++){
		if(i==0||ve[1][i][0]!=ve[1][i-1][0])ans+=ve[1][i][0];
	}
	return ans;
}
void solve(){
	int X[5];
	for(int i=0;i<=3;i++)cin>>X[i];
//	if(X[0]!=1)return;
	for(int i=1;i<=n;i++){
		a[i]=min(b[i]^X[i%4],K);
	} 
	int ans=0;
//	printf("cal %d %d\n",2,cal(2));
	for(int i=1;i<=n;i++){
		ans^=i*cal(c[i]); 
//		printf("cal %d %d\n",i,cal(i));
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("arena.in","r",stdin);	
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&c[i]);
	}
	K=0;
	while(bit(K)<n)K++;
	for(int i=1;i<=K;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=bit(K-i);j++){
			d[i][j]=ch[j]-'0';
		}
	}
//	puts("WA");
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
