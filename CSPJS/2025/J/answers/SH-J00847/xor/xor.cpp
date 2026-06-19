#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
    int n,k,a[500005]={},b[500005]={},maxn=-1;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(i==1) b[i]=a[i];
        else b[i]=a[i]^b[i-1];
    }
    for(int i = 1;i <= n;i++)
    {
    	int cnt=0;
	    for(int j = 1;j <= n;j++)
	    {
	        if(b[j]^b[i]==k)
	        {
	            cnt++;
	            j=j+j-i;
	    	}
	   	if(cnt > maxn) maxn=cnt;
    	}
	}
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
