#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int x=0;
	int a[5000];
	long long int ways=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x=x+a[i];
	}
	int max=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>max){
			a[i]=max;
		}
	}
	if(x>2*max){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
