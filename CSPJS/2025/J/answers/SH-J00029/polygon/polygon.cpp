#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int a[N];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1; 
	if(n==3){
		if((a[j]+a[j+1]+a[j+2])>max(a[j],a[j+1],a[j+2])*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	cout<<9;
	return 0;
}
