#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a[100001][4]={0};
		int n;
		int zz[4]={0};
		scanf("%d",&n);
		int aa[100001]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]==0){
					zz[j]++;
				}
				if(j==1)aa[i]=a[i][j];			
			}
		}
		if(n==2){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j)continue;
					int total=a[1][i]+a[2][j];
					if(total>ans)ans=total;
				}
			}
			cout<<ans<<endl;
		}else if(n==4){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							int z[4]={0};
							z[i]++;z[j]++;z[k]++;z[l]++;
							if(z[1]>2||z[2]>2||z[3]>2)continue;
							int total=a[1][i]+a[2][j]+a[3][k]+a[4][l];
							if(total>ans)ans=total;
						}
					}
				}
			}
			cout<<ans<<endl;
		}else if(zz[2]==n&&zz[3]==n){
			int ans=0;
			sort(aa,aa+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=aa[i];
			}
			cout<<ans<<endl;
		}else if(zz[3]==n&&zz[2]!=n){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=aa[i];
				aa[i]=a[i][2]-aa[i];
			}
			sort(aa+1,aa+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans=ans+aa[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
