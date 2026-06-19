#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id,score;
};
node stu[105];
int n,m;
bool cmp(node n,node m)
{
    return n.score>m.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        int x;
        cin>>x;
        stu[i].id=i;
        stu[i].score=x;
    }
    sort(stu+1,stu+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(stu[i].id==1)
        {
            if(i%n==0)
            {
                if(i/n%2==1)
                    cout<<i/n<<" "<<n;
                else
                    cout<<i/n<<" "<<1;
            }
            else
            {
                if((i/n+1)%2==1)
                    cout<<i/n+1<<" "<<i%n;
                else
                    cout<<i/n+1<<" "<<n+1-i%n;
            }
            return 0;
        }
    }
    return 0;
}
