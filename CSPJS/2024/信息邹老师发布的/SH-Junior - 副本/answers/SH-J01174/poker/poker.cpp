#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
struct N{
	char a,b;
}p[60];
bool cmp(N a,N b){
	if(a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].b;
	sort(p+1,p+n+1,cmp);
	ans=n;
	for(int i=1;i<n;i++)
		if(p[i].a==p[i+1].a&&p[i].b==p[i+1].b)
			ans--;
	cout<<52-ans;
	return 0;
}
