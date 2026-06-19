#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int n,maxx=0,sum=0;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]+=1;
		c[a[i]]+=1;
		maxx=max(a[i],maxx);
	}
	
	for (int i=1;i<=maxx-1;i++){
		if (b[i]!=0){
			for (int j=i+1;j<=maxx;j++){
				if (c[j]!=0){
					if (c[j]>=b[i]){
						b[i]=0;
						c[j]-=b[i];
					}else{
						b[i]-=c[j];
						c[j]=0;
					}
				}
			}
		} 
	}
	
	for (int i=1;i<=maxx;i++){
		sum+=b[i];
	}
	cout<<sum<<endl;
} 
