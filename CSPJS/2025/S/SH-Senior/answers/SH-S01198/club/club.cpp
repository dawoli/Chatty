#include <iostream>
#include <algorithm>
using namespace std;
int a[100005][5];
int main()
{
    // 1
    //6
    //32 3 1
    //55 33 32


    //42+32+33+39+2
    //55+42+39+4+2
    //42 64 39 4 +32 + 1
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2] >>a[i][3] ;
        }
        if(n==2)
        {
            int k1=max(a[1][1],a[2][1]);
            int k2=max(a[1][2],a[2][2]);
            int k3=max(a[1][3],a[2][3]);
            cout<<k1+k2+k3-min(min(k1,k2),k3);
            //39 4
            //25 15
        }
        else{
            cout<<0;
        }

}
