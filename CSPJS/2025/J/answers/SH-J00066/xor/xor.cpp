#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>;
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[10000],swithch=1;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)swithch=0;
	}
	if(swithch && !k){
		cout<<n/2;
		return 0;
	}
	return 0;
}
