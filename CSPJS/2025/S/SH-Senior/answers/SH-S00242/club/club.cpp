#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n,answ=0;
        cin>>n;
        int sone[n]={0},stwo[n]={0},sthree[n]={0};
        for(int i=0;i<n;i++){
            cin>>sone[i]>>stwo[i]>>sthree[i];
        }
        for(int i=0;i<n;i++){
            if(sone[i]>=stwo[i] && sone[i]>=sthree[i]){
                answ+=sone[i];
            }
            if(stwo[i]>sone[i] && stwo[i]>=sthree[i]){
                answ+=stwo[i];
            }
            if(sthree[i]>sone[i] && sthree[i]>stwo[i]){
                answ+=sthree[i];
            }
        }
        cout<<answ<<endl;
    }
    return 0;
}
