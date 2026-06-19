#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	int n,m,ans=1,k=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==0)k++;
	}
	for(int i=n;i>n-m;i--)ans*=i;
	if(k>n-m)ans=0;
	cout<<ans;
	return 0;
} 
