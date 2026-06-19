#include <bits/stdc++.h>
using namespace std;
const int N=110;
struct stu{
	int i,n;
	bool operator <(const stu a)const {
		return n<a.n;
	}
}a[N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].n;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1);
	int cnt=n*m;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(a[cnt--].i==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[cnt--].i==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
