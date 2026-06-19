#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s,cnt = 0;
	cin>>s;
	for(int i = 1;i < n * m;i++){
		int a;
		cin>>a;
		if(a > s){
			cnt++;
		}
	}
	int c = 1,r = 1;
	int up = 1;
	bool flag = 1;
	for(int i = 0;i < cnt;i++){
		if(r == n and flag){
			c++;
			up = -1;
			flag = 0;
		}else if(r == 1 and i != 0 and flag){
			c++;
			up = 1;
			flag = 0;
		}else{
			r += up;
			flag = 1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
