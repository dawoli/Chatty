#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010],ans;
bool rb[200010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<(1<<n);i++){
			int t=i,l=0,sum=0;
			while(t){
				rb[++l]=t%2;
				t/=2;
			}
			for(int i=1;i<=n;i++){
	//			cout<<rb[i];
				for(int j=i-1;j>=1;j--){
					if(rb[j]==rb[i]){
						if(a[i]==a[j]){
						//	cout<<"fafwwfafaw";
							sum+=a[i];
						}
					}
				}
			}
			
			ans=max(ans,sum);
		//	cout<<'\n';
		}
		cout<<ans<<'\n';
		ans=0;
	}

	return 0;
}
//Z*L#LH%9

