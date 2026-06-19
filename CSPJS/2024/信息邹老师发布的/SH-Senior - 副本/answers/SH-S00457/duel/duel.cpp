#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int a[100005]; 
stack<int> q;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	int h=1,r=1;
	for(int i=1;i<=n;i++){
		if(a[r]>a[h]){
			h++;
		}
		r++;
		
	}
//	cout << h << r<<endl;
	printf("%d",r-h);
//	int ans=0;
//	q.push(a[1]);
//	for(int i=2;i<=n;i++){
//		int xx=q.top();
//		if(a[i]<=q.top()){
//			ans++;
//		}
//		else {
//			q.pop();
//		}
//		q.push(a[i]);
////		cout << ans << endl;
//	}
//	printf("%d",q.size());
	return 0;
}
