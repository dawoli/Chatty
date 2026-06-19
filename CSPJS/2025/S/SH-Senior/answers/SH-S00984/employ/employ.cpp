#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	sum=n;
	n--;
	for(;n>0;n--){
		sum=sum*n;
		sum=sum%998244353;
	}
	cout<<sum<<endl;
	return 0;
}
