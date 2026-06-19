#include <bits/stdc++.h>
using namespace std;
int T,n,a[200010],vis[1000010];
long long ans=0;
int main(){
	freopen("color.in","w",stdout);
	printf("1\n");
	T=1;
	int n=rand()%15+1;
	cout<<n<<endl;
	srand(rand());
	for(int i=0;i<n;i++){
		cout<<rand()%10<<" ";
		srand(rand());
	}
	return 0;
}
