#include<bits/stdc++.h>
using namespace std;
const int A = (1<<20) + 9;
const int N = 5e5+9;
int a[N] , p[A][2] , n , k  ,now ,t,t_1,cnt;
struct edge{
	int u , v;
}e[int(1e8)],ne[int(1e8)];
bool cmp(const edge &a ,const edge &b){
	return a.u == b.u ? a.v > b.v : a.u < b.u;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i= 1;i <= n;i++){
		p[now][0]++;
		p[now][1] = i-1;
		now= (now ^ a[i]);
		if (p[now^k][0] > 0){
			e[t++]=edge{p[now^k][1]+1,i};
		}
	}
	sort(e,e+t,cmp);
	ne[t_1++] = e[0];
	for (int i = 1 ;i < t ; i++){
		while (e[i].v<=ne[t_1-1].v&&t_1 >= 0){
			t_1--;
		}
		ne[t_1++] = e[i];
	}
	int lest = 0;
	for (int i = 0;i < t_1; i++){
		if (ne[i].u <= lest){
			continue;
		}
		lest = ne[i].v;
		cnt ++;
	}
	cout << cnt; 
	return 0;
}
