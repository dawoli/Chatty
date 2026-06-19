#include<bits/stdc++.h>
using namespace std;
int a[100010],n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)   cin>>a[i];
	sort(a,a+n);
	int cur=-1;
	for(int i=0;i<n;i++){
		if(a[i]>a[cur+1])   cur++;
	}
	cout<<n-cur-1;
	return 0;
}
