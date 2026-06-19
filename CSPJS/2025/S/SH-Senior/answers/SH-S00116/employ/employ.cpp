#include<bits/stdc++.h>
using namespace std;
const int N=509;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
