#include<bits/stdc++.h>
using namespace std;
string a[59]; 
int n;
int ans=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) ans++;
	}
	cout<<52-ans;
	return 0;
}
