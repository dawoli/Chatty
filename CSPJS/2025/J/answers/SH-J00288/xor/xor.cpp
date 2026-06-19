#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],t,cnt=0;
signed main(){
	//#Shang4Shan3Ruo6Shui4
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>t;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(t==k){
			cnt++;
			t=a[i];
		}else{
			t=t^a[i];
		}
	}
	if(t==k) cnt++;
	cout<<cnt;
	return 0;
}
