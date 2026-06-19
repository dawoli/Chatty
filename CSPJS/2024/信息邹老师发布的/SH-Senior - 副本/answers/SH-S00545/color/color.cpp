#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[1000005];
int main(){
	freeopen("color.in","r",stdin);
	freeopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a[x]++;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=sum+a[i]/2*i;
		}
		cout<<sum<<endl;
	}
	return 0;
}
