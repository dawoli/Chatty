#include<cstdio>
#include<random>
#include<ctime>
using namespace std;
typedef long long LL;
const int N=200010,M=1000010;
int _,n;
LL res;
int a[N],p[N],l[M];
bool c[N];
mt19937 gen;
template<typename T>
T max(T &a,T &b){
	if(a<b)
		return b;
	return a;
}
void dfs(int u){
	if(u==n+1){
		int last0=0,last1=0;
		LL sum=0;
		for(int i=1;i<=n;i++)
			if(c[i]){
				if(a[i]==a[last1])
					sum+=a[i];
				last1=i;
			}
			else{
				if(a[i]==a[last0])
					sum+=a[i];
				last0=i;
			}
		res=max(res,sum);
		return;
	}
	c[u]=false;
	dfs(u+1);
	c[u]=true;
	dfs(u+1);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&_);
	gen.seed(time(NULL));
	while(_--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		res=0;
		if(n<=15){
			dfs(1);
			printf("%lld\n",res);
			continue;
		}
		for(int i=1;i<=n;i++){
			p[i]=l[a[i]];
			l[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(!p[i]){
				c[i]=gen()&1;
				continue;
			}
			bool col=c[p[i]+1],done=false,flag=true;
			for(int j=p[i]+2;j<i;j++){
				done=true;
				if(c[j]!=col){
					flag=false;
					break;
				}
			}
			if(done&&(col==c[p[i]]))
				flag=false;
			if(!flag){
				c[i]=gen()&1;
				continue;
			}
			res+=a[i];
			c[i]=c[p[i]];
		}
		printf("%lld\n",res);
		for(int i=1;i<=n;i++)
			l[a[i]]=0;
	}
	return 0;
}
