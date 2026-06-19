#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
while(T--){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int c=0,x=-1,y=-1;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					//if(i==5)cout<<x+1<<' '<<j+1<<' '<<endl;
					if(~x)if(a[x+1]==a[j+1])c+=a[x+1];
					x=j;
				}else{
					if(~y)if(a[y+1]==a[j+1])c+=a[y+1];
					y=j;
				}
			}
			ans=max(ans,c);
			//cout<<c<<' '<<i<<endl;
		}cout<<ans<<endl;
	}
	
}
	return 0;
}

