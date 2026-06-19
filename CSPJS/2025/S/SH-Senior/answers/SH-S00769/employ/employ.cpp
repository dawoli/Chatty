#include<bits/stdc++.h>
using namespace std;
int c[509],a[509];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		a[i]=i;
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=i-cnt-1)
				continue;
			if(s[i-1]=='1')
				cnt++;
		}
		ans+=(cnt>=m);
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
//rp++ 
