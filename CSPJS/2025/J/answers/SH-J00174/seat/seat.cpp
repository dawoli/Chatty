#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105];
bool cmp(int x,int y){
    return x > y;	
}	
int main(){
	
    freopen64("seat.in","w",stdin);
    freopen64("seat.in","r",stdin);
    freopen64("seat.out","w",stdout);
    
    int n,m;
    cin >> n >> m;
    int t = n*m;
    for (int i = 1;i <= t;i++){
		cin >> a[i];
	}
	int x = a[1];
	int w = 0;
	sort(a+1,a+t+1,cmp);
	for (int i = 1;i <= t;i++){
		if (a[i] == x){
			w = i;
		}
	}
	int p = w / (2*n);
	int q = w % (2*n);
	if (q <= n && q != 0){
		cout << 2*p+1 << " " << q;
	}
	else if (q == 0){
		cout << 1 << " " << 2*p;
	}
	else{
		cout << 2*p+2 << " " << 2*n-q+1;
	}
    return 0;
}
