#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 7;

int t, n, maxans = 0;
bool specialA = true, specialB = true, specialC = true;
struct Node{
	int d1, d2, d3;
}A[maxn];

void init(){
	n = 0;
	maxans = 0;
	memset(A, 0, sizeof(A));
}

bool cmpA(Node x, Node y){
	return x.d1 > y.d1;
}

int solve2(){
	int s1 = A[1].d1 + A[2].d2;
	int s2 = A[1].d1 + A[2].d3;
	int s3 = A[1].d2 + A[2].d1;
	int s4 = A[1].d2 + A[2].d3;
	int s5 = A[1].d3 + A[2].d1;
	int s6 = A[1].d3 + A[2].d2;
	cout << max(s1, max(s2, max(s3, max(s4, max(s5, s6))))) << endl;
}

int solveA(){
	sort(A + 1, A + n + 1, cmpA);
	int ans = 0;
	for(int i = 1; i <= n / 2; i++){
		ans += A[i].d1;
	}
	cout << ans << endl;
}

void dfs(int i, int s, int size1, int size2, int size3){
	//cout << i << " " << s << " " << size1 << " " << size2 << " " << size3 << endl;
	if(i == n + 1){
		maxans = max(maxans, s);
		return;
	}
	
	if(i == n){
		if(maxans - s < A[i].d1 and size1 + 1 <= n / 2){
			dfs(i + 1, s + A[i].d1, size1 + 1, size2, size3);
		}
		if(maxans - s < A[i].d2 and size2 + 1 <= n / 2){
			dfs(i + 1, s + A[i].d2, size1, size2 + 1, size3);
		}
		if(maxans - s < A[i].d3 and size3 + 1 <= n / 2){
			dfs(i + 1, s + A[i].d3, size1, size2, size3 + 1);
		}
	}
	else{
		if(size1 + 1 <= n / 2){
			dfs(i + 1, s + A[i].d1, size1 + 1, size2, size3);
		}
		if(size2 + 1 <= n / 2){
			dfs(i + 1, s + A[i].d2, size1, size2 + 1, size3);
		}
		if(size3 + 1 <= n / 2){
			dfs(i + 1, s + A[i].d3, size1, size2, size3 + 1);
		}
	}
	
}

void dfsB(int i, int s, int size1, int size2){
	if(i == n + 1){
		maxans = max(maxans, s);
		return;
	}
	
	if(i == n){
		if(maxans - s < A[i].d1 and size1 + 1 <= n / 2){
			dfsB(i + 1, s + A[i].d1, size1 + 1, size2);
		}
		if(maxans - s < A[i].d2 and size2 + 1 <= n / 2){
			dfsB(i + 1, s + A[i].d2, size1, size2 + 1);
		}
	}
	else{
		if(size1 + 1 <= n / 2){
			dfsB(i + 1, s + A[i].d1, size1 + 1, size2);
		}
		if(size2 + 1 <= n / 2){
			dfsB(i + 1, s + A[i].d2, size1, size2 + 1);
		}
	}
	
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	   
	cin.tie(0);
	   
	cin >> t;
	for(int i = 1; i <= t; i++){
		init();
	   	cin >> n;
	   	for(int j = 1; j <= n; j++){
	   		cin >> A[j].d1 >> A[j].d2 >> A[j].d3;
	   		if(A[j].d2 != 0 or A[j].d3 != 0){
	   			specialA = false;
			}
			if(A[j].d3 != 0){
				specialB = false;
			}
		}
		if(n == 2){
			solve2();
		}
		else if(specialA == true){
			solveA();
		}
		else if(specialB == true){
			dfsB(1, 0, 0, 0);
			cout << maxans << endl;
		}
		else{
			dfs(1, 0, 0, 0, 0);
			cout << maxans << endl;
		}
	}

	cout.tie(0);
	return 0;
}
