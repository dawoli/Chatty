#include <bits/stdc++.h>
using namespace std;
int n,tmp,ans;
bool flag[52];
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    memset(flag,false,sizeof(flag));
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='C')tmp+=13;
        else if(s[0]=='H')tmp+=26;
        else if(s[0]=='S')tmp+=39;
        if(s[1]>='2' && s[1]<='9')tmp+=(s[1]-'0');
        else if(s[1]=='A')tmp++;
        else if(s[1]=='T')tmp+=10;
        else if(s[1]=='J')tmp+=11;
        else if(s[1]=='Q')tmp+=12;
        else if(s[1]=='K')tmp+=13;
        flag[tmp]=true;
        tmp=0;
    }
    for(int i=0;i<52;i++)if(flag[i]==false)ans++;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
