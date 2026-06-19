#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","I",stdin);
	//freopen("number.out","w",stdout);
	int n,a;
	cin>>n;
	if(n<=10)cout<<n;
	else{
		a=n%10;
		n=(n-a)/10;
		cout<<max(a,n)<<min(a,n);
	}
}
