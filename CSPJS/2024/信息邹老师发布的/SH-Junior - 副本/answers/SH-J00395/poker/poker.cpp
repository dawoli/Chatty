#include<bits/stdc++.h>
using namespace std;
const int N=60;
string d[N];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	d[0]='x';
	for(int i=1;i<=n;i++){
		int cnt=0;
		cin>>d[i];
		for(int j=0;j<i;j++){
			if(d[i]!=d[j])
			  cnt++;
			else
			  continue;
		if(cnt==i)
		  ans++;
		}
	}
	cout<<52-ans<<endl;
	return 0;
}
