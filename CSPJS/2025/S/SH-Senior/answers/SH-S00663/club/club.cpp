#include<bits/stdc++.h>
using namespace std;
int t,n;
struct qwq{
	int a,b,c;
}s[100009];
bool cmp(qwq x,qwq y){
	int a[4],b[4];
	a[1]=x.a;
	a[2]=x.b;
	a[3]=x.c;
	b[1]=y.a;
	b[2]=y.b;
	b[3]=y.c;
	sort(a+1,a+1+3);
	sort(b+1,b+1+3);
	return a[3]-a[2]<b[3]-b[2];
}
long long ans;
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2;
priority_queue<int,vector<int>,greater<int> >q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		sort(s+1,s+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<s[i].a<<" "<<s[i].b<<" "<<s[i].c<<"\n";
//		}
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
			int a=s[i].a;
			int b=s[i].b;
			int c=s[i].c;
			if(a==b&&b==c){
				if(num1<=num2&&num1<=num3){
					num1++;
					q1.push(i);
				}
				else if(num2<=num1&&num2<=num3){
					num2++;
					q2.push(i);
				}
				else{
					num3++;
					q3.push(i);
				}
				ans+=a;
			}
			else if(a>b&&a>c){
				//cout<<"__2__"<<"\n";
				//cout<<i<<"\n";
				if(num1<n/2){
					num1++;
					q1.push(i);
					ans+=a;
				}
				else{
					int k1=q1.top();
					long long p1=a+s[k1].b-s[k1].a;
					long long p2=a+s[k1].c-s[k1].a;
					//cout<<i<<" "<<ans<<" "<<p1<<" "<<p2<<"\n";
					if(p1>0||p2>0){
						if(p1>p2){
							num2++;
							q2.push(k1);
							q1.pop();
							ans+=p1;
						}
						else{
							num3++;
							q3.push(k1);
							q1.pop();
							ans+=p2;
						}
					}
					else{
						if(b>c){
							num2++;
							q2.push(i);
							ans+=b;
						}
						else{
							num3++;
							q3.push(i);
							ans+=c;
						}
					}
				}
			}
			else if(b>a&&b>c){
				//cout<<"__3__"<<"\n";
				if(num2<n/2){
					num2++;
					q2.push(i);
					//cout<<i<<" "<<q2.top()<<"\n";
					ans+=b;
				}
				else{
					int k2=q2.top();
					long long p1=b+s[k2].a-s[k2].b;
					long long p2=b+s[k2].c-s[k2].b;
					//cout<<p1<<" "<<p2<<"\n";
					if(p1>0||p2>0){
						if(p1>p2){
							num1++;
							q1.push(k2);
							q2.pop();
							ans+=p1;
						}
						else{
							num3++;
							q3.push(k2);
							q2.pop();
							ans+=p2;
						}
					}
					else{
						if(a>c){
							num1++;
							ans+=a;
						}
						else{
							num3++;
							ans+=c;
						}
					}
				}
			}
			else if(c>b&&c>a){
				//cout<<"__4__"<<"\n";
				if(num3<n/2){
					num3++;
					q3.push(i);
					//cout<<i<<" "<<q3.top()<<"\n";
					//if(q2.size()) cout<<q2.top()<<"\n";
					ans+=c;
				}
				else{
					int k3=q3.top();
					long long p1=c+s[k3].b-s[k3].c;
					long long p2=c+s[k3].a-s[k3].c;
					//cout<<k3<<" "<<p1<<" "<<p2<<"\n";
					if(p1>0||p2>0){
						if(p1>p2){
							num2++;
							q2.push(k3);
							q3.pop();
							ans+=p1;
						}
						else{
							num1++;
							q1.push(k3);
							q3.pop();
							ans+=p2;
						}
						//cout<<q3.top()<<"\n";
					}
					else{
						if(b>a){
							num2++;
							q2.push(i);
							ans+=b;
						}
						else{
							num1++;
							q1.push(i);
							ans+=a;
						}
					}
				}
			}
//			if(q2.size()){
//				cout<<q2.top()<<"\n";
//			}
			else if(a==b){
				//cout<<"__5__"<<"\n";
				if(num1<num2){
					num1++;
					q1.push(i);
					ans+=a;
				}
				else{
					num2++;
					q2.push(i);
					ans+=b;
				}
			}
			else if(b==c){
				//cout<<"__6__"<<"\n";
				if(num2<num3){
					num2++;
					q2.push(i);
					ans+=b;
				}
				else{
					num3++;
					q3.push(i);
					ans+=c;
				}
			}
			else if(c==a){
				//cout<<"__7__"<<"\n";
				if(num3<num1){
					num3++;
					q3.push(i);
					ans+=c;
				}
				else{
					num1++;
					q1.push(i);
					ans+=a;
				}
			}
		}
		while(q1.size()){
			q1.pop();
		}
		while(q2.size()){
			q2.pop();
		}
		while(q3.size()){
			q3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
