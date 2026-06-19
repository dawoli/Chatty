#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans;
	cin>>n;
	ans=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]&&a[j]!=0){
				a[j]=0;
				ans--;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
