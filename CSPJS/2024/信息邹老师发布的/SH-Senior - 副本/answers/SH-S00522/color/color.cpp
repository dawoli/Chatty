#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c[200001];
ll r[200001],z[200001];
struct color{
	int id;
	int num;
}a[200001];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i].num;
		}
		for(int g=1;g<=n;g++){
			a[g].id=1;
			for(int e=g;e>=0;e--){
				if(a[e].id==a[g].id){
					c[i]=a[e].num;
				}
			}
		}
		r[0]=0;
		r[1]=c[1];
		for(int q=1;q<=n;q++){
			r[q]=r[q-1]+c[q];
		}
		for(int d=1;d<=n;d++){
			r[n]=z[d];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<z[i]<<endl;
	}
	return 0;
}
