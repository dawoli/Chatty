#include<bits/stdc++.h>
using namespace std;
int a[500009],b[500009],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int lastk=0;
	for(int i=1;i<=n;i++){
		for(int j=lastk;j<i;j++){
			if((int)(b[i]^b[j])==k){
				ans++;
				lastk=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
