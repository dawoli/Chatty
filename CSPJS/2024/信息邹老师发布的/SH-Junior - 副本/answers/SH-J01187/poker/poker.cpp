#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    map<string,int>mp;
    int cnt=0;
    for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(!mp[s])cnt++;
		mp[s]++;
    }
    cout<<52-cnt<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
