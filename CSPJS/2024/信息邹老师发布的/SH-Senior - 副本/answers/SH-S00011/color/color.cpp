#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define F false
#define T true
#define ll long long
ll num[200010]={0},m,ans=-2147483648;
bool color[200010]={false};
ll score(){
	ll ret=0;
	for(ll i=0;i<m;++i){
		for(int j=i-1;j>-1;--j){
			if(color[i]==color[j]&&num[i]==num[j]){ret+=num[i];break;}
			if(color[i]==color[j]&&num[i]!=num[j]) break;
		}
	}
	return ret;
}
void calc(ll steps=1){
	if(steps==m){
		ll sc=score();
		ans=ans<sc?sc:ans;
		return;
	}
	color[steps]=true;
	calc(steps+1);
	color[steps]=false;
	calc(steps+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll n;
	cin>>n;
	while(n--){
		ans=-2147483648;
		cin>>m;
		for(ll i=0;i<m;++i) cin>>num[i];
		calc();
		cout<<ans<<endl;
	}
	return 0;
}//水到20分就行，后面的算了吧 
