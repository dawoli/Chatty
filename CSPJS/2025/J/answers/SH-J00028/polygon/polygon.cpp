#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int ans;
void cal(vector<int> l,int n,long long sum,int lst){
	if(l.size()<3){
		return;
	}
	else{
		for(int i = lst;i<l.size();i++){
			if(sum-l[i]>n){
				ans = (ans+1)%N;
				vector<int> tl;
				for(int j = 0;j<i;j++){
					tl.push_back(l[j]);
				}
				for(int j = i+1;j<l.size();j++){
					tl.push_back(l[j]);
				}
				int ts = sum-l[i];
				cal(tl,n,ts,i);
			}
		} 
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i = 0;i<n;i++){
//		cout<<a[i]<<' ';
//	}
//	a[i]作为最大值 
	ans = 0;
	for(int i = 2;i<n;i++){
		//求有多少种方法让长度之和大于a[i]*2 
		vector<int> tl;
		long long sum = 0;
		for(int j = 0;j<i;j++){
			tl.push_back(a[j]);
			sum+=a[j];
		}
		if(sum>a[i]){
			ans++;
		}
		cal(tl,a[i],sum,0);
	}
	cout<<ans;
	return 0;
} 
