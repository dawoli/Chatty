#include <iostream>
#include <string>
using namespace std;
int n,m,c[505],cnt0;
string tests;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>tests;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt0+=1;
		}
	}
	for(int i=0;i<n-cnt0;i++){
		ans*=(i+1);
		ans%=998244353;
	}
	if(m>n-cnt0){
		cout<<0;
	}
	else{
		cout<<ans;
	}
	return 0;
}
