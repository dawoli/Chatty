#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
unsigned long long ans=0;

int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	priority_queue<int>q;
	queue<int> q1;
	for(int i=3;i<=n;i++){
		for(int j=i-2;j>0;j--){
			q1.push(a[j]+a[i-1]);
		}
		while(!q1.empty()){
			q.push(q1.front());
			q1.pop();
		}
		while(!q.empty()){
			int x=q.top();
			if(x>a[i]){
				ans++;
				ans%=998244353;
			}
			q1.push(x+a[i]);
			q1.push(x);
			q.pop();
		}
	} 
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout); 
	return 0;
}
