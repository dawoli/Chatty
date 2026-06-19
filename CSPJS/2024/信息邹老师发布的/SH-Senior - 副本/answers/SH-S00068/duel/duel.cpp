#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r;
	cin >> n;
	while(n--){
		cin>>r;
		a[r]++;
	}
	int m=-1;
	for(int i=0;i<100001;i++)
	if(a[i]>m)m=a[i];
	cout<<m;
	return 0;
}
