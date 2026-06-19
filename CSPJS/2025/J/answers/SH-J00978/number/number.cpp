#include<bits/stdc++.h>//AC
using namespace std;
#define int long long
char a;
int x[1100000];
int ind=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)if(a<='9'&&a>='0')x[ind]=a-'0',ind++;
	sort(x+1,x+ind);
	for(int i=ind-1;i>=1;i--)cout<<x[i];
	return 0;
}
