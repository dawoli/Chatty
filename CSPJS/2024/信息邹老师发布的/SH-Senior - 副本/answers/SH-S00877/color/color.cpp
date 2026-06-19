#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;

int a[N];

int main(){
	freopen("color2.in","r",stdin);
	freopen("color.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int k=-1,ans=0;
		for(int i=n;i>=1;i--){
			if(a[i]==k)ans+=a[i];
			else k=a[i];
		}
		cout<<ans<<'\n';
	}
}
