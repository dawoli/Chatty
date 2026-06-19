#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
long long f[1000050];
//map<long long,long long> f;
long long g[200010];
long long q=0;
long long b[200010];
long long ans=0;

void print128(){
	stack<int> s;
	while(ans>0){
		s.push(ans%10);
		ans/=10;
	}
	while(!s.empty()){
		printf("%d",s.top());
		s.pop();
	}
	printf("\n");
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		b[0]=0;
		a[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=b[i-1];
			if(a[i]==a[i-1]) b[i]+=a[i-1];
			f[a[i]]=0;
		}
//		memset(f,0,sizeof(f));
//		memset(g,0,sizeof(g));
//		q=0;
//		ans=0;

//		for(int i=1;i<=n-1;i++){
//			int j=i+1;
//			for(int k=1;k<i;k++){
//				f[i][j]=max(f[i][j],f[k][i]+((a[k]==a[j])?a[k]:0));
//				ans=max(ans,f[i][j]);
//			}
//			for(j=i+2;j<=n;j++){
//				f[i][j]=f[i][i+1]+b[j]-b[i+1];
//				ans=max(ans,f[i][j]);
//			}
//		}

//		for(int i=1;i<=n-1;i++){
//			int j=i+1;
//			for(int k=1;k<i;k++){
//				g[i]=max(g[i],g[k]-b[k+1]+((a[k]==a[j])?a[k]:0));
//			}
//			cout<<"MAX"<<sta<<" "<<stb<<endl;
//			g[i]+=b[i];
//			cout<<g[i]<<endl;
//			ans=max(ans,g[i]+b[n]-b[i+1]);
//		}
//		cout<<"endnd"<<endl;

		memset(f,0,sizeof(f));
//		f.clear();
		memset(g,0,sizeof(g));
		q=0;
		ans=0;
		for(int i=1;i<=n-1;i++){
			g[i]=max(q,f[a[i+1]]);
//			cout<<"MAX"<<q<<" "<<f[a[i+1]]<<endl;
			g[i]+=b[i];
//			cout<<g[i]<<endl;
			q=max(q,g[i]-b[i+1]);
			f[a[i]]=max(f[a[i]],g[i]-b[i+1]+a[i]);
			ans=max(ans,(long long)(g[i]+b[n]-b[i+1]));
		}
		print128();
	}
	return 0;
}
