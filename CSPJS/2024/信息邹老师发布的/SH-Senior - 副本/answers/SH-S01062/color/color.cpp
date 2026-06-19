#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N],T,n,r,b,ans,cnt;
void solve15(){
	ans=0;
	for (int i=0;i<(1<<n);i++){
		cnt=0,r=0,b=0;
		for (int j=0;j<n;j++){
			if ((i>>j)&1){
				if (a[j]==r) cnt+=r;
				r=a[j];
			}
			else{
				if (a[j]==b) cnt+=b;
				b=a[j];
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for (int br=1;br<=T;br++){
		cin>>n;
		for (int i=0;i<n;i++) cin>>a[i];
		if (n<=15) solve15();
		else cout<<n<<endl; 
	}
	return 0;
} 
