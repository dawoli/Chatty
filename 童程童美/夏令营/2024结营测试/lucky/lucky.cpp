#include<iostream>
using namespace std;
long long n,cnt;
bool lucky(long long a)
{
	while(a)
	{
		if(a%10!=4||a%10!=7){return 0;}
		a/=10;
	}
	return 1;
}
int main()
{
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	cin>>n;
	for(long long i=4; ;i++)
	{
		if(lucky(i)){cnt++;}
		if(cnt==n){cout<<i;break;}
	}
	return 0;
} 
