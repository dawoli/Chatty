#include<bits/stdc++.h>
using namespace std;
int a[20],c[20];
char h[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]] or h[i]=='0'){
				cnt++;
			}
		}
		if(n-cnt>=m) ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
}
