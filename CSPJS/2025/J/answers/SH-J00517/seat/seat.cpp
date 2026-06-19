#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct achieve{
	int score,id;
}a[1000009];
int n,m;
bool cmp(const achieve &a,const achieve &b){
	if(a.score>b.score)return 1;
	if(a.score<b.score)return 0;
	return a.id<b.id;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int at;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			at=i;
			break;
		}
	}
	int l=1;
	while(at>n){
		at-=n;
		l++;
	}
	int r=0;
	if(l%2==1)r=at;
	else r=m-at+1;
	cout<<l<<' '<<r;
	return 0;
}


