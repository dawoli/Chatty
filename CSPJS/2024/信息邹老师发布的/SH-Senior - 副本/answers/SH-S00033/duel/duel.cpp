#include<bits/stdc++.h>
using namespace std;
int a[100005];
queue<int> live;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		live.push(a[i]);
	}
	for(int i = 1;i <= n;i++){
		if(a[i] > live.front()){
			live.pop();
		}
	}
	cout << live.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
