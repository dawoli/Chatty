#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt;
	bool flag=1;
	char a[60],b[60];
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<i;j++){
			if(a[j]==a[i]&&b[j]==b[i]){
				cnt--;
			}
		}
	}
	cout<<52-cnt;
	return 0;
}
