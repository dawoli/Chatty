#include <bits/stdc++.h>
using namespace std;
int n,a[100010],mx,b[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int m=n;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]&&!b[j]){
				m--; 
				b[j]=1;
				break;
			}
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
