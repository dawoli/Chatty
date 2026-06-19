#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n,ans=0;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		if(a[i]!=n&&a[i+1]!=n){
			a[i+1]=(a[i]^a[i+1]);
		}
		else if(a[i]==n) ans++;
		else continue;
	}
	cout<<ans;
	return 0; 
}
