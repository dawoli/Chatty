#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,x;
	cin>>n;
	multiset<int>v;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.insert(x);
		a[i]=x;
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v.size()&&a[i]>*v.begin())v.erase(v.begin()),cnt++;
	}
	cout<<n-cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
