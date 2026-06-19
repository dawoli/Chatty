#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n,brr[100000];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k[100000],a,arr[100000];
        cin>>a;
        for(int j=0;j<a;j++)
        {
            cin>>k[i];
            arr[k[i]]++;
        }
        for(int j=0;j<a;j++)
        {
            if(arr[j]>=2)
            {
                brr[i]+=j*(arr[j]/2);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<brr[i]<<endl;
    }
	fclose(stdin);
    fclose(stdout);
    return 0;
}