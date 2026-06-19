#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a,b,cnt=0,ans=0;
	cin>>a>>b;
	if(b==k)cnt++;
	if(a==k)cnt++;
	if(a^b==k)ans++;
	cout<<max(cnt,ans);
	return 0;
}
