#include<cstdio>
#include<cstring>
const long long N = 100100;
const long long M = 3005;
struct car{
	long long d;
	long long v;
	long long a;
	long long bh,bh1,bh2;
	long long s_num,e_num;
	long long sm,em;
	long long sz,ez;
};
car c[N];
long long t,n,m,L,V,p[N],b[M][M],bb[N],pp[N],bp[N],answer,answer2;
long long abss(long long a);
void dfs(long long index,long long sum);
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t>0){
		t--;
		answer=0;answer2=N;
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		memset(b,0,sizeof(b));
		memset(bb,0,sizeof(bb));
		memset(pp,0,sizeof(pp));
		memset(bp,0,sizeof(bp));
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
			if(c[i].a==0){
				if(c[i].v>V){
					c[i].bh=c[i].bh1=c[i].bh2=1;
					c[i].s_num=c[i].d;
					c[i].e_num=L;
					c[i].sz=c[i].ez=0;
					c[i].sm=c[i].em=1;
				}
			}
			else if(c[i].a>0){
				if(c[i].v>=V){
					c[i].bh=c[i].bh1=c[i].bh2=1;
					c[i].s_num=c[i].d;
					c[i].e_num=L;
					c[i].sz=c[i].ez=0;
					c[i].sm=c[i].em=1;
					if(c[i].v==V){
						c[i].bh1=0;
					}
				}
				else{
					c[i].bh1=0;
					c[i].s_num=c[i].d;
					c[i].sz=V*V-c[i].v*c[i].v;
					c[i].sm=2*c[i].a;
					c[i].sz=abss(c[i].sz);
					c[i].sm=abss(c[i].sm);
					c[i].s_num+=c[i].sz/c[i].sm;
					c[i].sz%=c[i].sm;
					if(c[i].s_num>=L){
						c[i].bh=0;
					}
					else{
						c[i].bh=c[i].bh2=1;
						c[i].e_num=L;
						c[i].ez=0;c[i].em=1;
					}
				}
			}
			else{
				if(c[i].v>V){
					c[i].bh=c[i].bh1=1;c[i].bh2=0;
					c[i].s_num=c[i].d;
					c[i].sz=0;
					c[i].sm=1;
					c[i].e_num=c[i].d;
					c[i].ez=V*V-c[i].v*c[i].v;
					c[i].em=2*c[i].a;
					c[i].sz=abss(c[i].sz);
					c[i].sm=abss(c[i].sm);
					c[i].e_num+=c[i].ez/c[i].em;
					c[i].ez%=c[i].em;
				}
			}
		}
		for(long long i=1;i<=m;i++){
			scanf("%lld",&p[i]);
			for(long long j=1;j<=n;j++){
				if(c[j].bh==0)continue;
				if(!(p[i]>c[j].s_num || (p[i]==c[j].s_num && c[j].sz==0 && c[j].bh1==1))){
					continue;
				}
				if(!(p[i]<c[j].e_num || (p[i]==c[j].e_num && c[j].bh2==1))){
					continue;
				}
				b[j][i]=1;
			}
		}
		for(long long i=1;i<=n;i++){
			long long ok=0;
			for(long long j=1;j<=m;j++){
				if(b[i][j]==1){
					ok=1;
				}
			}
			if(ok==1){
				answer++;
				bp[i]=1;
			}
		}
		printf("%lld ",answer);
		dfs(1,0);
		printf("%lld\n",m-answer2);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
long long abss(long long a){
	return a<0?-a:a;
}
void dfs(long long index,long long sum){
	if(index>m){
		memset(pp,0,sizeof(pp));
		for(long long i=1;i<=m;i++){
			if(bb[i]==1){
				for(long long j=1;j<=n;j++){
					pp[j]=pp[j]|b[j][i];
				}
			}
		}
		for(long long i=1;i<=n;i++){
			if(bp[i]==1 && pp[i]==0){
				return ;
			}
		}
		if(sum<answer2){
			answer2=sum;
		}
		return ;
	}
	if(sum>=answer2){
		return ;
	}
	bb[index]=0;
	dfs(index+1,sum);
	bb[index]=1;
	dfs(index+1,sum+1);
}
