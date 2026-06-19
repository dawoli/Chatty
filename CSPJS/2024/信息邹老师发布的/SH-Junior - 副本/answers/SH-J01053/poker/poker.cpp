#include <bits/stdc++.h>
using namespace std;
int n,ans=0,pd=0;
string a[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]==a[j])
			    pd=1;
		}
		if(pd==0)
		    ans++;
		pd=0;
	}
	ans=52-ans;
	cout<<ans;
	return 0;
} 
