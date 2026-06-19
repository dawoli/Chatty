#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int ni;cin>>ni;for(int i=0;i<ni;i++){
		int n;cin>>n;long long f[n+1]={0},w[10]={6,2,5,5,4,5,6,3,7,6};
		for(long long j=1;j<10;j++){f[w[j]]=f[w[j]]>0?min(f[w[j]],j):j;
			for(int k=w[j];k<=n;k++){
				if(f[k-w[j]]>0){
					f[k]=f[k]>0?min(f[k],f[k-w[j]]*10+j):f[k-w[j]]*10+j;
					if(j==6)f[k]-=6;
					if(j==6&&k==10)f[k]=22;
					if(j==6&&k==15)f[k]=222;
				}
			}
			for(int k=0;k<=n;k++)cout<<f[k]<<" ";cout<<endl;
		}
		if(f[n]==0)f[n]--;
		cout<<f[n];if(i<ni-1)cout<<"\n";
	}
	return 0;
}
