#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using ld=long double;
using namespace std;

struct Car{
    ld exs;
    ld exe;
    bool exc;
    Car(ld x0 ,ld v0, ld v1, ld a,ld road){
        if(a<=0){
            if(v0<=v1){
                exc=false;
                // cout<<1<<endl;
                return;
            }
            if(a==0&&v1>v0){
                exc=true;
                exs=x0;
                exe=1e6+1;
                // cout<<2<<endl;
                return;
            }
            this->exs=x0;
            this->exe=x0+((v1-v0)/a)*v0+(ld)0.5*a*pow((v1-v0)/a,2)-(ld)1e-9;
            exc=true;
            // cout<<3<<endl;
            return;
        }
        this->exs=x0+((v1-v0)/a)*v0+(ld)0.5*a*pow((v1-v0)/a,2)+(ld)1e-9;
        if(this->exs>road){
            exc=false;
            // cout<<4<<endl;
            return;
        }
        this->exe=1e6+1;
        exc=true;
        // cout<<5<<endl;
        return;
    }
    bool operator <(Car b){
        return b.exs<exs;
    }
};

void solve(){
    ld n,m,l,v;
    cin>>n>>m>>l>>v;
    vector<Car> cs;
    ld x0,v0,a;
    Car c=Car(0,0,0,0,0);
    for(int i=0;i<n;i++){
        cin>>x0>>v0>>a;
        c=Car(x0,v0,v, a,l);

        if(c.exs) cs.emplace_back(c);
    }
    for(auto &c:cs) cout<<c.exs<<endl;
    sort(cs.begin(),cs.end());
    vector<ld> p(m);
    for(auto &i:p) cin>>i;
    sort(p.begin(),p.end());
    // vector<bool> vis(cs.size,false);
    // res=cs.size();
    int i=0;
    for(auto &k:p){
        cout<<cs[i].exs<<" "<<cs[i].exe<<endl;
        while(cs[i].exs<=k&&cs[i].exe>=k){
            // cout<<"hmm"<<endl;
            // vis[i]=true;
            i++;
        }
    }
    cout<<cs.size()-i+1;
}

int main(){
    // ld x0,v0,v1,a,road;
    // while(1){
    //     cin>>x0>>v0>>v1>>a>>road;
    //     Car c=Car(x0,v0,v1,a,road);
    //     if(!c.exc){
    //         cout<<"no"<<endl;
    //         continue;
    //     }
    //     cout<<c.exs<<" "<<c.exe<<endl;
    //     // if(c.exs==2) cout<<"oh"<<endl;
    //     // else cout<<2-c.exs;
    // }
    solve();
    return 0;
}