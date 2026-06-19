#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int a, b, c, d;
};

bool cmp(Node a, Node b){
    return a.d<b.d;
}

signed main(){
    freopen("club3.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n, ans = 0;
        cin>>n;
        vector<Node> x, y, z;
        for(int i=1;i<=n;i++){
            int a, b, c;
            cin>>a>>b>>c;
            if(a==max(a,max(b,c))){
                int d=min(a-b,a-c);
                x.push_back({a, b, c, d});
                ans+=a;
            }
            else if(b==max(a,max(b,c))){
                int d=min(b-a,b-c);
                y.push_back({a, b, c, d});
                ans+=b;
            }
            else if(c==max(a,max(b,c))){
                int d=min(c-a, c-b);
                z.push_back({a, b, c, d});
                ans+=c;
            }
            // cout <<ans<<endl;
        }
        // cout <<ans<<" ";
        // cout <<x.size()<<" "<<y.size()<<" "<<z.size()<<" ";
        if(x.size()>(n/2)){
            sort(x.begin(), x.end(), cmp);
            for(int i=0;i<(x.size()-(n/2));i++){
                ans-=x[i].d;
            }
        }
        if(y.size()>(n/2)){
            sort(y.begin(), y.end(), cmp);
            for(int i=0;i<(y.size()-(n/2));i++){
                ans-=y[i].d;
            }
        }
        if(z.size()>(n/2)){
            sort(z.begin(), z.end(), cmp);
            for(int i=0;i<(z.size()-(n/2));i++){
                ans-=z[i].d;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}

//g++ club.cpp -Wall -std=c++14 -O2 -o club & /home/cyez/D/SH-S00294sunheqi/club/club