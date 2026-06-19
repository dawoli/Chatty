#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t,n;
long long sum;
int a[N][5];
bool f=0,e=0,g=0;

int dfs(int i,int m1,int m2,int m3){
	if(i==n) {
		if(m1==0) return max(a[i][2],a[i][3]);
		if(m2==0) return max(a[i][1],a[i][3]);
		if(m3==0) return max(a[i][1],a[i][2]);
		return max(a[i][1],max(a[i][2],a[i][3]));
	}
	if(m1==0) 
		sum=max(a[i][2]+dfs(i+1,m1,m2-1,m3),a[i][3]+dfs(i+1,m1,m2,m3-1));
	else if(m2==0)               
		sum=max(a[i][1]+dfs(i+1,m1-1,m2,m3),a[i][3]+dfs(i+1,m1,m2,m3-1));
	else if(m3==0) 
		sum=max(a[i][2]+dfs(i+1,m1,m2-1,m3),a[i][1]+dfs(i+1,m1-1,m2,m3));
	else sum=max(a[i][1]+dfs(i+1,m1-1,m2,m3),max(a[i][2]+dfs(i+1,m1,m2-1,m3),a[i][3]+dfs(i+1,m1,m2,m3-1)));

}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		sum=0;
		f=0,e=0,g=0;
		priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0 || a[i][3]!=0) f=1;
			if(a[i][1]!=0 || a[i][3]!=0) e=1;
			if(a[i][2]!=0 || a[i][1]!=0) g=1;
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3]) q1.push(a[i][1]);
			else if(a[i][2]>a[i][1] && a[i][2]>a[i][3]) q2.push(a[i][2]);
			else if(a[i][3]>a[i][2] && a[i][3]>a[i][1]) q3.push(a[i][3]);
		}
		if(n==2){
			int s1=a[1][1]+a[2][2];
			int s2=a[1][1]+a[2][3];
			int s3=a[1][2]+a[2][1];
			int s4=a[1][2]+a[2][3];
			int s5=a[1][3]+a[2][1];
			int s6=a[1][3]+a[2][2];
			int s7=max(s1,max(s2,s3));
			int s8=max(s4,max(s5,s6));
			cout<<max(s7,s8);
			continue;
		}
		if(f==0){
			while(q1.size()>n/2) q1.pop();
			while(q1.size()) {
				sum+=q1.top();
				q1.pop();
			}
			cout<<sum<<endl;
			continue;
		}
		if(e==0){
			while(q2.size()>n/2) q2.pop();
			while(q2.size()) {
				sum+=q2.top();
				q2.pop();
			}
			cout<<sum<<endl;
			continue;
		}
		if(g==0){
			while(q3.size()>n/2) q3.pop();
			while(q3.size()) {
				sum+=q3.top();
				q3.pop();
			}
			cout<<sum<<endl;
			continue;
		}
		int sum=dfs(0,n/2,n/2,n/2);
//		while(q1.size()>n/2){
//			int i=q1.top();
//			q1.pop();
//			if(a[i][2]>a[i][3]) q2.push(i);
//			else q3.push(i);
//		}
//		while(q2.size()>n/2){
//			int i=q2.top();
//			q2.pop();
//			if(a[i][1]>a[i][3]) q1.push(i);
//			else q3.push(i);
//		}
//		while(q3.size()>n/2){
//			int i=q3.top();
//			q3.pop();
//			if(a[i][2]>a[i][1]) q2.push(i);
//			else q1.push(i);
//		}
//		while(q1.size()){
//			int i=q1.top();
//			q1.pop();
//			sum+=a[i][1];
//		}
//		while(q2.size()){
//			int i=q2.top();
//			q2.pop();
//			sum+=a[i][2];
//		}
//		while(q3.size()){
//			int i=q3.top();
//			q3.pop();
//			sum+=a[i][3];
//		}
		cout<<sum<<endl;
	}
	return 0;
}
