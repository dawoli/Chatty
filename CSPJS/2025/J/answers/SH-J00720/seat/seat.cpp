#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int R = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == R) R = i;
	}
	int ansm=0,ansn=0,cnt = 0;
	for(int i = 1;i <= m;i++){
		ansm = i;
		if(i%2==1){
			for(int j = 1;j <= n;j++){
				ansn = j;
				cnt++;
				if(cnt == R) break;
			}
		}else{
			for(int j = n;j >= 1;j--){
				ansn = j;
				cnt++;
				if(cnt == R) break;
			}
		}
		if(cnt == R) break;
	}
	cout<<ansm<<" "<<ansn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
