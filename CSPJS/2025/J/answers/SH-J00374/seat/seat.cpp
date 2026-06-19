#include<bits/stdc++.h>
using namespace std;
struct abc{
	int sc;
	int id;
};
bool cmp(abc a1,abc a2){
	return a1.sc>a2.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	struct abc a[1000];
	for(int i=0;i<n*m;i++){
		cin>>a[i].sc;
		a[i].id=i+1;
	}
	sort(a,a+n*m,cmp); 
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		int an=(i+n-1)/n;
		if(a[i-1].id==1 && int(an)%2==1){
			cout<<an<<" "<<cnt;
		}else if(a[i-1].id==1 && int(an)%2==0){
			cout<<an<<" "<<m-cnt+1;
		}
		cnt++;
		if(cnt>m) cnt=1;
	}
	return 0;
}
