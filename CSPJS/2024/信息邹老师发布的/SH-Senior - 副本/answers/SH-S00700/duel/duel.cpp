#include <iostream>
#include <algorithm>
using namespace std;

int n;
int mst[100005];
int t[100005];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> mst[i];
		t[mst[i]]++;
	}
	int ans=0;
	for(int i=1;i<=100000;i++){
		if(t[i]){
			if(t[i]>ans) ans=t[i];
		}
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
1 1
2 2
3 3
4 1
5 2

1 1
4 1
2 2
5 2
3 3

*/
