#include<bits/stdc++.h>
using namespace std;
long long int a[1000010],b[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]^m)==0){
			cnt++;
			b[a[i]]=-1;
		}
		else{
			b[a[i]]=(a[i]^m);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]!=m && b[a[j]]!=m && i!=j){
				if(a[i]==b[a[j]]){
					b[a[i]]=-1;
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
