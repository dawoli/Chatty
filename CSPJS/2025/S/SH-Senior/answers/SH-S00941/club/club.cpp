#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100001][4],sot[100001][5],cpct[4],nxt[100001],ans;
struct node{
	int digit,inde;
}rsk[100001];
bool cmp(node _n_,node _m_){
	return _n_.digit<_m_.digit;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(sot,0,sizeof(sot));
		memset(cpct,0,sizeof(cpct));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				if(a[i][j]==max(max(a[i][1],a[i][2]),a[i][3])&&sot[i][0]!=j)sot[i][1]=j;
			for(int j=1;j<=3;j++)
				if(a[i][j]==a[i][1]+a[i][2]+a[i][3]-max(max(a[i][1],a[i][2]),a[i][3])-min(min(a[i][1],a[i][2]),a[i][3])&&sot[i][1]!=j)sot[i][2]=j;
			for(int j=1;j<=3;j++)
				if(sot[i][1]!=j && sot[i][2]!=j)sot[i][3]=j;
		}
		for(int i=1;i<=n;i++){
			nxt[i]=2;
			rsk[i].digit=a[i][sot[i][nxt[i]-1]]-a[i][sot[i][nxt[i]]];
			rsk[i].inde=i;	
			cpct[sot[i][nxt[i]-1]]++;
			ans+=a[i][sot[i][nxt[i]-1]];
			sot[i][4]=0;
		}
		for(int i=1;i<=3;i++){
			if(cpct[i]>n/2){
				sort(rsk+1,rsk+1+n,cmp);
				int j=1;
				while(cpct[i]>n/2){
					if(sot[rsk[j].inde][nxt[rsk[j].inde]-1]==i&&nxt[rsk[j].inde]<=3){
						cpct[i]--;
						ans-=rsk[j].digit;
						nxt[rsk[j].inde]++;
						rsk[j].digit=a[rsk[j].inde][sot[rsk[j].inde][nxt[rsk[j].inde]-1]]-a[rsk[j].inde][sot[rsk[j].inde][nxt[rsk[j].inde]]];
					}
					j++;
				}
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
