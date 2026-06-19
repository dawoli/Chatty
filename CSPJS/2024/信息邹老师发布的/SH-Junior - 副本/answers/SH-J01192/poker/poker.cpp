#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char a[60],b[60];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int cnt=n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]&&b[i]==b[j]){
				cnt--;
				break;
			} 
		}
	cout<<52-cnt;
	return 0;
}
