#include<bits/stdc++.h>

using namespace std;
int t,n;
long long a[100005][4],ans;
struct node{
	int num,z;
	long long cnt3;
}b[4][100005];
bool cmp(node x,node y){
	return x.cnt3<y.cnt3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	//	memset(a,0,sizeof(a));
	//	memset(b,0,sizeof(b));
		int cnt0=0,cnt1=0,cnt2=0;
		ans=0;
long long ans1=0,flagg=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			ans1+=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				node ttt;
				ttt.num=i,ttt.z=a[i][0],ttt.cnt3=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				b[0][++cnt0]=ttt;
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans+=a[i][1];
				node ttt;
				ttt.num=i,ttt.z=a[i][1],ttt.cnt3=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				b[1][++cnt1]=ttt;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
				ans+=a[i][2];
				node ttt;
				ttt.num=i,ttt.z=a[i][2],ttt.cnt3=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
				b[2][++cnt2]=ttt;
			}
		}
//cout<<ans1<<" 1\n";
//cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<" "<<n/2<<endl;
		if(cnt0<=n/2&&cnt1<=n/2&&cnt2<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		int op=0,cntcnt=0,d;
		if(cnt0>n/2) cntcnt=cnt0,d=cnt0-n/2;
		else if(cnt1>n/2) op=1,cntcnt=cnt1,d=cnt1-n/2;
		else op=2,cntcnt=cnt2,d=cnt2-n/2;
//cout<<op<<" "<<cntcnt<<" "<<d<<endl;
		sort(b[op]+1,b[op]+cntcnt+1,cmp);
//	cout<<ans<<endl;
		for(int i=1;i<=d;i++){
			ans-=b[op][i].cnt3;
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
