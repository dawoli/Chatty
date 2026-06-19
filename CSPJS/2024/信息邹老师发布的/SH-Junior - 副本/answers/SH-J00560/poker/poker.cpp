#include<bits/stdc++.h>
using namespace std;
int n;
struct stu{
	char hs,p;
}a[60];
bool cmp(stu a,stu b){
	if(a.hs!=b.hs) return a.hs<b.hs;
	if(a.p!=b.p) return a.p<b.p;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].hs>>a[i].p;
	}
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].hs==a[i+1].hs&&a[i].p==a[i+1].p) continue;
		cnt++;
	}
	cout<<52-cnt;
	return 0;
}
