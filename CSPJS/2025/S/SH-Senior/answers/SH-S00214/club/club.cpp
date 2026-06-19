#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,z2;
	bool operator < (const node & a)const{
		return x>a.x;
	}
};
int a[100010][3];
priority_queue<node> q1;
priority_queue<node> q2;
priority_queue<node> q3;
int n;
int fa(int i){
	int m=0;
		int an=0;
		if(a[i][0]>a[i][1]){
			m=a[i][0];
			an=0;
		}
		else if(a[i][0]==a[i][1]){
			m=a[i][0];
			if(q1.size()<q2.size())an=0;
			else an=1;
		}
		else {
			m=a[i][1];
			an=1;
		}
		if(m<a[i][2]){
			m=a[i][2];
			an=2;
		}
	return an;
}
int fb(int i){
	int m=0;
		int an=0;
		if(a[i][0]>a[i][1] and a[i][0]<a[i][2]){
			m=a[i][0];
			an=0;
		}
		else if(a[i][0]==a[i][1] and a[i][2]>a[i][0]){
			m=a[i][0];
			if(q1.size()<q2.size())an=0;
			else an=1;
		}

		else if(a[i][1]>a[i][0] and a[i][1]<a[i][2]){
			m=a[i][1];
			an=1;
		}
		else if(a[i][1]==a[i][2] and a[i][0]>a[i][1]){
			m=a[i][1];
			if(q2.size()<q3.size())an=1;
			else an=2;
		}
		else if(a[i][2]>a[i][1] and a[i][2]<a[i][0]){
			m=a[i][2];
			an=2;
		}
		else if(a[i][2]==a[i][0] and a[i][2]<a[i][1]){
			m=a[i][1];
			if(q3.size()<q1.size())an=2;
			else an=0;
		}
		else{
			an=0;
		}
	return an;
}
int p(int i,int an){
	int am=fb(i);
	if(an==0){
		if(q1.size()<(n/2)){
			q1.push({a[i][an]-a[i][an]-a[i][am],a[i][an],i,an});
			return -1;
		}
		else{
			int xm=fb(q1.top().z);
			if(a[i][an]-a[i][am]>=(q1.top().x)){
				node o=q1.top();
				q1.pop();
				q1.push({a[i][an]-a[i][am],a[i][an],i,an});
				a[o.z][o.z2]=-1;
				return o.z;
			}
			else {
				a[i][an]=-1;
				return i;
			}
		}
	}
	else if(an==1){
		if(q2.size()<(n/2)){
			q2.push({a[i][an]-a[i][an]-a[i][am],a[i][an],i,an});
			return -1;
		}
		else{
			int xm=fb(q2.top().z);
			if(a[i][an]-a[i][am]>=(q2.top().x)){
				node o=q2.top();
				q2.pop();
				q2.push({a[i][an]-a[i][am],a[i][an],i,an});
				a[o.z][o.z2]=-1;
				return o.z;
			}
			else {
				a[i][an]=-1;
				return i;
			}
		}
	}
	else if(an==2){
		if(q3.size()<(n/2)){
			q3.push({a[i][an]-a[i][an]-a[i][am],a[i][an],i,an});
			return -1;
		}
		else{
			int xm=fb(q3.top().z);
			if(a[i][an]-a[i][am]>=(q3.top().x)){
				node o=q3.top();
				q3.pop();
				q3.push({a[i][an]-a[i][am],a[i][an],i,an});
				a[o.z][o.z2]=-1;
				return o.z;
			}
			else {
				a[i][an]=-1;
				return i;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
			cin>>n;
		for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<n;i++){
			int an=fa(i);
			int m=p(i,an);
			while(m!=-1){
				an=fa(m);
				m=p(m,an);
			}
		}
		long long ans=0;
		while(!q1.empty()){
			ans+=q1.top().y;
			q1.pop();
		}
		while(!q2.empty()){
			ans+=q2.top().y;
			q2.pop();
		}
		while(!q3.empty()){
			ans+=q3.top().y;
			q3.pop();
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
