#include<bits/stdc++.h>
using namespace std;
const int mm=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long p=1;
	int n;
	cin>>n;
	int cnt=n,now=n;
	while(cnt){
		cnt--;
		if(p>mm)p%=mm;
		p*=now;now--;
	}
	cout<<p;
	return 0;
}
