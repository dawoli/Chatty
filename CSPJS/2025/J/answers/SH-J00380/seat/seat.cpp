#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int s;
	bool r;
}a[105];
bool cmp(stu c,stu d){
	return c.s>d.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		if(i==1){
			a[i].r=1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].r){
			cout<<ceil((double)i/n)<<' ';
			int cnt=0;
			while(i>=n){
				i-=n;
				cnt++;
			}
			if(cnt%2 ==0){
				if(i==0){
					cout<<1;
					return 0;
				}
				cout<<i;
				return 0;
			}
			if(i==0){
				cout<<n;
				return 0;
			}
			cout<<n-i+1;
			return 0;
		}	
	}
	return 0;
}
