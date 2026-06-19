#include <iostream>
#include <cstring>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
#define int long long
struct d{
	int a,b,c;
	int mincha;
	int maxshu;
	int maxid;
};
d q[100005];
int t[5];
int maxida[100005];
int maxidb[100005];
int maxidc[100005];
signed main(int argc, char** argv) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		memset(t,0,sizeof(t));
		memset(maxida,0,sizeof(maxida));
		memset(maxidb,0,sizeof(maxidb));
		memset(maxidc,0,sizeof(maxidc));
		int ans=0; int ra=1,rb=1,rc=1;
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&q[i].a,&q[i].b,&q[i].c);
			int a=q[i].a,b=q[i].b,c=q[i].c;
			if(a>=b and a>=c){
				q[i].maxshu=a;
				q[i].maxid=1;
				q[i].mincha=min(a-b,a-c);
				maxida[ra++]=q[i].mincha;
			}
			else if(b>=a and b>=c){
				q[i].maxshu=b;
				q[i].maxid=2;
				q[i].mincha=min(b-a,b-c);
				maxidb[rb++]=q[i].mincha;
			}
			else if(c>=a and c>=b){
				q[i].maxshu=c;
				q[i].maxid=3;
				q[i].mincha=min(c-a,c-b);
				maxidc[rc++]=q[i].mincha;
			}
			
			
		}
		sort(maxida+1,maxida+ra);
			sort(maxidb+1,maxidb+rb);
			sort(maxidc+1,maxidc+rc);
			for(int i=1;i<=n;i++){
				ans+=q[i].maxshu;
				t[q[i].maxid]++;
			}
//			printf("%d\n",ans);
			if(t[1]>n/2){
				int chao=t[1]-n/2;
				for(int i=1;i<=chao;i++){
					ans-=maxida[i];
				}
			}
			else if(t[2]>n/2){
				int chao=t[2]-n/2;
				for(int i=1;i<=chao;i++){
					ans-=maxidb[i];
				}
			}
			else if(t[3]>n/2){
				int chao=t[3]-n/2;
				for(int i=1;i<=chao;i++){
					ans-=maxidc[i];
				}
			}
		printf("%lld\n",ans);
	}

	return 0;
}
