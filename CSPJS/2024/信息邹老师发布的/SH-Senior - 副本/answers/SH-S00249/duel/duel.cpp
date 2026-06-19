#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
struct GUAISHOU{
	long long x;
	bool flag=0,huozhe=1;
}a[N];
//stack<long long> q;
//stack<long long> p;
long long n,cnt;
bool cmp(GUAISHOU a,GUAISHOU b){
	return a.x<b.x;
}
int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].x;
//	}
//	sort(a+1,a+1+n,cmp);
//	for(int i=2;i<=n;i++){
//		if(a[i].x>p.top()&&!p.empty()&&a[i].flag==0){
//			q.push(a[i].x);
//			p.pop();
//			a[i].flag=1;
//		}
//		else{
//			p.push(a[i].x);
//		}
//	}
//	cout<<q.size(); 




	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
	}
	sort(a+1,a+1+n,cmp);
	long long l=1,r=2;
	while(l<r&&r<=n){
		if(a[r].huozhe==0||a[r].flag==1){
			r++;
			continue;
		} 
		if(a[l].huozhe==0) {
			r++;
			l=r-1;
			continue;
		}
		if(a[r].x>a[l].x){
			a[l].huozhe=0;
			cnt--;
			a[r].flag=1;
			l=1;
			r=2;
		}
	}
	cout<<cnt;
	return 0;
}
