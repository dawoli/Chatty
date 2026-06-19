#include <bits/stdc++.h>
using namespace std;
char a[3];
bool p[5][14]={0};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[0]>>a[1];
        if(a[0]=='D')
        {
            if(a[1]=='T') p[1][10]=1;
            else if(a[1]=='J') p[1][11]=1;
            else if(a[1]=='Q') p[1][12]=1;
            else if(a[1]=='K') p[1][13]=1;
            else if(a[1]=='A') p[1][1]=1;
            else if(a[1]=='2') p[1][2]=1;
            else if(a[1]=='3') p[1][3]=1;
            else if(a[1]=='4') p[1][4]=1;
            else if(a[1]=='5') p[1][5]=1;
            else if(a[1]=='6') p[1][6]=1;
            else if(a[1]=='7') p[1][7]=1;
            else if(a[1]=='8') p[1][8]=1;
            else if(a[1]=='9') p[1][9]=1;
        }
        if(a[0]=='C')
        {
            if(a[1]=='T') p[2][10]=1;
            else if(a[1]=='J') p[2][11]=1;
            else if(a[1]=='Q') p[2][12]=1;
            else if(a[1]=='K') p[2][13]=1;
            else if(a[1]=='A') p[2][1]=1;
            else if(a[1]=='2') p[2][2]=1;
            else if(a[1]=='3') p[2][3]=1;
            else if(a[1]=='4') p[2][4]=1;
            else if(a[1]=='5') p[2][5]=1;
            else if(a[1]=='6') p[2][6]=1;
            else if(a[1]=='7') p[2][7]=1;
            else if(a[1]=='8') p[2][8]=1;
            else if(a[1]=='9') p[2][9]=1;
        }
        if(a[0]=='H')
        {
            if(a[1]=='T') p[3][10]=1;
            else if(a[1]=='J') p[3][11]=1;
            else if(a[1]=='Q') p[3][12]=1;
            else if(a[1]=='K') p[3][13]=1;
            else if(a[1]=='A') p[3][1]=1;
            else if(a[1]=='2') p[3][2]=1;
            else if(a[1]=='3') p[3][3]=1;
            else if(a[1]=='4') p[3][4]=1;
            else if(a[1]=='5') p[3][5]=1;
            else if(a[1]=='6') p[3][6]=1;
            else if(a[1]=='7') p[3][7]=1;
            else if(a[1]=='8') p[3][8]=1;
            else if(a[1]=='9') p[3][9]=1;
        }
        if(a[0]=='S')
        {
            if(a[1]=='T') p[4][10]=1;
            else if(a[1]=='J') p[4][11]=1;
            else if(a[1]=='Q') p[4][12]=1;
            else if(a[1]=='K') p[4][13]=1;
            else if(a[1]=='A') p[4][1]=1;
            else if(a[1]=='2') p[4][2]=1;
            else if(a[1]=='3') p[4][3]=1;
            else if(a[1]=='4') p[4][4]=1;
            else if(a[1]=='5') p[4][5]=1;
            else if(a[1]=='6') p[4][6]=1;
            else if(a[1]=='7') p[4][7]=1;
            else if(a[1]=='8') p[4][8]=1;
            else if(a[1]=='9') p[4][9]=1;
        }
    }
    for(int j=1;j<=4;j++)
    {
        for(int k=1;k<=13;k++)
        {
            if(p[j][k]==1)
			{
				ans--;
			}
        }
    }
    cout<<ans<<endl;
    return 0;
}

