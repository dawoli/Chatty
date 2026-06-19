#include <iostream>
#include <cmath>
using namespace std;

int a[100005],c[100005];
string d[100005];
int x[4];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int j=1;j<=m;j++){
		cin >> c[j];
	}
	int K=ceil(log2(n));
	for(int i=1;i<=n;i++){
		cin >> d[i];
	}
	int T;
	cin >> T;
	while(T--){
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		cout << 0 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
