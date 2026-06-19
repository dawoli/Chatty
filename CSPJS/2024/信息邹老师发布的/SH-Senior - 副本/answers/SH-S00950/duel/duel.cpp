#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main(){
	freopen("duel.in",r,stdin);
	freopen("duel.out",w,stdout);
	deque <int> q[maxn];
	priority_queue <int> na[maxn];//注意这里都是q.pop()两个都得没，所以得再开个记录的数组 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,cnt=0;
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	while(!(q.empty() || ((q.size()==1 || q.front()=q.back())&& (q.back()-na.front() <=0)))){
		int bukechi=q.back()-q.front();
		int kechi=q.back()-na.front();//可耻吃已经没战斗力的
		if(kechi>0 && bukechi>0){
			if(kechi<bukechi){
				na.push(kechi);
				na.pop();
				q.pop_back();
			}else{
				na.push(bukechi);
				q.pop_front(),q.pop_back();
			}
		ans++;
		}else if(kechi<0 && bukechi<0){//现在没法吃 
			break;
		}else{
			if(kechi>0){
				na.push(kechi);
				na.pop();
				q.pop_back();
			}else{
				na.push(bukechi);
				q.pop_front(),q.pop_back();
			}
			ans++;
		}
	}
	cout<<n-ans;
	return 0;
}//对的但是慢，考虑优化 
