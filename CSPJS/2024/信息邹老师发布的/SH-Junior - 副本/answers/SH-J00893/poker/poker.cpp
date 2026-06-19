#include <bits/stdc++.h>
using namespace std;
int h[6][15];
int k=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            h[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        string a;
        int c,num;
        cin>>a;
        if(a=="DA"){
            c=1;
            num=1;
        }else if(a=="D2"){
            c=1;
            num=2;
        }else if(a=="D3"){
            c=1;
            num=3;
        }else if(a=="D4"){
            c=1;
            num=4;
        }else if(a=="D5"){
            c=1;
            num=5;
        }else if(a=="D6"){
            c=1;
            num=6;
        }else if(a=="D7"){
            c=1;
            num=7;
        }else if(a=="D8"){
            c=1;
            num=8;
        }else if(a=="D9"){
            c=1;
            num=9;
        }else if(a=="DT"){
            c=1;
            num=10;
        }else if(a=="DJ"){
            c=1;
            num=11;
        }else if(a=="DQ"){
            c=1;
            num=12;
        }else if(a=="DK"){
            c=1;
            num=13;
        }
        else if(a=="CA"){
            c=2;
            num=1;
        }else if(a=="C2"){
            c=2;
            num=2;
        }else if(a=="C3"){
            c=2;
            num=3;
        }else if(a=="C4"){
            c=2;
            num=4;
        }else if(a=="C5"){
            c=2;
            num=5;
        }else if(a=="C6"){
            c=2;
            num=6;
        }else if(a=="C7"){
            c=2;
            num=7;
        }else if(a=="C8"){
            c=2;
            num=8;
        }else if(a=="C9"){
            c=2;
            num=9;
        }else if(a=="CT"){
            c=2;
            num=10;
        }else if(a=="CJ"){
            c=2;
            num=11;
        }else if(a=="CQ"){
            c=2;
            num=12;
        }else if(a=="CK"){
            c=2;
            num=13;
        }
        else if(a=="HA"){
            c=3;
            num=1;
        }else if(a=="H2"){
            c=3;
            num=2;
        }else if(a=="H3"){
            c=3;
            num=3;
        }else if(a=="H4"){
            c=3;
            num=4;
        }else if(a=="H5"){
            c=3;
            num=5;
        }else if(a=="H6"){
            c=3;
            num=6;
        }else if(a=="H7"){
            c=3;
            num=7;
        }else if(a=="H8"){
            c=3;
            num=8;
        }else if(a=="H9"){
            c=3;
            num=9;
        }else if(a=="HT"){
            c=3;
            num=10;
        }else if(a=="HJ"){
            c=3;
            num=11;
        }else if(a=="HQ"){
            c=3;
            num=12;
        }else if(a=="HK"){
            c=3;
            num=13;
        }
        else if(a=="SA"){
            c=4;
            num=1;
        }else if(a=="S2"){
            c=4;
            num=2;
        }else if(a=="S3"){
            c=4;
            num=3;
        }else if(a=="S4"){
            c=4;
            num=4;
        }else if(a=="S5"){
            c=4;
            num=5;
        }else if(a=="S6"){
            c=4;
            num=6;
        }else if(a=="S7"){
            c=4;
            num=7;
        }else if(a=="S8"){
            c=4;
            num=8;
        }else if(a=="S9"){
            c=4;
            num=9;
        }else if(a=="ST"){
            c=4;
            num=10;
        }else if(a=="SJ"){
            c=4;
            num=11;
        }else if(a=="SQ"){
            c=4;
            num=12;
        }else if(a=="SK"){
            c=4;
            num=13;
        }
        h[c][num]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(h[i][j]==0){
                k++;
            }
        }
    }
    cout<<k<<endl;
    return 0;
}
