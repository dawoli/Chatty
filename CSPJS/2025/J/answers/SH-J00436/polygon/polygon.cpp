#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		int ans=0;
		for(int j=1;j<=i;j++){
			ans+=a[j];
		}
		for(int j=1;j<=i;j++){
			if(ans-a[j]>a[i]){
				num++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout<<num;
	return 0;
}
