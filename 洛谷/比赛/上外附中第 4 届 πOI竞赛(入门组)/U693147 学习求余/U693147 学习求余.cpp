#include<iostream>
using namespace std;
typedef long long ll;
ll n,k,q;
int main()
{
	cin>>n;
	k=n/2+1;
	q=n%k;
	cout<<max(k*q,n-1);
	return 0;
} 