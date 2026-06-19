#include<bits/stdc++.h>
using namespace std;
int n,a[15],b[15],c[15],d[15],sum=0;
void f(int w,char x){
    int o;
    if(x<='9'&&x>='0'){
        o=int(x-'0');
    }
    else if(x=='A'){
        o=1;
    }
    else if(x=='T'){
        o=10;
    }
    else if(x=='J'){
        o=11;
    }
    else if(x=='Q'){
        o=12;
    }
    else{
        o=13;
    }
    if(w==1){
        a[o]=1;
    }
    else if(w==2){
        b[o]=1;
    }
    else if(w==3){
        c[o]=1;
    }
    else{
        d[o]=1;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        if(s[0]=='D'){
            f(1,s[1]);
        }
        else if(s[0]=='C'){
            f(2,s[1]);
        }
        else if(s[0]=='H'){
            f(3,s[1]);
        }
        else if(s[0]=='S'){
            f(4,s[1]);
        }
    }
    for(int i=1;i<=13;i++){
        if(a[i]==0) sum++;
    }
    for(int i=1;i<=13;i++){
        if(b[i]==0) sum++;
    }
    for(int i=1;i<=13;i++){
        if(c[i]==0) sum++;
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
