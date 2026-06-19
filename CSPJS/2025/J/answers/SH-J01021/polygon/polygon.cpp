#include <bits/stdc++.h>
using namespace std;
int n,a[10005];
/*===================*/
bool isp(int i,int j,int k){
	int sum=a[i]+a[j]+a[k];
	int ave=max(max(a[i],a[j]),a[k]);
	if(sum>ave*2)return true;
	return false;
} 
bool ispa(int i,int j,int k,int u){
	int sum=a[i]+a[j]+a[k]+a[u];
	int ave=max(max(a[i],a[j]),max(a[k],a[u]));
	if(sum>ave*2)return true;
	return false;
} 
bool ispb(int i,int j,int k,int u,int y){
	int sum=a[i]+a[j]+a[k]+a[u]+a[y];
	int ave=max(max(a[i],a[j]),max(max(a[k],a[u]),a[y]));
	if(sum>ave*2)return true;
	return false;
} 
/*===================*/
int lx(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(i==j||j==k)continue;
				if(isp(i,j,k))sum++;	
			} 
		}
	}
	return sum;
}
/*===================*/
int lxq(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				for(int u=k;u<=n;u++){
					if(i==j||j==k||k==u)continue;
					if(ispa(i,j,k,u))sum++;
				}
					
			} 
		}
	}
	return sum;
}
/*==================*/
int lxf(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				for(int u=k;u<=n;u++){
					for(int y=u;y<=n;y++){
						if(i==j||j==k||k==u||u==y)continue;
						if(ispb(i,j,k,u,y))sum++;
					}
					
				}
					
			} 
		}
	}
	return sum;
}
/*===================*/
void Solve(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	ans+=lx();
	ans+=lxq();
	ans+=lxf();
	cout<<ans;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solve();
	return 0;
}
