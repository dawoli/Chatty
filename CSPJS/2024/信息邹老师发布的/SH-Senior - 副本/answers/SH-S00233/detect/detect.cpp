#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100003
using namespace std;

int T,n,m,L,V,cnt,ans;
int d[N],v[N],a[N],p[N];
vector< pair<int,int> > zone;
// vector<int> zonec[N],ex[N];//point in zone       zone throught point

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first||(a.first==b.first&&a.second<b.second);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int o=0;o<T;o++){
        cnt=0,ans=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>V) 
                zone.push_back((pair<int,int>){d[i],L+1});
        //     if(a[i]==0){
        //         if(v[i]>V){
        //             zone.push_back((pair<int,int>){d[i],L+1});
        //         }
        //     }
        //     else
        //         if(v[i]>V){
        //             // start[i]=d[i];
        //             // end[i]=(int)(V*V-v[i]*v[i])/(2*a[i]);
        //             zone.push_back((pair<int,int>){d[i],(int)(V*V-v[i]*v[i])/(2*a[i])});
        //         }
        //         else{
        //             // start[i]=(int)(V*V-v[i]*v[i])/(2*a[i]);
        //             // end[i]=L+1;
        //             zone.push_back((pair<int,int>){(int)(V*V-v[i]*vfor(int i=0;i<m;i++)cout<<p[m]<<' ';
        //             zonec[i].push_back(j);
        //             ex[j].push_back(i);
        //         }
        //     }
        }
        for(int i=0;i<m;i++)cin>>p[i];
        sort(p,p+m);
        // if(m==2264){
        //     cout<<n<<' '<<m<<' '<<L<<' '<<V;
        //     cout<<endl;
        // }
        for(int i=0;i<zone.size();i++){
            if(zone[i].first<=p[m-1])cnt++;
        }
        cout<<cnt<<" ";
        if(cnt!=0)cout<<m-1<<endl;
        else cout<<m<<endl;
        // zone.clear();
        // for(int i=0;i<n;i++){
        //     zonec[i].clear();
        
    }
    return 0;
}
