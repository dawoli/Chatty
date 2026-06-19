#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000020]={},cnt=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<=l;i++){
        if('0'<=s[i]&&s[i]<='9'){
            num[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(num,num+cnt);
    for(int i=cnt-1;i>0;i--){
        cout<<num[i];
    }
	return 0;

}
