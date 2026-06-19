#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool d[100010];
	int a[100010];
	int c[100010];
	int n,k,cnt=0;
	string b;
	cin>>n;
	cin>>k;
	cin>>b;
	for(int i=0;i<n;i++){
		a[i+1]=b[i]-'0';
		cin>>c[i+1];
		cnt+=a[i+1];
	}
	if(cnt==n){
		cout<<0;
	}
	return 0;
} 
