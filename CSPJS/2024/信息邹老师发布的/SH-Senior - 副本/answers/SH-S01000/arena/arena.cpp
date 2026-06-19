#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005],t,k;
long long a1[100005],x[4],a[100005],sum,ans;
bool d[20][50010];
struct node{
	int a=0;
	int sum=0;
};

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	k=log2(n);
	if(1<<k!=n){
		k++;
	}
	for(int i=1;i<=k;i++){
		string dd;
		cin>>dd;
		for(int j=1;j<=dd.length();j++){
			d[i][j]=dd[j-1];
		}
	}
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<n;i++){
			a[i]=a1[i]^x[i%4];
		}
		for(int j=1;j<=m;j++){
			
			int k1=log2(c[j]);
			
			node f[60005];
			for(int i=1;i<=c[j];i++){
				f[i].a=a[i];
				f[i].sum=i;
			}
			for(int i=1;i<=k1;i++){
				for(int q=1;q<=1<<(k1-i);q++){
					if(!d[i][q]){
						if(f[2*q-1].a>=i){
							f[q]=f[2*q-1];
						}else if(0<=f[2*q-1].a&&f[2*q-1].a<i){
							f[q]=f[2*q];
						}
					} else{
						if(f[2*q].a>=i){
							f[q]=f[2*q];
						}else if(0<=f[2*q].a&&f[2*q].a<i){
							f[q]=f[2*q-1];
						}
					}
				}
			}
			ans=ans^(j*f[1].sum);
			
		}
		
		cout<<ans<<endl;
		ans=0;
		
		
		
		
		
		
		
		
		
		
	}
	return 0;
} 
