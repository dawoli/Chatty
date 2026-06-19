#include <bits/stdc++.h>
using namespace std;
struct cars{
	int d,vv,va;
}car[100005];
int m1[100005];
bool pm[100005];
int n,m,l,v,cnt=0,k;
int fch(){
	cnt=0;
	for(int i=1;i<=n;i++){
			if(car[i].vv<=v&&car[i].va<=0) continue;
			else if(car[i].vv>v&&car[i].va>=0){
				if(car[i].va!=0){
					double ts=1.0*(v*v-car[i].vv*car[i].vv)/(2*car[i].va);
					for(int j=1;j<=m;j++){
						if(m1[j]>=car[i].d&&m1[j]<car[i].d+ts&&pm[j]==0){
							cnt++;
//							cout<<i<<" ";
							break;
							}
						}
					}
				else{
					for(int j=1;j<=m;j++){
						if(m1[j]>=car[i].d&&pm[j]==0){
							cnt++;
//							cout<<i<<" ";
							break;
							}
						}
					}
			}
			else if(car[i].vv<=v&&car[i].va>0){
				double time=1.0*(v-car[i].vv+0.01)/car[i].va;
				double ts=1.0*car[i].vv*time+0.5*car[i].va*time*time;
				for(int j=1;j<=m;j++){
					if(m1[j]>=car[i].d+ts&&sqrt(car[i].vv*car[i].vv+2.0*car[i].va*ts)>v&&pm[j]==0){
						cnt++;
//						cout<<i<<" ";
						break;
					}
				}
			}
			else{
				if(car[i].va!=0){
					double ts=1.0*(v*v-car[i].vv*car[i].vv)/(2*car[i].va);
					ts+=car[i].d;
					for(int j=1;j<=m;j++){
						if(m1[j]>=car[i].d&&m1[j]<ts&&pm[j]==0){
							cnt++;
//							cout<<i<<" ";
							break;
						}
					}
				}
				else {
					for(int j=1;j<=m;j++){
						if(m1[j]>=car[i].d&&pm[j]==0){
							cnt++;
//							cout<<i<<" ";
							break;
						}
					}
				}
				
			}
		}
	return cnt;
}
int fcl(int num,int i){
	if(i==m+1){
		if(fch()==k) return num;
		else return -1;
	} 
	pm[i]=1;
	int a=fcl(num+1,i+1);
	pm[i]=0;
	int b=fcl(num,i+1);
	return max(a,b);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>v;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].vv>>car[i].va;
			if(car[i].va==0) sum++;
		}
		for(int i=1;i<=m;i++) cin>>m1[i];
		int k=fch();
		if(sum==n) cout<<k<<" "<<k<<endl;
		else cout<<fcl(0,1)<<endl;
		for(int i=1;i<=m;i++) pm[i]=0;
	}
	return 0; 
} 
