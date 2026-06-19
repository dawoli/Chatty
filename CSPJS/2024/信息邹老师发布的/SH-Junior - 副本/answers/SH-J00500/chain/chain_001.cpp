#include<bits/stdc++.h>//1
using namespace std;//2
int T;
int main(){//3
    freopen("chain.in","r",stdin);//4
    freopen("chain.out","w",stdout);//5
    cin>>T;
    for(int i=1;i<=T;i++){
        int S[1010][2020];
        int l[1010];
        int mison[1010][2];
        int posb[1010];
        int n,k,q;
        cin>>n>>k>>q;
        for(int j=1;j<=q;j++) posb[j]=0;
        for(int j=1;j<=n;j++){
            cin>>l[j];
            for(int jj=1;jj<=l[j];jj++){
                cin>>S[j][jj];
            }
        }
        for(int j=1;j<=q;j++){
            cin>>mison[j][0]>>mison[j][1];
        }
        for(int j=1;j<=n;j++){
            for(int jj=1;jj<=l[j];jj++){
                for(int jjj=1;jjj<=q;jjj++){
                    if(S[j][jj]==mison[jjj][1]) posb[jjj]=1;
                }
            }
        }
        for(int j=1;j<=q;j++){
            cout<<posb[j]<<endl;
        }
    }
    return 0;//6
}//3
