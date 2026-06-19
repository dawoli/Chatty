#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,k;
int num[4]={0,1,1,0};
signed main()
{
	cin>>n>>k;
	for(int i = n-1; i > 0; i--){
		cout << num[(k/((int)(1)<<i))%4];
	}
	cout<<num[k%4];
	return 0;
}
