#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string st[54];
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		bool flag=false;
		for(int j=1;j<=cnt;j++){
			if(t==st[j]){
				flag=true;
				break;
			}
		}
		if(!flag) st[++cnt]=t;
	}
	int ans=52-cnt;
	cout<<ans;
	return 0;
 } 
