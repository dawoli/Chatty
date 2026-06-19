#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		int maxx=0,m=0,sum=0;
		for(int j=i;j<n;j++){
			if(a[j]>maxx)
				maxx=a[j];
			sum+=a[j];
			m++;
			if(m>=3 && sum>2*maxx)
				cnt++;
		}
	}
	cout<<cnt%998244353; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
