#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101];

int main(){
	
	freopen("seat.in","r",stdin);
	freoprn("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int score=a[1];
	sort(a+1,a+n*m+1);
	int cnt=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (j%2==0){
				if (a[cnt]==score){
					cout << j << " " << m-i+1;
				}
				cnt++;
			}
			else{
				if (a[cnt]==score){
					cout << j << " " << i;
				}
				cnt++;	
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
