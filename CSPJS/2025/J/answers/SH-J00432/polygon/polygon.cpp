#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int max1=-1;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>max1){
			max1=a[i];
		}
	}
	if(n==3){
		if(sum>max1*2){
			cout<<"1";
		}
		else cout<<"0";
	}
	return 0; 
}
