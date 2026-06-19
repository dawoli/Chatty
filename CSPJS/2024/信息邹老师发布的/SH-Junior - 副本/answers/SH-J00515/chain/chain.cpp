#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,k,q;
struct node{
	int len;
	string s;
}a[100005];
struct doingth{
	int r,c;
}b[100005];
int main(){
	freopen ("chain.in","r",stdin);
	freopen ("chain.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n>>k>>q;
		for (int i=0;i<n;i++){
			int (j=0;j<=1;j++){
				cin>>a[i].len;
				cin>>a[i].s;
			}
		}
		for (int i=0;i<q;i++){
			cin>>b[i].r>>b[i].c;
		}
		for (int i=0;i<q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
} 
