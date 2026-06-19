#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v1,d[100005],v[100005],a[100005],p[100005],sum;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n>>m>>l>>v1;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(v[i]>v1){
				sum++;
			}
		}
		cout<<sum<<" ";
		if(sum==0){
			cout<<m<<endl;
		}
		else{
			cout<<m-1<<endl; 
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
	}
}
