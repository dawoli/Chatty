#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,cnt;
string s;
map<string,bool> p;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s;
		if(!p[s])cnt++;
		p[s]=1;
	} 
	printf("%d\n",52-cnt);
	return 0;
}
