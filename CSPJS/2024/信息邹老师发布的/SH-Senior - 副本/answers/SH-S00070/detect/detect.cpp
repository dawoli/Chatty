#include<bits/stdc++.h>
using namespace std;
struct car{int d,v,a;};
struct over_limit_car{car cr;int captureParam_id;};
struct over_limit_segment{double st,ed;};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,L,V;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        vector<car> cars;
        for(int i=1;i<=n;i++){
            int d,v,a;
            scanf("%d%d%d",&d,&v,&a);
            cars.push_back({d,v,a});
        }
        vector<int> captureParams;
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            captureParams.push_back(x);
        }
        vector<over_limit_car> over_limit_cars;
        int over_limit_cars_num=0;
        for(car c:cars){
            for(int captureParam:captureParams){
                int s=abs(captureParam-c.d);
                if(sqrt(c.v*c.v*1.+2*c.a*s*1.)>V){
                    over_limit_cars_num++;
                    over_limit_cars.push_back({c,captureParam});
                    break;
                }
            }
        }
        set<int> useful_captureParams;
        // vector<over_limit_segment> over_limit_segments;
        for(over_limit_car cr:over_limit_cars){
            useful_captureParams.insert(cr.captureParam_id);
            // if(cr.cr.v>V&&cr.cr.a>=0)over_limit_segments.push_back({cr.cr.d*1.,L*1.});
            // else if(cr.cr.v>V&&cr.cr.a<0)over_limit_segments.push_back({cr.cr.d*1.,(V*V-cr.cr.v*cr.cr.v)*1./(2*cr.cr.a)+cr.cr.d*1.});
            // else if(cr.cr.v<V&&cr.cr.a>=0)over_limit_segments.push_back({(V*V-cr.cr.v*cr.cr.v)*1./(2*cr.cr.a)+cr.cr.d*1.,L*1.});
        }
        // double maxSt=0,maxEd=0;
        // for(over_limit_segment seg:over_limit_segments){
        //     // cout<<seg.st<<" "<<seg.ed<<endl;
        //     maxSt=max(maxSt,seg.st);
        //     maxEd=max(maxEd,seg.ed);
        // }
        printf("%d %d\n",over_limit_cars_num,m-useful_captureParams.size());
    }
    return 0;
}