#include<iostream>
using namespace std;
long long n,k,ans;
long long num[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>num[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(num[i]==0)ans++;
			else if(num[i]==num[i+1]){
				ans++;
				i++;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(num[i]^num[i+1]==1){
				ans++;
				i++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			
		}
	}
	cout<<ans;
	return 0;
}
