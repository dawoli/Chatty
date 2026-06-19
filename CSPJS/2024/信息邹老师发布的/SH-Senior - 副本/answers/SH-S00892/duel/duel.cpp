#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100001],cnt,b[100001];
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]&&b[j]!=0){
				cnt--;
				b[j]=0;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
