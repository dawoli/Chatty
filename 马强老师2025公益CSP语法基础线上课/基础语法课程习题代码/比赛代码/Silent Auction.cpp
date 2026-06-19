#include<bits/stdc++.h>
using namespace std;
struct per{
	string name;
	int money,id;
}a[101];
bool cmp(per x,per y){
	if(x.money!=y.money)
		return x.money>y.money;
	else
		return x.id<y.id;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].money;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1].name;
	
}
/*int main(){
	int n,a,maxa=0;
	string s,ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>a;
		if(a>maxa){
			maxa=a;
			ans=s;
		}
	}
	cout<<ans;
	return 0;
}*/

