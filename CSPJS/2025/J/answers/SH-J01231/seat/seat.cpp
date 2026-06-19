#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],LittleR;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> a[i];
	LittleR = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n;i++){
		if(i%2){
			for(int j = 1;j <= m;j++){
				if(a[(i-1)*n+j] == LittleR){
					cout << i << " " << j;
					return 0; 
				}
			}
		}
		else{
			for(int j = m;j >= 1;j--){
				if(a[(i-1)*n+j] == LittleR){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
