#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    vector<int> a;
    int len=str.size();
    for(int i=0;i<len;i++){
        if(isdigit(str[i])) a.push_back(str[i]-'0');
    }
    sort(a.begin(),a.end(),cmp);
    len=a.size();
    for(int i=0;i<len;i++)  cout<<a[i];
    return 0;
}
