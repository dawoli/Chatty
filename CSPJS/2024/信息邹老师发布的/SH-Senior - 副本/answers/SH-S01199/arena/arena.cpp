#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdio>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=100010,K=20;
int _,n,m,k;
int a[N],res[N];
PII c[N];
bool d[1<<K];
inline int getidx(int r,int g){
	int idx=0;
	for(int i=1;i<r;i++)
		idx+=(1<<(k-i));
	idx+=g;
	return idx;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i].first);
		c[i].second=i;
	}
	sort(c+1,c+m+1);
	while((1<<k)<n)
		k++;
	for(int i=1;i<=k;i++){
		static char str[1<<K];
		scanf("%s",str);
		for(int j=0;j<(1<<(k-i));j++)
			d[getidx(i,j)]=(str[j]=='1');
	}
	scanf("%d",&_);
	while(_--){
		static int x[4];
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		for(int i=1;i<=n;i++)
			a[i]^=x[i&3];
		for(int i=1;i<=m;i++){
			int last=c[i].first,backup=last,r=0;
			static PII a[N],b[N];
			for(int j=1;j<=last;j++)
				a[j]=PII(::a[j],j);
			while(last!=1){
				r++;
				int len=0;
				for(int j=1;j<=last;j+=2){
					int canidx;
					if(d[getidx(r,j>>1)]){
						if(a[j].second>a[j+1].second)
							canidx=j;
						else canidx=j+1;
					}
					else{
						if(a[j].second<a[j+1].second)
							canidx=j;
						else canidx=j+1;
					}
					if(canidx==j){
						if(a[j].first>=r)
							b[++len]=a[j];
						else b[++len]=a[j+1];
					}
					else{
						if(a[j+1].first>=r)
							b[++len]=a[j+1];
						else b[++len]=a[j];
					}
				}
				last=len;
				memcpy(a,b,sizeof a);
			}
			int ans=a[1].second;
			last=backup;
			while(c[i].first==last){
				res[c[i].second]=ans;
				i++;
			}
			i--;
		}
//		for(int i=1;i<=m;i++)
//			printf("%d ",res[i]);
//		puts("");
		LL ans=0;
		for(int i=1;i<=m;i++)
			ans^=(LL)i*res[i];
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			a[i]^=x[i&3];
	}
	return 0;
}
