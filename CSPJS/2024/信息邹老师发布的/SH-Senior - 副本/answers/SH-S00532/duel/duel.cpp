#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long a[N],b[N];
struct Node{
	long long x;
	int pos;
}node[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
/*
	for(int i = 1; i <= n; i++){
		cout << b[i] << endl;
	} 
*/
	int k = 0;
	for(int i = 1; i <= n; i++){
		if(i == 1 || i >= 2 && a[i] != a[i-1]){
			k++;
			node[k].x = a[i];
			node[k].pos = 1;
		}else{
			node[k].pos++;
		}
	}
/*
	for(int i = 1; i <= k; i++){
		cout << node[i].x << " " << node[i].pos << endl;
	}
	
	return 0;
*/	
/* 3 2 2 1 1
	一个3，两个2，两个1
	尽可能的消耗其中最小的数 
	 
*/	 
	long long co = 0;
	long long nt = 0;
	for(int i = 2; i <= k; i++){
		co += node[i].pos;
	}
	for(int i = k-1; i >= 1; i--){
		nt += node[i].pos;
	}
	cout << n - min(co,nt);
	
		
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
} 
