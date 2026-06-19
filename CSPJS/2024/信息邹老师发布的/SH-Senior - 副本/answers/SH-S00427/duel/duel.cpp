#include<bits/stdc++.h>
#define N 100009
using namespace std;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cur=1;
	for(int i=1;i<=n;i++){
		int alt=cur-1;
		while(a[i]==a[i+1]&&i<=n&&alt>0)alt--,i++;
		while(a[i]==a[i+1]&&i<=n)cur++,i++;
//		cout<<cur<<' '<<i<<endl;
	}
	cout<<cur<<endl;
	return 0;
}
