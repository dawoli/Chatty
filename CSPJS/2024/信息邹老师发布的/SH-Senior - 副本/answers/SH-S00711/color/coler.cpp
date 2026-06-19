#include<bits/stdc++.h>
using namespace std;
#define makepair pair<int,int>
int t;
int n;
int a[200010];
int b[200010];
long long ans;
void fi(int o,int p){
//	cout << o << " " <<p <<endl;
	if(o >= p)return;
	priority_queue<pair<int,int> > q;
	for(int i = o;i <= p;i++){
		q.push(makepair(a[i],i));
//		cout << q.top().first << " " << q.top().second<< endl; 
	}
	int x = q.top().first;
	int y = q.top().second;
	q.pop();
	while(q.top().first != x && !q.empty() /*&& b[y] != b[q.top().second]*/){
//		cout << q.top().first << " " << q.top().second<< endl; 
		x = q.top().first;
		y = q.top().second;
		q.pop();
	}
	if(q.empty()){
		return;
	}
	int r = y;
	int l = q.top().second;
	if(!b[r] && !b[l]){
		b[r] = b[l] = 1;
		for(int i = l +1;i < r;i++){
			b[i] = 2;
		}
	}
	else{
		b[l] = b[r];
		if(b[l] == 1){
			y = 2;
		}
		else{
			y = 1;
		}
		for(int i = l +1;i < r;i++){
			b[i] = y;
		}
	}
	ans = ans + x;
	for(int i = l +1;i < r;i++){
		if(a[i] == a[i - 1]){
			ans = ans +a[i];
		}
	}
	if(l +1 != r){
		fi(o,l +1);
		fi(r - 1,p);
	} 
	else{
		fi(o,l-1);
		fi(r +1,p);
	} 
//	int q = bg(o,p);
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("coler.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		fi(1,n);
		printf("%d\n",ans);
	}
	return 0;
}
