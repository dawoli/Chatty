#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,q;
struct Node{
	int a,b;
};
Node t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string op1,op2;
		cin>>op1>>op2;
		bool flag=0;
		for(int j=0;j<op1.length()&&flag==0;j++){
			if(op1[j]=='b'){
				t1[i].a=j;
				t1[i].b=op1.length()-1-j;
				flag=1;
			}
		}
		flag=0;
		for(int j=0;j<op2.length()&&flag==0;j++){
			if(op2[j]=='b'){
				t2[i].a=j;
				t2[i].b=op2.length()-1-j;
				flag=1;
			}
		}
		//cout<<t1[i].a<<t1[i].b<<" "<<t2[i].a<<t2[i].b<<endl;
	}
	for(int i=1;i<=q;i++){
		string op1,op2;
		cin>>op1>>op2;
		int c1,c2,d1,d2; 
		bool flag=0;
		for(int j=0;j<op1.length()&&flag==0;j++){
			if(op1[j]=='b'){
				c1=j;
				c2=op1.length()-1-j;
				flag=1;
			}
		}
		flag=0;
		for(int j=0;j<op2.length()&&flag==0;j++){
			if(op2[j]=='b'){
				d1=j;
				d2=op2.length()-1-j;
				flag=1;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			//cout<<t1[j].a<<t1[j].b<<" "<<t2[j].a<<t2[j].b<<" "<<c1<<c2<<" "<<d1<<d2<<endl;
			if(t1[j].a>c1||t1[j].b>c2) continue ;
			if(t2[j].a>d1||t2[j].b>d2) continue ;
			if(t2[j].a-t1[j].a!=d1-c1) continue ;
			if(t2[j].b-t1[j].b!=d2-c2) continue ;
			ans++;
		} 
		cout<<ans<<endl;
	}
	return 0;
}

