#include<iostream>
#include<algorithm>
int MAXN=100001;
using namespace std;
int main() 
{
	int s,n=10,i,j,a[MAXN];
	for(i=0;i<n;i++)cin>>a[i];
	cin>>s;
	sort(a,a+n,greater<int>());
    for (i=0;i<n;i++)
    {
      if(a[i]==s)cout<<++i;
    }
    return 0;
}
