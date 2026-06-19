#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int numwant[10];

int stu[4][100010];
int T,N;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=3;i++)
			memset(stu[i],0x00,sizeof(int)*(N+2));
		memset(numwant,0x00,sizeof(numwant));
		long long ans=0;
		for(int i=0;i<N;i++){
			int a1,a2,a3;
			scanf("%d%d%d",&a1,&a2,&a3);
			int mx=max(max(a1,a2),a3);
			ans+=mx;
			if(mx==a1){
				stu[1][numwant[1]]=a1-max(a2,a3);
				numwant[1]++;
			}else if(mx==a2){
				stu[2][numwant[2]]=a2-max(a1,a3);
				numwant[2]++;
			}else{
				stu[3][numwant[3]]=a3-max(a1,a2);
				numwant[3]++;
			}
		}
		sort(stu[1],stu[1]+numwant[1]);
		sort(stu[2],stu[2]+numwant[2]);
		sort(stu[3],stu[3]+numwant[3]);
		for(int i=1;i<=3;i++){
			for(int j=0;2*(numwant[i]-j)>N;j++){
				ans-=stu[i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
