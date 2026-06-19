#include<bits/stdc++.h>
using namespace std;
long long n,m,mod=998244353,ans,na,x,a[100100],q,w;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	na=n;
	for(int i=1;i<=na;i++){
		cin>>x;
		if(x==0){
			n--;
		}
	}
	if(m>n/2){
		m=n-m;
	}
	ans=1;
	q=0,w=1;
	for(int i=n;i>=n-m+1;i--){
		ans*=i;
		q++;
		a[q]=n/i+1;
		if(ans%a[w]==0){
			ans/=a[w];
			w++;
		}
		ans%=mod;
	}
	for(int i=w;i<=q;i++){
		ans/=a[i];
	}
	cout<<ans;
}
