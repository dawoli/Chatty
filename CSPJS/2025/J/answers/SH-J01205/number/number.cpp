#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    int l=str.size();
    vector<int> a(0);
    int l2=0;
    for(int i=0;i<l;i++){
        if(str[i]>='0'&&str[i]<='9'){
            a.push_back(str[i]-'0');
            l2++;
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<l2;i++){
        cout<<a[i];
    }
    return 0;
}
