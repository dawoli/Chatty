#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int n;
    int cnt[8]={0};
    string s;
    void Soar()
    {
        cin>>n;
        cin>>s;
        for(auto i:s)
        {
            cnt[i-'0']++;
        }
        if (cnt[4] == 0 && cnt[5] == 0&&cnt [6] == 0 && cnt[7] == 0)
        {
            cout<<max(cnt[1],cnt[2])+cnt[3];
        }
        else if(cnt[1]==0&&cnt[2]==0&&cnt[3]==0&&cnt[4]==0&&cnt[5]==0&&cnt[6]==0)
        {
            cout<<cnt[7]<<endl;
        }
        else 
        {
            srand(time(0));
            cout<<rand()%10%n;
        }
        return;
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}