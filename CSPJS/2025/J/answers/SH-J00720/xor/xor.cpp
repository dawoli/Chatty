#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int n,k;
int ding[500005];
int vis[500005];
struct xia{
	int start1,end1;
}wang[500005];
bool cmp(xia x,xia y){
	if (x.start1 - x.end1 != y.start1 - y.end1) return x.start1 - x.end1 < y.start1 - y.end1;
	else return x.start1 < y.start1;
}
int bi(int x){
	a.clear();
	int ans = 0;
	while(x){
		int n1 = x%2;
		a.push_back(n1);
		x/=2;
	}
	for(int i = a.size()-1;i>=0;i--){
		ans*=10;
		ans+=a[i];
	}
	return ans;
}
int xor_f(int x,int y){
	a.clear();
	int ans = 0;
	int bushi = x;
	x = max(x,y);
	y = min(y,bushi);
	while(x){
		int a1,b;
		a1 = x%10;
		b = y%10;
		if(a1!=b){
			a.push_back(1);
		}else{
			a.push_back(0);
		}
		x/=10;
		y/=10;
	}
	for(int i = a.size()-1;i>=0;i--){
		ans*=10;
		ans+=a[i];
	}
	return ans;
}
int bi_opp(int x){
	int ans = 0;
	int cnt = 1;
	while(x){
		int a1;
		a1 = x%10;
		ans+=cnt*a1;
		x/=10;
		cnt*=2;
	}
	return ans;
}
int fxor(int x,int y){
	return bi_opp(xor_f(bi(x),bi(y)));
}
int add(int x,int y){
	if(x == y) return ding[x];
	int ans = 0;
	int num = ding[x];
	for(int i = x+1;i <= y;i++){
		ans = fxor(ding[i],num);
		num = ans;
		
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans = 0;
	
	cin >> n >>k;
	for(int i = 1;i <= n;i++){
		cin >> ding[i];
	}
	int imax = 1;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(add(i,j)==k){
				wang[imax].end1 = j;
				wang[imax].start1 = i;
				imax++;	
			}
		}
	}
	sort(wang+1,wang+imax,cmp);
	for(int i = 1;i <= imax-1;i++){
		xia xxx = wang[i];
		int flag = 1;
		for(int j = xxx.start1;j <= xxx.end1;j++){
			if(vis[j] == 1){
				flag = 0;
			}
		}
			if(flag) {
				ans ++;	
				for(int j = xxx.start1;j <= xxx.end1;j++){
					vis[j] = 1;
				}
			}
		
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
