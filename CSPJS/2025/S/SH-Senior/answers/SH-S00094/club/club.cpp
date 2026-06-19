#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ll long long
ll T,n,ans,u,v,w;
struct A{
	ll x,y,z;
}a[N];
bool cmp1(A ax,A ay){
	return ax.x-max(ax.y,ax.z)>ay.x-max(ay.y,ay.z);
}
bool cmp2(A ax,A ay){
	return ax.y-max(ax.x,ax.z)>ay.y-max(ay.x,ay.z);
}
bool cmp3(A ax,A ay){
	return ax.z-max(ax.y,ax.x)>ay.z-max(ay.y,ay.x);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;u=v=w=ans=0;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y&&a[i].x>a[i].z)u++;
			if(a[i].y>a[i].x&&a[i].y>a[i].z)v++;
			if(a[i].z>a[i].x&&a[i].z>a[i].y)w++;
		}
		if(u<=n/2&&v<=n/2&&w<=n/2){
			for(int i=1;i<=n;i++)ans+=max({a[i].x,a[i].y,a[i].z});
		}
		else if(u>n/2){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			for(int i=n/2+1;i<=n;i++)ans+=max(a[i].y,a[i].z); 
		}
		else if(v>n/2){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++)ans+=a[i].y;
			for(int i=n/2+1;i<=n;i++)ans+=max(a[i].x,a[i].z); 
		}
		else if(w>n/2){
			sort(a+1,a+1+n,cmp3);
			for(int i=1;i<=n/2;i++)ans+=a[i].z;
			for(int i=n/2+1;i<=n;i++)ans+=max(a[i].y,a[i].x); 
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
