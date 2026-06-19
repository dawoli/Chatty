#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++){
		int k=0;
		int t=100005;
		for(int i=n;i>0;i--){
			if(a[i]!=0&&t==100005){
				k=1;
				t=a[i];
				a[i]=0;
				cnt++;
				continue;
			}
			if(a[i]<t&&t!=100005&&a[i]!=0){
				t=a[i];
				a[i]=0;
				continue;
			}
		}
		if(k==0){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
