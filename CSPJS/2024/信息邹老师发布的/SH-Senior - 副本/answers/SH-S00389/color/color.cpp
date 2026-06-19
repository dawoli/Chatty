#include<cstdio>
using namespace std;
long long t,n,a[200010],chose[200010],lastchose[2],ans,score;

long long max(long long x,long long y){
	return x>y? x : y;
}

void dfs(long long x){
	if(x==n+1){
		ans=max(ans,score);
		return;
	}
	for(int i=0;i<2;i++){
		chose[x]=i;
		long long score1=score;
		if(lastchose[i]==a[x]) score+=a[x];
		long long lastchose1=lastchose[i];
		lastchose[i]=a[x];
		dfs(x+1);
		score=score1;
		lastchose[i]=lastchose1;
	}
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=0;
		score=0;
		lastchose[0]=0,lastchose[1]=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
} 
