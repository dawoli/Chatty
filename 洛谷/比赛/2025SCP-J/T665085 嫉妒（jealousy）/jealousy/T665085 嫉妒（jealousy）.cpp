#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int n,y,s,t;//分别表示面试的场数，小 Y 开始打工的时刻，一场面试的时长和巡视一圈的时长
    void Soar()
    {
        cin>>n>>y>>s>>t;
        for(int i=1;i<=n;i++)
        {
            if(y==(i-1)*s)
            {
                continue;
            }
            if(y==(i)*s)
            {
                continue;
            }
            if((i-1)*s<=y&&i*s<=y)
            {
                cout<<"Yes"<<endl;
                return;
            }
            if(((i-1)*s-y)%t!=0&&(i*s-y)%t!=0)
            {
                cout<<"Yes"<<endl;
                return;
            }
        }
        cout<<"No"<<endl;
        return;
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}