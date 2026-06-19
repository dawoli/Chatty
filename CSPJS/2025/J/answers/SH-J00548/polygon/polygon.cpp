#include<bits/stdc++.h>
using namespace std;
long long mul(int n){
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	return sum;
}
long long gets(int all,int get_it){
	long long all_mul=mul(all);
	long long get_it_mul=mul(get_it);
	long long num=all_mul/get_it_mul;
	return num;
}
int main() {
//	freopen("polygon4.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	long long a[n+1];
	for(int i=3;i<=n;i++){
		sum+=gets(n,i);
	}
	cout<<sum;
	return 0;
}
