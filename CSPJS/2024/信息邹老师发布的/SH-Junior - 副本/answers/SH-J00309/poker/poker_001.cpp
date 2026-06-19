#include<bits/stdc++.h>
using namespace std;
char a[55][55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cnt=0;
		cin>>a[i][0]>>a[i][1];
		for(int j=0;j<i;++j){
			if(char(a[i][0])==char(a[j][0])&&char(a[i][1])==char(a[j][1]))
				cnt=1;
		}
		if(cnt!=1)
			ans=ans+1;
	}
	cout<<52-ans;
	return 0;
}
