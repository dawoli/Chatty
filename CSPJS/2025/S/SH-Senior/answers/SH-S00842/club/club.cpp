#include<bits/stdc++.h>
using namespace std;
int T,N,cnt1,cnt2,cnt3,ans,num;
struct S{
	int x,y,z;
}x[100011],y[100011],z[100011];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		memset(z,0,sizeof z);
		cnt1=cnt2=cnt3=ans=0;
		for(int i=1;i<=N;i++){
			S in;
			scanf("%d%d%d",&(in.x),&(in.y),&(in.z));
			if(in.x>=in.y&&in.x>=in.z)x[++cnt1]=in;
			else if(in.y>=in.x&&in.y>=in.z)y[++cnt2]=in;
			else z[++cnt3]=in;
			ans+=max(max(in.x,in.y),in.z);
		}
		if(cnt1<=N/2&&cnt2<=N/2&&cnt3<=N/2)printf("%d\n",ans);
		else{
			if(cnt1>N/2)num=1;else if(cnt2>N/2)num=2;else num=3;
			if(num==1){
				sort(x+1,x+1+cnt1,[](S a,S b){return (a.x-max(a.y,a.z))<(b.x-max(b.y,b.z));});
				for(int i=1;i<=cnt1-N/2;i++)ans-=(x[i].x-max(x[i].y,x[i].z));
			}
			if(num==2){
				sort(y+1,y+1+cnt2,[](S a,S b){return (a.y-max(a.x,a.z))<(b.y-max(b.x,b.z));});
				for(int i=1;i<=cnt2-N/2;i++)ans-=(y[i].y-max(y[i].x,y[i].z));
			}
			if(num==3){
				sort(z+1,z+1+cnt3,[](S a,S b){return (a.z-max(a.y,a.x))<(b.z-max(b.y,b.x));});
				for(int i=1;i<=cnt3-N/2;i++)ans-=(z[i].z-max(z[i].x,z[i].y));
			}
			printf("%d\n",ans);
		}
	}
}
