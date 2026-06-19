#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	bool boo=1;
	string a[52];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(a[i]==a[j]){
				boo=0;
				break;
			}
		if(boo)
			cnt++;
		boo=1;
	}
	cout<<52-cnt;
	return 0;
}
