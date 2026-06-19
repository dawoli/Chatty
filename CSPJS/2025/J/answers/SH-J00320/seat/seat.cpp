#include <bits/stdc++.h>

using namespace std;

int g[114][514];
vector<int> s;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int r;
    cin>>r;
    s.push_back(r);
    for(int i=2;i<=n*m;i++){
        int t;
        cin>>t;
        s.push_back(t);
    }
    sort(s.begin(),s.end(),cmp);
    int i=1,j=1,k=0;
    bool f1=0,f2=1;
    int o=1; // 1 down;2 up
    while(i<=n&&j<=m){
        g[i][j]=s[k++];
        // cout<<i<<" "<<j<<endl;
        if(g[i][j]==r){
            cout<<j<<" "<<i<<endl;
            break;
        }
        if(i==n){
            if(f1){
                i--;
                f1=0;
                o=2;
            }
            else{
                j++;
                f1=1;
            }
        }else if(i==1){
            if(f2){
                i++;
                f2=0;
                o=1;
            }else{
                j++;
                f2=1;
            }
        }else{
            o==1?i++:i--;
        }
    }
    // for(int i=1;i<=n;i++,cout<<endl)
    //     for(int j=1;j<=m;j++)
    //         cout<<g[i][j]<<" ";
    return 0;
}
