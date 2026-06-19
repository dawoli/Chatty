#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,a[N],MAX;
stack<int> q1,q2;
void f(int x,int ans){
	int h,t;
	if(x>n){
		MAX=max(ans,MAX);
		return;
	}
	if(q1.size()!=0){
		h=q1.top();		
	}
	if(a[x]==h&&q1.size()){
		q1.push(a[x]);
		f(x+1,ans+a[x]);
		q1.pop();
	}
	if(q2.size()!=0){
		t=q2.top();	
	}
	if(a[x]==t&&q2.size()){
		q2.push(a[x]);
		f(x+1,ans+a[x]);
		q2.pop();
	}
	else{
		q1.push(a[x]);
		f(x+1,ans);
		q1.pop();
		q2.push(a[x]);
		f(x+1,ans);
		q2.pop();
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		MAX=0;
		for(int i=1;i<=q1.size();i++){
			q1.pop();
		}
		for(int i=1;i<=q2.size();i++){
			q2.pop();
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		f(1,0);
		cout<<MAX<<endl;
	}
	return 0;
}
