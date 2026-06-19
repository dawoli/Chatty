#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const int M=1e6+9;
int T,n,m,L,V,d,v,a,l[N],r[N],p[N],match[M],s[M],c[N];
bool ok[N];

bool cmp(int x,int y){
	return r[x]<r[y];
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=0;i<N;i++) {
			l[i]=L+1,r[i]=L+1;
			p[i]=0;
			c[i]=i;
			ok[i]=false;
		}
		for(int i=0;i<M;i++){
			match[i]=0,s[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d,&v,&a);
			if(a==0){
				if(v>V){
					l[i]=d;
					r[i]=L;
				}
			}
			else if(a>0){
				if(v>V){
					l[i]=d;
					r[i]=L;
				}
				else{
					l[i]=(V*V-v*v)/(2*a)+d+1;
					r[i]=L;
					l[i]=min(l[i],L+1);
				}
			}
			else{
				if(v>V){
					l[i]=d;
					r[i]=d-(v*v-V*V-1)/(2*a);
					r[i]=min(r[i],L);
				}
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			match[p[i]]++;
		}
		for(int i=1;i<=L;i++)
			s[i]=s[i-1]+match[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[r[i]]-s[l[i]-1]>0){
				ans++;
				ok[i]=true;
			}
		}
		printf("%d ",ans);
		sort(c+1,c+n+1,cmp);
		int pos=-1;
		ans=m;
		for(int i=1;i<=n;i++){
			if(!ok[c[i]]) continue;
			if(pos>=l[c[i]] and pos<=r[c[i]]) continue;
			ans--;
			for(int j=pos+1;j<=r[c[i]];j++){
				if(match[j]>0)
					pos=j;
			}
		}
		printf("%d\n",ans);
	}
}
