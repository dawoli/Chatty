#include<bits/stdc++.h>
using namespace std;
int t,n,ans,cnt1,cnt2,cnt3,ma1,ma2,ma3,vist[4];
struct node{
	int x,y,z;
}a[100005];
bool cmp(node m,node k){
	return m.x>k.x;
}
void f(int bo,int depp,int u){
	if(bo==1)u+=a[depp].x;
	if(bo==2)u+=a[depp].y;
	if(bo==3)u+=a[depp].z;
	vist[bo]++;
	if(depp==n){
		ans=max(ans,u);
		return;
	}
	if(vist[1]+1<=n/2)f(1,depp+1,u);
	if(vist[2]+1<=n/2)f(2,depp+1,u);
	if(vist[3]+1<=n/2)f(3,depp+1,u);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0,cnt2=0,cnt3=0,ans=INT_MAX;
		ma1=0,ma2=0,ma3=0;
		ans=0;
		memset(vist,0,sizeof(vist));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y==0)cnt2++;
			if(a[i].z==0)cnt3++;
			if(a[i].x==max(a[i].x,max(a[i].y,a[i].z)))ma1++;
			if(a[i].y==max(a[i].x,max(a[i].y,a[i].z)))ma2++;
			if(a[i].z==max(a[i].x,max(a[i].y,a[i].z)))ma3++;
		}
		if(cnt2==n&&cnt3==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
		}
		else if(ma1<=n/2&&ma2<=n/2&&ma3<=n/2){
			for(int i=1;i<=n;i++)ans+=max(a[i].x,max(a[i].y,a[i].z));
			cout<<ans<<endl;
		}
		else{
			f(1,1,0);
			memset(vist,0,sizeof(vist));
			f(2,1,0);
			memset(vist,0,sizeof(vist));
			f(3,1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
