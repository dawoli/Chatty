#include<bits/stdc++.h>
using namespace std;
int T,n,a[100001];
long long ans,maxs;
bool book[100001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(book,0,sizeof book);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int num=pow(2,n);
		for(int k=0;k<num;k++){
			maxs=0;
			int x=k;
			for(int i=n;i>=1;i--){
				book[i]=x%2;
				x/=2;
			}
			for(int i=1;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(book[i]==book[j]){
						if(a[i]==a[j]) maxs+=a[j];
						break;
					}
				}	
			}
			ans=max(maxs,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
