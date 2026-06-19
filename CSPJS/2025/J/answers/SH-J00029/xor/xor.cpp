#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
long long int n,k,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[n+1]=-1;
		if(a[i]==k && a[i]!=-1){
			cnt++;
			a[i]=-1;
		}
		else if(a[i]^a[i+1]==k && a[i]!=-1 && a[i+1]!=-1){
			cnt++;
			a[i]=-1;
			a[i+1]=-1;
		}
	}
	cout<<cnt;
	return 0;
}
