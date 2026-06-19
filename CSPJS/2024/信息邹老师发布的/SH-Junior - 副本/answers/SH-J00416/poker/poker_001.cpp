#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string sz;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		cin>>sz;
		if(mp[sz]!=1){
			mp[sz]=1;
			cnt++;
		}
	}
	printf("%d\n",52-cnt);
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
