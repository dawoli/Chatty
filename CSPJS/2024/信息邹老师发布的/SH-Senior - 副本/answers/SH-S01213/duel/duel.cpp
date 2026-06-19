// espyjump JZJF 24-10-26
// Nunc sola via est necare aut necari, per aspera ad astra.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,res,prev_i=-1,prev=-1;
    int j;
    cin>>n;
    res=n;
    vector<int> pkmn(n);
    vector<bool> alive(n,true);
    for(auto &i:pkmn) cin>>i;
    sort(pkmn.begin(),pkmn.end());
    for(int i=n-1;i>=0;i--){
        if(prev==pkmn[i]) j=prev_i;
        else j=i-1;
        for(;j>=0;j--){
            if(pkmn[j]<pkmn[i]&&alive[j]){
                alive[j]=false;
                res--;
                break; 
            }
        }
        prev_i=max(j-1,0);
        prev=pkmn[i];
    }
    cout<<res;
    return 0;
}