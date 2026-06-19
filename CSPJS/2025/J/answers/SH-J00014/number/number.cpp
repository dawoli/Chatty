#include<bits/stdc++.h>
using namespace std;

string s;
int num[1000001],cnt=0,n[10],k=9;

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){ 
if(s[i]-48>=0&&s[i]-48<=9){
num[cnt]=s[i]-48;
n[s[i]-48]++;
cnt++;
}
}

while(k!=-1){
for(int i=0;i<n[k];i++)
cout<<k;
k--;
}

return 0;
}
