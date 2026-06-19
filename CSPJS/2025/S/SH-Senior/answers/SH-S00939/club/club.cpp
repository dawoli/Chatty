#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],maxmanyi=-1;
bool vis[100005][5];
bool ff=0;
int pone,ptwo,pthree;
int tong[20005],cnttt;
//void dfs(int step,int manyidu){
//	if(step==n){
//		if(manyidu>maxmanyi)maxmanyi=manyidu;
//		return ;
//	}
//	for(int i=1;i<=3;i++){
//		if(vis[step][i]!=0&&pone<n/2){
//			dfs(step+1,manyidu+a[step][1]);
//		}
//		else 
//	}
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnttt=0;
		ff=0;
		maxmanyi=-1;
		memset(a,0,sizeof(a));
		memset(tong,0,sizeof(tong));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)ff=1;
		}
		if(n==2){
			int maxnnn=0;
			if(a[1][1]+a[2][2]>maxnnn)maxnnn=a[1][1]+a[2][2];
			if(a[1][1]+a[2][3]>maxnnn)maxnnn=a[1][1]+a[2][3];
			if(a[1][2]+a[2][1]>maxnnn)maxnnn=a[1][2]+a[2][1];
			if(a[1][2]+a[2][3]>maxnnn)maxnnn=a[1][2]+a[2][3];
			if(a[1][3]+a[2][1]>maxnnn)maxnnn=a[1][3]+a[2][1];
			if(a[1][3]+a[2][2]>maxnnn)maxnnn=a[1][3]+a[2][2];
			cout<<maxnnn<<endl;
		}
		if(ff==0){
			for(int i=1;i<=n;i++){
				tong[a[i][1]]++;
			}
			int yifang=0;
			for(int i=20000;i>0;i--){
				if(tong[i]!=0){
					if(yifang+tong[i]<=n/2){
						yifang=yifang+tong[i];
						cnttt+=tong[i]*i;
//						cout<<cnttt<<"*"<<i<<endl;
					}
					if(yifang+tong[i]>n/2){
//						cout<<yifang<<' '<<i<<' '<<cnttt<<' '<<tong[i]<<"(("<<endl;
						cnttt=cnttt+i*(n/2-yifang);
						cout<<cnttt<<endl;
						break;
					}
				}
			}
		}
//		dfs()
	}
	return 0;
} 
