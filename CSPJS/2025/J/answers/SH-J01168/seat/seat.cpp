#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int sc,id;
};
bool cmp(node a, node b){
	return a.sc>b.sc;
}
node st[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++){
		cin >> st[i].sc;
		st[i].id=i;
	}
	sort(st+1,st+n*m+1,cmp);
	//cout << st[1].id; 
	int row=1;
	int col=1;
	for (int i=1; i<=n*m; i++){
		if (st[i].id==1){
			cout << col << " " << row;
		}
		int k=(i-1)%(2*n);
		if (0<=k && k<=(n-2)){
			row++;
		}
		if (k==n-1 || k==2*n-1){
			col++;
		}
		if (n<=k && k<=(2*n-2)){
			row--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
8:45 Start: Sort+Mn(M*N<100?????) O(log(nm))
8:51 All Computers are Stuck!!!
8:58 Fixed. Given 10 min Lol
9:03-9:05 Toilet
9:14 Pass All Samples 100 Prs 
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//feropen
//freeopen
//orz orz rp++; 
*/
