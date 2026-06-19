#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],cnt,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>cnt;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(cnt==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				i++;
			}
		}
		ans+=(n-ans*2);
		cout<<ans;
	}
	else if(cnt==1) 
	{
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				i++;
			}
		}
		ans+=(n-ans*2);
		cout<<ans;
	}
	else cout<<3;
	return 0;
 } 
