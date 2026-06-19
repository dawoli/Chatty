#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
const int N=1e5+5;
int t;
int n;
int a[N][3];
int x[N],y[N],z[N];
bool vis[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		int px=0,py=0,pz=0;
		int mx=0,my=0,mz=0;
		int sx=0,sy=0,sz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x[i]=a[i][1];
			y[i]=a[i][2];
			z[i]=a[i][3];
			
		
			if(x[i]>=max(y[i],z[i])){
				px++;
				mx+=x[i];
				if(y[i]==x[i]&&y[i]==z[i]){
					sy+=y[i];
				}
				else if(y[i]>=z[i]){
					sy+=y[i];
				}
				else{
					sz+=z[i];
				}
			}
			if(y[i]>=z[i]&&y[i]>x[i]){
				py++;
				my+=y[i];
				if(x[i]==y[i]&&x[i]==z[i]){
					sx+=x[i];
				}
				else if(x[i]>z[i]){
					sx+=x[i];
				}
				else{
					sz+=z[i];
				}
			}
			if(z[i]>max(x[i],y[i])){
				pz++;
				mz+=z[i];
				if(z[i]==x[i]&&y[i]==z[i]){
					sx+=x[i];
				}
				else if(x[i]>=y[i]){
					sx+=x[i];
				}
				else{
					sy+=y[i];
				}
			}
		}
		int sum=0,sumx=0,sumy=0,sumz=0;
		if(px<=n/2&&py<=n/2&&pz<=n/2){
			sum=mx+my+mz;
			cout<<sum<<endl;
			continue;
		}
		if(px>n/2&&py==0&&pz==0&&sy==0&&sz==0){
			mx=0;
			for(int i=1;i<=px;i++){
				sort(x+1,x+px+1);
			}
			for(int i=px;i>px-n/2;i--){
				mx+=x[i]; 
			}
			sum=mx;
			cout<<sum<<endl;
			continue;
		}
		if(py>n/2&&px==0&&pz==0&&sx==0&&sz==0){
			my=0;
			for(int i=1;i<=py;i++){
				sort(y+1,y+py+1);
			}
			for(int i=py;i>py-n/2;i--){
				my+=y[i]; 
			}
			sum=my;
			cout<<sum<<endl;
			continue;
		}
		if(pz>n/2&&py==0&&px==0&&sy==0&&sx==0){
			mz=0;
			for(int i=1;i<=pz;i++){
				sort(z+1,z+pz+1);
			}
			for(int i=pz;i>pz-n/2;i--){
				mz+=z[i]; 
			}
			sum=mz;
			cout<<sum<<endl;
			continue;
		}
		if(n==2&&px>n/2&&(sy!=0||sz!=0)){
			int ss1=0,ss2=0,ss3=0,ss4=0,ss5=0;
			int sss1,sss2;
			ss1=x[1]+max(y[2],z[2]);
			ss2=x[2]+max(y[1],z[1]);
			sum=max(ss1,ss2);
			cout<<sum<<endl;
			continue;
		}
		if(n==2&&py>n/2&&(sx!=0||sz!=0)){
			int ss1=0,ss2=0,ss3=0,ss4=0,ss5=0;
			int sss1,sss2;
			ss1=y[1]+max(x[2],z[2]);
			ss2=y[2]+max(x[1],z[1]);
			sum=max(ss1,ss2);
			cout<<sum<<endl;
			continue;
		}
		if(n==2&&pz>n/2&&(sx!=0||sy!=0)){
			int ss1=0,ss2=0,ss3=0,ss4=0,ss5=0;
			int sss1,sss2;
			ss1=z[1]+max(y[2],x[2]);
			ss2=z[2]+max(y[1],y[1]);
			sum=max(ss1,ss2);
			cout<<sum<<endl;
			continue;
		}
	}
	return 0;
}
