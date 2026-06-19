#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(register int i=(l);i<=(r);i++)
#define per(i,r,l) for(register int i=(r);i>=(l);i--)
#define repn(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int N=2e5+10, inf=1e9; // 2e5

int n,m,k,s,a[N],mp[N],res[N];

int lim;
int op[N<<1],tr[N<<1];

set<int> cant;

int sum;
bool can[N];
void add(int x){
	printf("  add %d\n",x);
	if(!can[x]){
		assert(cant.find(x) != cant.end());
		can[x]=true, sum+=x, cant.erase(x);
		assert(cant.find(0) == cant.end());
	}
}

void init(){
	rep(i,s,s+s-1) tr[i]=i-s+1;
	per(i,s-1,1) tr[i]=tr[i<<1];
}
void upd(int u, int x){
	printf("  upd %d %d\n",u,x);
	a[u]=x;
	u+=(s-1);
	for(int i=u>>1,j=1; i>0; i>>=1, j++){
		if(op[i]==0)	tr[i] = a[tr[i<<1]] >= j ? tr[i<<1] : tr[i<<1|1];
		else		  tr[i] = a[tr[i<<1|1]] >= j ? tr[i<<1|1] : tr[i<<1];
	}
}

signed main(){
	freopen("arena1.in","r",stdin);
//	freopen("arena.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,m){
		int c; cin>>c;
		mp[c]=i;
	}
	s=1,k=0; while(s<n) s<<=1, k++;
	per(i,k-1,0){
		rep(j,0,(1<<i)-1){
			char ch; cin>>ch;
			op[(1<<i)+j]=ch-'0';
		}
	}
	
	init();
	
	int T; cin>>T;
	
	while(T--){
		rep(i,1,s) cant.insert(i); // s 不是 n 
		assert(cant.find(0) == cant.end());
		
		int x[4]; rep(i,0,3) cin>>x[i];
		rep(i,1,n){
			a[i]^=x[i%4];
			upd(i, a[i]);
		}
		
		rep(i,n+1,s){
			upd(i, -1);
		}
		printf("all -1\n");
		add(tr[1]);
		
		rep(i,n+1,s){
			upd(i, inf);
			printf("let %d = inf\n",i);
			if(tr[1]==i) add(tr[1]);
			upd(i, -1);
		}
		
		printf("结束1\n");
		
		per(i,n,1){
			printf("开始 i = %d\n",i);
			upd(i, inf);
			printf("let %d = inf\n",i);
			if(tr[1]==i) add(tr[1]);
			printf("let %d =  -1\n",i);
			upd(i, -1);
			add(tr[1]);
			if(mp[i])
			{
			//	for(int j:cant){
				for(auto it=cant.begin(); it!=cant.end(); it++){
					int j=*it;
					if(j<i) continue; //
					printf("let %d = inf\n",j);
					upd(j, inf);
					if(tr[1]==j) add(tr[1]);
					upd(j, -1);
				}
				res[mp[i]]=sum;
			}
			printf("结束 i = %d\n",i);
		}
		
		int out=0;
		rep(i,1,m){
			printf("res[%d] = %d\n",i,res[i]);
			out^=(i*res[i]);
			res[i]=0;
		}
		cout<<out<<endl<<endl;
		
		sum=0;
		rep(i,1,s) can[i]=false;
		cant.clear();
	}
	return 0;
}
