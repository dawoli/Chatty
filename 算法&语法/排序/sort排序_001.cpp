#include<iostream>
#include<algorithm>
int MAXN=100001;
using namespace std;
int main() 
{
	int n,i,j,a[MAXN];
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
    for (i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}
