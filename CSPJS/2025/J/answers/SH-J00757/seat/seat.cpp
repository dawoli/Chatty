#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,h;
}s[110];
bool cmp(stu x,stu y){
	return x.a>y.a;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].a;
		s[i].h=i;
	}
	sort(s+1,s+1+n*m,cmp);
	int l;
	for(int i=1;i<=n*m;i++){
		if(s[i].h==1) l=i;
	}
	if(l%n==0){
		if(l/n%2==0){
			cout<<l/n<<" "<<1;
		}
		else{
			cout<<l/n<<" "<<m;
		}
	}
	else{
		if(l/n%2==1){
			cout<<l/n+1<<" "<<n-l%n+1;
		}
		else cout<<l/n+1<<" "<<l%n;
	}
	return 0;
}
