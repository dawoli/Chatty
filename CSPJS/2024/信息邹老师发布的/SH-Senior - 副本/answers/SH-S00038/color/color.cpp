#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int q=1;q<=T;q++){
		int n,cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[j]==a[i]){
					cnt+=a[i];
					a[j]=0;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
