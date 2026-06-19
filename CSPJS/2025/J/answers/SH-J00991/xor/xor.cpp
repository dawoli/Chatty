#include<bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ant=a[i];
			for(int k=i+1;k<=j;k++){
				ant=ant^a[k];
			}
			if(ant==k)cnt++;
		}
	}
	cout<<cnt;
}
