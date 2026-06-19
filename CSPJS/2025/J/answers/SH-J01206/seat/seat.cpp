#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int s,id;	
}a[105];
bool cmp(node x,node y){
	return x.s > y.s;
}
bool f = true;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i=1,j=1,cnt=1;cnt<=n*m;cnt++){
		if (a[cnt].id == 1){
			cout << j << " " << i << endl;
			return 0;
		}
		if (f) i++; 
		else i--;
		if (i > n or i < 1){
			j++;
			f ^= true;
			if (f) i++; 
			else i--;
		}
	}
	return 0;
}
