#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],ans=0;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<(1<<n);i++){
			int pb=0,pr=0;
			int res=0,tmp=i;
			for(int j=1;j<=n;j++){
				if(tmp%2==1){
					if(a[j]==a[pr])res+=a[j];
					//cout<<"R"<<i<<" "<<pr<<","<<j<<endl;
					pr=j;
				}else{
					if(a[j]==a[pb])res+=a[j];
					//cout<<"B"<<i<<" "<<pb<<","<<j<<endl;
					pb=j;
				}tmp/=2;
			}//cout<<res<<endl<<endl;
			if(res>ans)ans=res;
		}cout<<ans<<'\n';
	}
	return 0;
}
