#include<bits/stdc++.h>;
using namespace std;
int sum,n,q,a[10001][3],l[3];
struct aa{
int s;
int d;

}q1[10000],q2[10000],q3[10000];
int c(aa& b,aa& c){
return b.d<c.d;}
void solve()
{

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=2; j++)
        {
            cin>>a[i][j];
        }
        if(a[i][0]>=max(a[i][1],a[i][2]))
        {
            q1[l[1]++]={i,a[i][0]};
        }
        else
        {
            if(a[i][1]>=max(a[i][0],a[i][2]))
            {
                q2[l[2]++]={i,a[i][1]};
            }
            else
            {
                if(a[i][2]>=max(a[i][1],a[i][0]))
                {
                    q3[l[3]++]={i,a[i][2]};
                }
            }
        }
    }

    sort(q1,q1+l[1],c);
    sort(q2,q2+l[1],c);
    sort(q3,q3+l[3],c);
    if(l[1]>n/2){
        for(int i=0;i<n/2;i++){
            sum+=q1[i].s;
        }
        for(int i=l[1]-1;i>=n/2;i--){
            if(a[q1[i].d][1]>a[q1[i].d][2]){
                sum+=a[q1[i].d][1];
            }else{sum+=a[q1[i].d][2];}
        }
        for(int i=0;i<l[2];i++){
            sum+=q2[i].s;
        }
        for(int i=0;i<l[3];i++){
            sum+=q3[i].s;
        }
    }
    if(l[2]>n/2){
        for(int i=0;i<n/2;i++){
            sum+=q2[i].s;
        }
        for(int i=l[2]-1;i>=n/2;i--){
            if(a[q2[i].d][0]>a[q2[i].d][2]){
                sum+=a[q2[i].d][0];
            }else{sum+=a[q2[i].d][2];}
        }
        for(int i=0;i<l[1];i++){
            sum+=q1[i].s;
        }
        for(int i=0;i<l[3];i++){
            sum+=q3[i].s;
        }
    }
    if(l[3]>n/2){
        for(int i=0;i<n/2;i++){
            sum+=q3[i].s;
        }
        for(int i=l[3]-1;i>=n/2;i--){
            if(a[q3[i].d][0]>a[q3[i].d][1]){
                sum+=a[q3[i].d][0];
            }else{sum+=a[q3[i].d][1];}
        }
        for(int i=0;i<l[1];i++){
            sum+=q2[i].s;
        }
        for(int i=0;i<l[2];i++){
            sum+=q1[i].s;
        }
    }
    else {
        for(int i=0;i<l[1];i++){
            sum+=q1[i].s;
        }

        for(int i=0;i<l[2];i++){
            sum+=q2[i].s;
        }
        for(int i=0;i<l[3];i++){
            sum+=q3[i].s;
        }
    }
    cout<<sum<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        sum=0;
        l[1]=0;
        l[1]=0;
        l[3]=0;
        memset(a,0,sizeof a);
        solve();
    }
    return 0;
}
