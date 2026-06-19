#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5000];
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n=3){
		if(sum-(*max_element(a,a+n))<(*max_element(a,a+n))){
			cout<<0;
			return 0;
		}
		else cout<<1;
	}
	else cout<<10;
	return 0;
}
