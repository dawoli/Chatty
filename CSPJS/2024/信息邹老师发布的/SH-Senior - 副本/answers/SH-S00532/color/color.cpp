#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long a[N],b[N];
struct Node{
	long long amount;
	int num = 0;
}node[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int k = 0;
	int T;
	cin >> T;
	while(T--){
		int x;
		cin >> x;
		for(int i = 1; i <= x; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b+1,b+x+1);
		bool flag = false;
		for(int i = 1; i <= x; i++){
			if(i == 1){
				k++;
				node[k].amount = b[i];
				node[k].num = 1;
			}
			else if(i >= 2 && b[i] == b[i-1]){
				flag = true;
				node[k].num++;
			}else{
				k++;
				node[k].amount = b[i];
				node[k].num = 1;
			}
		}
		if(!flag){
			cout << 0 << endl;
			continue;
		}else{
			long long r = 0;
			for(int i = 1; i <= k; i++){
				//cout << node[i].amount << " " << node[i].num << endl;
				r += node[i].amount * (node[i].num / 2);
			}
			cout << r << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
