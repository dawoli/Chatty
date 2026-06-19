#include<stdio.h>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int MAXN=1e5+5;

int T,n;
ll ans;
bool isSP1,isSP2;
struct student{
	int w1;
	int w2;
	int w3;
}stu[MAXN];

void dfs(int dep,ll cnt,int n1,int n2,int n3){
	if(dep==n+1){
		ans=max(cnt,ans);
		return;
	}
	
	if(n1<n/2) dfs(dep+1,stu[dep].w1+cnt,n1+1,n2,n3);
	if(n2<n/2) dfs(dep+1,stu[dep].w2+cnt,n1,n2+1,n3);
	if(n3<n/2) dfs(dep+1,stu[dep].w3+cnt,n1,n2,n3+1);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		isSP2=1;isSP1=1; 
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].w1,&stu[i].w2,&stu[i].w3);
			if(stu[i].w3!=0){
				isSP2=0;
				isSP1=0;
			}
			if(stu[i].w2!=0) isSP1=0;
		}
		if(isSP1){
			int tmp[100005];
			for(int i=1;i<=n;i++){
				tmp[i]=stu[i].w1;
			}
			sort(tmp+1,tmp+1+n);
			for(int i=n;i>n/2;i--){
				ans+=tmp[i];
			}
			isSP2=0;
		}else if(isSP2){
			int tmp[100005];
			int num=0;
			for(int i=1;i<=n;i++){
				tmp[i]=stu[i].w2-stu[i].w1;
				sort(tmp+1,tmp+1+n);
				ans+=max(stu[i].w2,stu[i].w1);
				if(stu[i].w2>stu[i].w1){
					num++;
				}	
			}
			num=num-n/2;
			printf("%d\n",num);
			if(num>0){
				int tot;
				for(int i=1;i<=n;i++){
					if(tmp[i]>=0){
						if(num==tot) break;
						tot++;
						ans-=tmp[i];
					}
				}
			}else if(num<0){
				int tot;
				for(int i=n;i>=1;i--){
					if(tmp[i]<=0){
						if(num==tot) break;
						tot++;
						ans+=tmp[i];
					}
				}
			}
		}else{
			dfs(1,0,0,0,0);	
		}
		
		
		printf("%lld\n",ans);
	}
	return 0;
}
