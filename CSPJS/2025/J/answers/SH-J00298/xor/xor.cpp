#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=0;
ll k,a[500005],s[500005];
ll q(int x,int y){
	return s[y]^s[x-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=l;j<=i;j++){
			if(q(j,i)==k){
				l=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
