#include<bits/stdc++.h>
using namespace std;
int t,n,a[200003];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=2;i<=n;i++){
			if(a[i-1]==a[i]){
				ans+=a[i];
			}else if(a[i-2]==a[i]){
				if(a[i+1]>a[i]&&a[i+1]==a[i-3]) ans+=a[i+1];
				else ans+=a[i];
			}else if(a[i-3]==a[i]){
				if(a[i-4]==a[i-2]&&a[i-1]==a[i+1]){
					ans+=a[i];
				}else if(a[i-2]==a[i-1]){
					ans+=a[i];
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}

