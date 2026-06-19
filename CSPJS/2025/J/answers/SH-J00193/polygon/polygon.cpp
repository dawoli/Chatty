#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen(ploygon.in,"r",stdin);
	freopen(ploygon.out,"w",stdout); 
    int n;
    cin>>n;
    int a[n]={};
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int num = 0;
    int maxn = 0;
    int cnt = 0;
    for(int x=3;x<n;x++)
    {
    	for(int b = 0;b<=x;b++)
    	{
    		for(int c = 0;c<=x;c++)
    		{
    			num+=a[c];
    			if(a[c]>maxn)
    			{
    				maxn = a[c];
				}
			}
			if(num>maxn*2)
			{
				cnt++;
			}
		}
	}
    cout<<cnt;
    return 0;
}
