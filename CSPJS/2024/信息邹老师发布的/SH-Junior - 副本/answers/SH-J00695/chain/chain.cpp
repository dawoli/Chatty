#include<bits/stdc++.h>
using namespace std;
int t;
int n,q,k,x,r,c;
vector <int> a[100010];
int b[100010];
int l;
bool fi(int o,int p,int e,int g){
//	cout << o << " " << p << " " << e << " " << g << endl;
	if(g == 0){
		return false;
	}
	bool f = false;
	for(int i = 1;i <= n;i++){
		if(i == e){
			continue;
		}
		for(int j = 0;j < b[i];j++){
			if(a[i][j] == p){
				for(int m = j - 1;m >= max(0,j - k + 1);m--){
					f = f | fi(o,a[i][m],i,g - 1);
					if(a[i][m] == o && g == 1){
//						cout << 1 <<endl;
//						cout << o << " " << p << " " << e << " " << g << endl;
//						cout << i << " " << j << " " << m + 1 << endl;
						f = true;
					}
					//	cout << i << " " << j + 1 << " " << m << endl; 
				}
			}
		}
	}
	if(f)return true;
	return false;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		l = 1;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++){
			scanf("%d",&b[i]);
			for(int j = 1;j <= b[i];j++){
				scanf("%d",&x);
				a[i].push_back(x);
			}
		}
		for(int i = 1;i <= q;i++){
			scanf("%d%d",&r,&c);
			if(fi(l,c,0,r)){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
	}
	return 0;
} 
