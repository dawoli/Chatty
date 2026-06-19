#include<bits/stdc++.h>
using namespace std;
const int N=200007;
int a[N];
bool c[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		c[i]=0;
		cin>>a[i];
	}
	int last=0,lasti=0,ans=0,lastc=0;;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				if(i>=last){
					c[i]=1;
					c[j]=1;
					ans+=a[i];
					lasti=i;
					last=j;//最后一个涂过色 
				}
				else if(i<last)
					if(a[i]>a[last]){
						c[i]=1;
						c[j]=1;
						c[lasti]=0;
						c[last]=0;
						ans=ans-a[last]+a[i];
						last=j;
					}
			}
		}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			if(a[i]==lastc)
				ans+=a[i];
			lastc=a[i];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
		solve();
	return 0;
}
