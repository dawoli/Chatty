#include <bits/stdc++.h>
using namespace std;
int n,m;
int nmd;
int pos;
int a[107];
int x,y;
int cmp(int c1,int c2){
	return c1 > c2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nmd = n*m;
	for(int i = 1;i<=nmd;i++){
		cin>>a[i]; 
		if(i == 1) pos = a[i];
	}
	sort(a + 1,a + nmd + 1,cmp);
	for(int i = 1;i<=nmd;i++){
		if(pos == a[i]){
			pos = i;
			break;
		}
	}
	if(pos % n == 0){
		y = pos / n;
		if(y % 2 == 1) x = n;
		else x = 1;
	}
	else{
		y = pos / n + 1;
		if(y % 2 == 1) x = pos % n;
		else x = n - pos % n + 1;
	}
	cout<<y<<' '<<x;
	return 0;
} 
