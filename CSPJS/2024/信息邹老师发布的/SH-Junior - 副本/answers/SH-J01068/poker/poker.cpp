#include<bits/stdc++.h>
using namespace std;
int n;
string a[100];
int ans=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++) if(a[i]==a[j]) ans++;
	}
	cout<<52-n+ans;
	return 0;
} 

