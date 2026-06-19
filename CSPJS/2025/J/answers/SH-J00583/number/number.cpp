#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int flag=0,a[1000005]={0},max=0;
    string x;
    cin>>x;
    for(int i=0;i<x.length();i++){
        if(x[i]>='0'&&x[i]<='9'){
            flag++;
            a[flag]=int(x[i]-'0');
        }
    }
    sort(a+1,a+flag+1,cmp);
    for(int i=1;i<=flag;i++)cout<<a[i];
    return 0;
}
