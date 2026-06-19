#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int T,a[N],ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		ans=0;
		int n;
		cin>>n;
		fill(a,a+n,0);
		for(int j=1;j<=n;j++) cin>>a[j];
		sort(a+1,a+1+n);
		for(int j=2;j<=n;j++)
		    if(a[j]==a[j-1])
		        ans+=a[j];
		cout<<ans<<endl;
	}
	return 0;
} 
