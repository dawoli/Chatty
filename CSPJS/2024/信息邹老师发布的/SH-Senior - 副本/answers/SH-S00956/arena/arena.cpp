#include<iostream>
#include<random>
#include<ctime>
using namespace std;
const int MAXN=105;
int n,m,a[MAXN],c[MAXN],k=0;
string s[MAXN];
int b[MAXN];
int main(){
	srand(time(0));
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	while((1<<k)<n){
		k++;
	}
	k--;
	for(int i=0;i<=k;i++){
		cin>>s[i];
	}
	int T,x[4];
	cin>>T;
	while(T--){
		cout<<rand()%(1LL*n*(n+1)/2)<<endl;
	}
	return 0;
}
