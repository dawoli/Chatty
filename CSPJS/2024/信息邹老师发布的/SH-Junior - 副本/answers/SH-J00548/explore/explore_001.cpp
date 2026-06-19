#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int n[t],m[t],k[t],ans[t]={0},cnt=0;
	int xstart[t],ystart[t],dstart[t];
	for(int i=0;i<t;i++){
		cin>>n[i]>>m[i]>>k[i]>>xstart[i]>>ystart[i]>>dstart[i];
		xstart[i]--;
		ystart[i]--;
		char c[n[i]][m[i]];
		for(int a=0;a<n[i];a++){
		for(int j=0;j<m[i];j++){
			cin>>c[a][j];
		}
		while(cnt<=k[i]){
			if(dstart[i]==0){
					if(ystart[i]+1>=0&&ystart[i]<m[i]-1&&c[i][i+1]=='.'){
				ystart[i]++;
				ans[i]++;
			}
			else dstart[i]=(dstart[i]+1)%4;
			cnt++;
		}
			if(dstart[i]==1){
					if(xstart[i]+1>=0&&xstart[i]<n[i]-1&&c[i+1][i]=='.'){
						xstart[i]++;
						ans[i]++;
					}
					else dstart[i]=(dstart[i]+1)%4;
					cnt++;
			}
			if(dstart[i]==2){
				if(ystart[i]-1>=0&&ystart[i]<m[i]&&c[i][i-1]=='.'){
					ystart[i]--;
					ans[i]++;
				}
				else dstart[i]=(dstart[i]+1)%4;
				cnt++;
			}
			if(dstart[i]==3){
				if(xstart[i]-1>=0&&xstart[i]<n[i]&&c[i-1][i]=='.'){
					xstart[i]--;
					ans[i]++;
				}
				else dstart[i]=(dstart[i]+1)%4;
				cnt++;
			}
		}
		cnt=0;
	}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
