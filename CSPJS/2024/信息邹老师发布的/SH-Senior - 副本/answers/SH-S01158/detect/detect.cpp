#include <bits/stdc++.h>

using namespace std;

int t;
double d[1000000],u[1010],a[1010];
int p[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int j=1;j<=n;j++){
            cin>>d[j]>>u[j]>>a[j];
        }
        for(int j=1;j<=m;j++){
            cin>>p[j];
        }
        int num=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(d[j]>p[k]){
                    continue;
                }
                if(a[j]==0){
                    if(u[j]>v){
                        num++;
                    }
                    continue;
                }
                double s=p[k]-d[j];
                double ss=u[j]*u[j]+2*a[j]*s;
                if(ss<=0){
                    continue;
                }
                double sss=sqrt(ss);
                if(sss<v){
                    num++;
                    break;
                }
            }
        }
        cout<<num<<" ";
    }
    return 0;
}
