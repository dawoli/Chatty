#include<bits/stdc++.h>
using namespace std;
int n,ret;
string s;
map<string,int>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		if(mp[s]==0){
			ret++;
		}mp[s]=1;
	}printf("%d",52-ret);
	return 0;
}
