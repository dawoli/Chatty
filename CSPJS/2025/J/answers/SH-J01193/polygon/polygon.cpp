#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a1a[5011];
int a,cnt=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
		cin>>a1a[i];
	sort(a1a,a1a+a);
	for(int i=7;i<pow(2,a);i++)
		if(max(a1a[0]*i%2,max(a1a[1]*i/2%2,max(a1a[2]*i/4%2,max(a1a[3]*i/8%2,max(a1a[4]*i/16%2,max(a1a[5]*i/32%2,max(a1a[6]*i/64%2,max(a1a[7]*i/128%2,max(a1a[8]*i/256%2,a1a[9]*i/512%2)))))))))*2<
		a1a[0]*i%2+a1a[1]*i/2%2+a1a[2]*i/4%2+a1a[3]*i/8%2+a1a[4]*i/16%2+a1a[5]*i/32%2+a1a[6]*i/64%2+a1a[7]*i/128%2+a1a[8]*i/256%2+a1a[9]*i/512%2)
		{
			cnt++;
		}
	cout<<cnt;
	return 0;
}
