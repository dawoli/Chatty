#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5;
long long n,m,id,c,l;
long long a[MAXN];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	int sc = a[1];
	for(int i = 2;i <= n*m;i++) cin >> a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == sc) id = i;
	}
	if(n == 1){
		if(id % 1 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 2){
		if(id % 2 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 3){
		if(id % 3 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 4){
		if(id % 4 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 5){
		if(id % 5 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 6){
		if(id % 6 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 7){
		if(id % 7 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 8){
		if(id % 8 == 0) c = id / n;
		else c = id/n+1;	
	}
	else if(n == 9){
		if(id % 9 == 0) c = id / n;
		else c = id/n+1;	
	}
	if(c % 2 == 0) l = n*c-id+1;
	else l = n-(n*c - id);
	cout << c << " " << l;
	return 0;
}
