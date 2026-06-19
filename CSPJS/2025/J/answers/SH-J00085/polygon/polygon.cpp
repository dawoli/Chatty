#include<bits/stdc++.h>
using namespace std;
int a[5050];
int f(int maxa,int r){
	int c=0;
	if(r==1){
		if(a[1]>maxa){
			return 1;
		}else return 0;
	}
	c=f(maxa,r-1)+f(maxa-a[r],r-1)+(a[r]>maxa);
	return c;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
//	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int count=0;
	for(int i=n;i>=3;i--){
		count+=f(a[i],i-1);
	}
	cout<<count%998244353;
	return 0;
}
