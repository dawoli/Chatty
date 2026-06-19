#include<bits/stdc++.h>
using namespace std;
int a[100001][5],zy[100001];
struct o{
	int cha,bh;
}c[100001];
bool cmp(o x,o y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int ans=0,c1=0,c2=0,c3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				zy[i]=a[i][1],c[i].bh=1,c1++;
				if(a[i][2]>a[i][3])c[i].cha=a[i][1]-a[i][2];
				else c[i].cha=a[i][1]-a[i][3];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				zy[i]=a[i][2],c[i].bh=2,c2++;
				if(a[i][1]>a[i][3])c[i].cha=a[i][2]-a[i][1];
				else c[i].cha=a[i][2]-a[i][3];
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				zy[i]=a[i][3],c[i].bh=3,c3++;
				if(a[i][1]>a[i][2])c[i].cha=a[i][3]-a[i][1];
				else c[i].cha=a[i][3]-a[i][2];
			}
		}
		if(c1>n/2){
			sort(c+1,c+n+1,cmp);
			int tc=c1-n/2;
			for(int i=1;i<=n;i++){
				if(tc==0)break;
				if(c[i].bh==1)ans-=c[i].cha,tc--;
			}
		}
		else if(c2>n/2){
			sort(c+1,c+n+1,cmp);
			int tc=c2-n/2;
			for(int i=1;i<=n;i++){
				if(tc==0)break;
				if(c[i].bh==2)ans-=c[i].cha,tc--;
			}
		}
		else if(c3>n/2){
			sort(c+1,c+n+1,cmp);
			int tc=c3-n/2;
			for(int i=1;i<=n;i++){
				if(tc==0)break;
				if(c[i].bh==3)ans-=c[i].cha,tc--;
			}
		}
		for(int i=1;i<=n;i++)ans+=zy[i];
		cout<<ans<<endl;
	}
}
