#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int a[maxn];
queue<int> s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	} 
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]>s.front()){
			s.push(a[i]);
			s.pop();
		}
		else{
			s.push(a[i]); 
		} 
	}
	cout<<s.size();
}
