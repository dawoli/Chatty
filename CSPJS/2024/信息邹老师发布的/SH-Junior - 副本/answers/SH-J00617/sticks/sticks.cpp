#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ssum [15] = {6,2,5,5,4,5,6,3,7,6};
struct nums
{
    int num,sticks;
}a[15] = {{0,6},{1,2},{2,5},{4,4},{6,6},{7,3},{8,7}};


bool cmp(nums a,nums b)
{
    if (a.sticks != b.sticks)
        return a.sticks > b.sticks;
    else
        return a.num < b.num;
}

struct node
{
    int step,sum,n;
};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int t;
    cin>>t;
    sort(a+1,a+9+1,cmp);
    while(t--)
    {
        int n;
        cin>>n;
        queue<node> q;
        for(int i = 0;i<=9;i++)
        {
            q.push({1,i,n-ssum[i]});
        }
        bool f = 0;
        while (!q.empty())
        {
            node t = q.front();
            q.pop();
            if (t.n == 0 && t.sum != 0 && t.sum >= 0)
            {
            	f = 1;
                cout<<t.sum<<endl;
                break;
            }
            if (t.n < 0)
                continue;
            for(int i = 0;i<=9;i++)
            {
            	if (t.step == 1 && i == 0) continue;
                q.push({t.step+1, i + pow(10,t.step) * t.sum,t.n-ssum[i]});
            }
        }
        if (!f)
        	cout<<-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

