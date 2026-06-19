#include<bits/stdc++.h>
using namespace std;
int n;
struct S{int s1,s2,s3;int t12,t13,t21,t23,t31,t32;}s[100010];
int smx(int x1,int x2,int x3){return x1+x2+x3-max({x1,x2,x3})-min({x1,x2,x3});}
int trans1(S a){
	return max((a.t12<0 ? a.t12 : 0),(a.t13<0 ? a.t13 : 0));
}
struct cmp1{
	operator()(S a,S b) const{
		if(abs(trans1(a)) != abs(trans1(b)))
			return abs(trans1(a)) > abs(trans1(b));
		return a.s1>b.s1;
	}
};
priority_queue<S, vector<S>, cmp1> q1;
int trans2(S a){
	return max((a.t21<0 ? a.t21 : 0),(a.t23<0 ? a.t23 : 0));
}
struct cmp2{
	operator()(S a,S b) const{
		if(abs(trans2(a)) != abs(trans2(b)))
			return abs(trans2(a)) > abs(trans2(b));
		return a.s2>b.s2;
	}
};
priority_queue<S, vector<S>, cmp2> q2;
int trans3(S a){
	return max((a.t31<0 ? a.t31 : 0),(a.t32<0 ? a.t32 : 0));
}
struct cmp3{
	operator()(S a,S b) const{
		if(abs(trans3(a)) != abs(trans3(b)))
			return abs(trans3(a)) > abs(trans3(b));
		return a.s3>b.s3;
	}
};
priority_queue<S, vector<S>, cmp3> q3;
int ans;
void settle(int x){
	int t1=s[x].s1,t2=s[x].s2,t3=s[x].s3;
	int mx=max({t1,t2,t3});
	ans+=mx;
	if(t1==mx) q1.push(s[x]);
	else if(t2==mx) q2.push(s[x]);
	else q3.push(s[x]);
	return;
}
void resettle(){
	while(true){
		if (q1.size()<=n/2 && 
			q2.size()<=n/2 && 
			q3.size()<=n/2) return ;
		if(q1.size()>n/2){
			S x=q1.top();q1.pop();
			int t=trans1(x);
			ans+=t;
			if(t==x.t12) q2.push(x);
			else if(t==x.t13) q3.push(x);
		}
		else if(q2.size()>n/2){
			S x=q2.top();q2.pop();
			int t=trans2(x);
			ans+=t;
			if(t==x.t21) q1.push(x);
			else if(t==x.t23) q3.push(x);
		}
		else{
			S x=q3.top();q3.pop();
			int t=trans3(x);
			ans+=t;
			if(t==x.t31) q1.push(x);
			else if(t==x.t32) q2.push(x);
		}
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int s1,s2,s3;scanf("%d %d %d",&s1,&s2,&s3);
		s[i].s1=s1;s[i].s2=s2;s[i].s3=s3;
		s[i].t12=s2-s1;s[i].t13=s3-s1;
		s[i].t21=s1-s2;s[i].t23=s3-s2;
		s[i].t31=s1-s3;s[i].t32=s2-s3;
	}
	for(int i=1;i<=n;i++){
		settle(i);
		resettle();
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		memset(s,0,sizeof(s));
		ans=0;
		solve();
	}
	return 0;
}
