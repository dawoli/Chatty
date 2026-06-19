#include<bits/stdc++.h>
using namespace std;
int a[5001];
bool b[5001];
int n;
int result = 0;
int _max = 0;
int answer = 0;
void dfs(int depth){
	if(depth >  n - 1){
		return;
	}
	if(result > _max * 2 && depth >= 3){
		   answer++;
	}
	bool f = false;
	for(int i = 1;i<=n;i++){
		if(b[i]){
			f = true;
			continue;
		}
		if(!f && depth > 1){
			continue;
		}
		b[i] = true;
	    int oldresult = result;
	    result += a[i];
	    int oldmax = _max;
	    if(a[i] > _max){
		   _max = a[i];
	    }
	    dfs(depth+1);
	    b[i] = false;
	    result = oldresult;
	    _max = oldmax;
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("poloygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n <= 3){
		if(n < 3){
			cout << 0 << "\n";
		}
		cout << (a[1]+a[2]+a[3] > max(a[1],max(a[2],a[3]))) << "\n";
		return 0;
	}
	dfs(1);
	cout << answer * 3 / 2 << "\n";
	return 0;
}
