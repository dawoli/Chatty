#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[105][105];
int w = 0;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	int aaa = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j = 1;j <= m;j++){
		for(int i = 1;i <= n;i++){
			b[i][j] = a[++w];
		}
		if(j < m)
			j++;
		else 
			break;
		for(int i = n;i >= 1;i--){
			b[i][j] = a[++w];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == aaa){
				cout << j <<' ' << i; 
				return 0; 
			}
		}
	}
	return 0;
}
