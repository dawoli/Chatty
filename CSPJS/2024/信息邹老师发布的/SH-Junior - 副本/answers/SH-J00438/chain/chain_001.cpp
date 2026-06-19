#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,a[10002][10002],b[10002],xx,yy;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        int flag=1;
        memset(b,0,sizeof(b));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            for(int j=1;j<=b[i];j++){
                cin>>a[i][j];
                if(a[i][j]==1) flag=0;
            }
        }
        while(q--){
            cin>>xx>>yy;
            if(flag){
                cout<<0<<endl;
                continue;
            }
            if(xx==1){
                int f=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=b[i];j++){
                        if(a[i][j]==yy){
                            if(k<=j){
                                cout<<1<<endl;
                                f=1;
                                continue;
                            }
                        }
                    }
                    if(f){
                        break;
                    }
                }
                if(!f) cout<<0<<endl;
                continue;
            }
            int f=0;
            if(xx==2){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=b[i];j++){
                        if(a[i][j]==yy){
                            if(k<=j){
                                f++;
                                continue;
                            }
                        }
                    }
                    if(f==2){
                        break;
                    }
                }
                if(f==2){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
                continue;
            }
        }
    }
    return 0;
}

