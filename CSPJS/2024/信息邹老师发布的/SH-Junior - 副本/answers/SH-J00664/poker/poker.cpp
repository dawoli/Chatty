#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    bool b[55];
    int n;
    string s[55];
    cin>>n;
    for (int i=1;i<=52;i++){
        b[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    for (int i=1;i<=n;i++){
        int cnt;
        if (s[i][0]=='D'){
            cnt=0;
        }
        if (s[i][0]=='C'){
            cnt=13;
        }
        if (s[i][0]=='H'){
            cnt=26;
        }
        if (s[i][0]=='S'){
            cnt=39;
        }
        if (s[i][1]=='A'){
            cnt+=1;
        }
        if (s[i][1]=='2'){
            cnt+=2;
        }
        if (s[i][1]=='3'){
            cnt+=3;
        }
        if (s[i][1]=='4'){
            cnt+=4;
        }
        if (s[i][1]=='5'){
            cnt+=5;
        }
        if (s[i][1]=='6'){
            cnt+=6;
        }
        if (s[i][1]=='7'){
            cnt+=7;
        }
        if (s[i][1]=='8'){
            cnt+=8;
        }
        if (s[i][1]=='9'){
            cnt+=9;
        }
        if (s[i][1]=='T'){
            cnt+=10;
        }
        if (s[i][1]=='J'){
            cnt+=11;
        }
        if (s[i][1]=='Q'){
            cnt+=12;
        }
        if (s[i][1]=='K'){
            cnt+=13;
        }
        b[cnt]=1;
    }
    int cnt=0;
    for (int i=1;i<=52;i++){
        if (b[i]==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
