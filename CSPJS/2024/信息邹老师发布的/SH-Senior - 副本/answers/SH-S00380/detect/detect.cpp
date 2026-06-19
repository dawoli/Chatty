#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000005
#define M 100005
int T,n,m,L,V,ans,ans2;
bool sp[N];//judge the speed 
int ap[M],ac,p[M];//average speed over,and its num 
int dd[M],aa[M],vv[M];
int tmp;
void check(int d,int v,int a){
	if(a==0){
		if(v>=V){
			if(p[m]>=d){
			   	tmp++;
//			        printf("%d %d %d\n",d,v,a);
			}			
		}
	}
	else if(a<0){
	  	if(v>V){
	   		int t=(v-V)/a;//time to be lower than V
		   	int s=v*t+0.5*a*t*t;
		   	for(int i=1;i<=m;i++)
		   	    if(p[i]>=d && p[i]<=s+d){
		   	    	tmp++;
//			        printf("%d %d %d\n",d,v,a);
		   	    	break;
				}
//		   	for(int x=d;x<=s;x++){
//		   		if(fl==1)break;
//		   	    for(int i=1;i<=m;i++)
//		   	        if(p[i]==x){
//		   	        	ans++;fl=1;
//		   	        	break;
//					}
//			}
		}
	}    
	else if(a>0){
		if(v>V){
			for(int i=m;i>=1;i--)
			    if(p[i]>=d){
			        tmp++;
//			        printf("%d %d %d\n",d,v,a);
			        break;
				}
		}
		else{
		int t=(V-v)/a;
		int s=v*t+0.5*a*t*t;
		if(s+d<=L){
			for(int i=m;i>=1;i--)
			    if(p[i]>=s+d){
			        tmp++;
//			        printf("%d %d %d\n",d,v,a);
			        break;
				}
		}
		}
	}
}
void solve_BF(){
	for(int j=1;j<=n;j++)
		check(dd[j],vv[j],aa[j]);
	printf("%d ",tmp);
	int tnt=tmp;
	int tot;
	for(int i=1;i<=m;i++){
	    tmp=0;
		tot=p[i],p[i]=-1;
	    for(int j=1;j<=n;j++)
		    check(dd[j],vv[j],aa[j]);
		if(tmp==tnt)
		    ans2++;
		p[i]=tot;
	}
	printf("%d\n",ans2);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf ("%d",&T);
	while(T--){
		bool allz=0;
		ans=0;ans2=0;
		scanf ("%d%d%d%d",&n,&m,&L,&V);
//		for(int i=1;i<=m;i++) p[i]=0;
		for(int i=1;i<=n;i++){
		    scanf ("%d %d %d",&dd[i],&vv[i],&aa[i]);
		    if(aa[i]!=0)
		        allz=1;
		}
		for(int i=1;i<=m;i++){
		    scanf ("%d",&p[i]);
		}
		sort(p+1,p+m+1);
		if(allz==0){
			for(int i=1;i<=n;i++)
			    if(p[m]>=dd[i] && vv[i]>V) ans++;
			if(ans>=1)ans2=m-1;
		    else ans2=m;
		    printf("%d ",ans);
		    printf("%d\n",ans2);
		    continue;
		}
		solve_BF();
	}
	return 0;
}
