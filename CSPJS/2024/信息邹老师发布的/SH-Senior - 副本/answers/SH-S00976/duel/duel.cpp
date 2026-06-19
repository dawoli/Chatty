#include<bits/stdc++.h>
using namespace std;
int n,ans,pt=1;
int a[100005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=1;
	while (true){
		l++;
		if (a[l-1]<a[l]) break;
			}
	for (int i=l;i<=n;i++){
		if (a[pt]<a[i] && a[pt]!=0){
			ans--;
			pt++;
			}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
