#include<bits/stdc++.h>
using namespace std;
int w[4][100005],f[100005],kk[100005],ki[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w[1][i]>>w[2][i]>>w[3][i];
		}
		int sum=0;
		for(int j=1;j<=n;j++){
			f[j]=0;
		}
		for(int ii=1;ii<=3;ii++){
			int maxn=-1,j=0;
			for(int k=1;k<=n;k++){
				kk[k]=w[i][k];
			}
			sort(kk+1,kk+1+n);
			maxn=kk[n-1];
			for(int k=1;k<=n;k++){
				if(j==n/2){
					break;
				}
				if(f[k]){
					continue;
				}
				if(w[ii][k]>=maxn){
					int ff=1;
					for(int e=1;e<=3;e++){
						if(w[e][k]>w[ii][k]){
							ff=0;
							break;
						}
					}
					if(ff==0||f[k]){
						continue;
					}	
					if(ff&&(!f[k])){
						f[k]=1;
						maxn=w[ii][k];
						sum+=w[ii][k];
						j++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
