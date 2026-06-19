#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ans[n/7+5];
        int a=0;
        float numb;
        cin>>numb;
        int shu=ceil(numb/7);
        int num=numb;
        if(num==1)
        {
            cout<<-1<<endl;
            continue;
        }
        //cout<<num<<' '<<shu<<endl;
        for (int j=1;j<=shu-1;j++)
        {
            if(j==1)
            {
                if((7*(shu-1)+2)>=num)
                {
                    ans[j]=1;
                    num-=2;
                }
                else if((7*(shu-1)+5)>=num)
                {
                    ans[j]=2;
                    num-=5;
                }
                else if((7*(shu-1)+6)>=num)
                {
                    ans[j]=6;
                    num-=6;
                }
                else if((7*(shu-1)+7)>=num)
                {
                    ans[j]=8;
                    num-=7;
                }
            }
            else
            {
                if((7*(shu-j)+6)>=num)
                {
                    ans[j]=0;
                    num-=6;
                }
                else if((7*(shu-j)+2)>=num)
                {
                    ans[j]=1;
                    num-=7;
                }
                else if((7*(shu-j)+5)>=num)
                {
                    ans[j]=2;
                    num-=7;
                }
                else if((7*(shu-j)+7)>=num)
                {
                    ans[j]=8;
                    num-=7;
                }
            }
        }
        if(num==2)
        {
            //cout<<'e'<<' ';
            ans[shu]=1;
        }
        else if(num==4)
        {
            ans[shu]=4;
        }
        else if(num==5)
        {
            ans[shu]=2;
        }
        else if(num==6)
        {
            ans[shu]=6;
        }
        else if(num==3)
        {
            ans[shu]=7;
        }
        else if(num==7)
        {
            ans[shu]=8;
        }
        for( int j=shu-1;j>=0;j--)
            a+=ans[shu-j]*pow(10,j);
        for(int j=1;j<=shu;j++)
        {
            //cout<<ans[j]<<' ';
        }
        cout<<a<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
