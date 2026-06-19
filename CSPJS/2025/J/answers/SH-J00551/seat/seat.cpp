#include <bits/stdc++.h>
using namespace std;

int n,m,r,pt[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	pt[1] = r;
	for(int i = 2;i <= n*m;i++){
		cin >> pt[i];
	}
	sort(pt+1,pt+(n*m)+1);
	int t = n*m;
	for(int i = 1;i <= n;i++){
		int j = 1;
		if(i % 2 == 0){
			j = m;
			for(;j >= 1;j--){
				if(pt[t] == r){
					cout << i << " " << j;
					return 0;
				}
				t--;
			}
		}
		else{
			for(;j <= m;j++){
				if(pt[t] == r){
					cout << i << " " << j;
					return 0;
				}
				t--;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
