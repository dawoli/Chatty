#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 string s;
 cin>>s;
 for(int i=0;i<s.size();i++){
  if(s[i]>='0'&&s[i]<='9'){
   cnt[int(s[i])-int('0')]++;
  }
 }
 for(int j=9;j>=0;j--){
  for(int k=1;k<=cnt[j];k++){
   cout<<j;
  }
 }
 return 0;
} 
