#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009][4];
int cnt[20010];
int x[100009][2],y[100009][2],z[100009][2];
int choose(int now,int ans,int x,int y,int z){
	if(x>n/2) return 0;
	if(y>n/2) return 0;
	if(z>n/2) return 0;
	if(now>n) return ans;
	ans=max(max(choose(now+1,ans+a[now][0],x+1,y,z),choose(now+1,ans+a[now][1],x,y+1,z)),choose(now+1,ans+a[now][2],x,y,z+1));
	return ans;
}
void solveBF(){
	int ans=choose(1,0,0,0,0);
	cout<<ans<<endl;
	return;
}
void solve1(){
	int sum=0;
	int x1=0,y1=0,z1=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]){
			if(a[i][1]>=a[i][2]){
				x[x1][0]=a[i][0];
				x[x1++][1]=i;
				a[i][3]=a[i][0]-a[i][1];
				sum+=a[i][0];
			}else{
				if(a[i][0]>=a[i][2]){
					x[x1][0]=a[i][0];
					x[x1++][1]=i;
					a[i][3]=a[i][0]-a[i][2];
					sum+=a[i][0];
				}else{
					z[z1][0]=a[i][2];
					z[z1++][1]=i;
					a[i][3]=a[i][2]-a[i][0];
					sum+=a[i][2];
				}
			}
		}else{
			if(a[i][1]<=a[i][2]){
				z[z1][0]=a[i][2];
				z[z1++][1]=i;
				a[i][3]=a[i][2]-a[i][1];
				sum+=a[i][2];
			}else{
				if(a[i][0]>=a[i][2]){
					y[y1][0]=a[i][1];
					y[y1++][1]=i;
					a[i][3]=a[i][1]-a[i][0];
					sum+=a[i][1];
				}else{
					y[y1][0]=a[i][1];
					y[y1++][1]=i;
					a[i][3]=a[i][1]-a[i][2];
					sum+=a[i][1];					
				}
			}
		}
	}
	for(int i=0;i<=20009;i++){
		cnt[i]=-1;
	}
	if(x1>n/2){
		int duo=x1-n/2;
		for(int i=0;i<x1;i++){
			cnt[a[x[i][1]][3]]++;
			if(cnt[a[x[i][1]][3]]==0) cnt[a[x[i][1]][3]]++;
		}
		for(int i=0;i<=20009;i++){
			if(cnt[i]>-1){
				if(cnt[i]>=duo){
					sum-=duo*i;
					break;
				}else{
					sum-=cnt[i]*i;
					duo-=cnt[i];
				}
			}
		}
	}else if(y1>n/2){
		int duo=y1-n/2;
		for(int i=0;i<y1;i++){
			cnt[a[y[i][1]][3]]++;
			if(cnt[a[y[i][1]][3]]==0) cnt[a[y[i][1]][3]]++;
		}
		for(int i=0;i<=20009;i++){
			if(cnt[i]>-1){
				if(cnt[i]>=duo){
					sum-=duo*i;
					break;
				}else{
					sum-=cnt[i]*i;
					duo-=cnt[i];
				}
			}
		}		
	}else if(z1>n/2){
		int duo=z1-n/2;
		for(int i=0;i<z1;i++){
			cnt[a[z[i][1]][3]]++;
			if(cnt[a[z[i][1]][3]]==0) cnt[a[z[i][1]][3]]++;
		}
		for(int i=0;i<=20009;i++){
			if(cnt[i]>-1){
				if(cnt[i]>=duo){
					sum-=duo*i;
					break;
				}else{
					sum-=cnt[i]*i;
					duo-=cnt[i];
				}
			}
		}		
	}
	cout<<sum<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		solve1();
	}
	return 0;
} 
