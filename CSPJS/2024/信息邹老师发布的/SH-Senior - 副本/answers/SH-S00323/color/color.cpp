#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					s+=a[i];
					a[i]=0;
					a[j]=0;
				}
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
