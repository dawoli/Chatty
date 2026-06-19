#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],c[200005],ans,num,lr,lb;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=num=lb=lr=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=(1<<n)-1;i++){
			num=0;lb=0;lr=0;
			int tmp=i;
			for(int j=1;j<=n;j++){
				c[j]=tmp%2;
				tmp>>=1;
				if(c[j]==0){
					if(a[j]==a[lr])num+=a[j];
					lr=j;
				}
				if(c[j]==1){
					if(a[j]==a[lb])num+=a[j];
					lb=j;
				}
			}
			ans=max(ans,num);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
