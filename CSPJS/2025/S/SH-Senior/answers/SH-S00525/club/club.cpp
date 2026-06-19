#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,best;
}a[100010],b[100010];
int i1=0,i2=0,i3=0;
bool cmp(node a,node b){
	//if(a.a>b.a) return true;
	if(a.b>b.b) return true;
	//if(a.c>b.c) return true;
	return false;
}
bool cmp2(node a,node b){
	//if(a.a>b.a) return true;
	if(a.b<b.b) return true;
	//if(a.c>b.c) return true;
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n,t,sum=0;
	cin>>t;
	while(t--){ 
	
		cin>>n;
		int k1=n/2,k2=k1,k3=k1;
		i1=0,i2=0,i3=0;
		
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			//b[i].a = a[i].a;b[i].b = a[i].b;b[i].c = a[i].c;
		}
		sort(a+1,a+1+n,cmp);

		for(int i=1;i<=n;i++){
//			cout<<a[i].a<<a[i].b<<a[i].c<<endl;

				if(a[i].a>a[i].b&&a[i].a>a[i].c&&k1) {
					i1+=a[i].a;
					k1--;
//					cout<<"k:"<<k1<<k2<<k3<<endl;
				}

				if(a[i].b>a[i].a&&a[i].b>a[i].c&&k2) {
					i2+=a[i].b;
					k2--;
//					cout<<"k:"<<k1<<k2<<k3<<endl;
				}

				if(a[i].c>a[i].a&&a[i].c>a[i].b&&k3) {
					i3+=a[i].c;
					k3--;
//					cout<<"k:"<<k1<<k2<<k3<<endl;
				}
			
//			cout<<" "<<i1<<" "<<i2<<" "<<i3<<endl;
		}
	
		cout<<i1+i2+i3<<endl;
	} 
	return 0;
}

