#include<bits/stdc++.h>
using namespace std;
int ans,cnt,cnt2;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=6;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int peter=max(a[0],a[1],a[2]);
		for(int m=3;m<=a[n];m++){
			if((a[0]+a[m])*(m+1)/2>2*peter){
				ans+=9;
				cout<<ans<<endl;
				break;
			}
			int qiangshuzheng=max(a[0],a[1],a[2]);
			int dingwenbo=max(a[3],a[4]);
			int gaoshixin=max(qiangshuzheng,dingwenbo);
			for(int z=3;z<=a[n];z++){
				if((a[0]+a[n])*(z+1)/2>2*gaoshixin){
				}
			}
		}
	}
	return 0;
}
