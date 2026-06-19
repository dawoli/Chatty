#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();
	int t=1;
	
	while(c<'0'||c>'9'){
		if(c=='-') t=-1;
		c=getchar();
	}
	int ans=0;
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	if(t==-1) ans*=t;
	return ans;
} 
int x[500500][3],w[50050][3];
struct st{
	int a;
	int b;
};


int sumx[4];
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n=read();
		int flag=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				w[i][j]=read();
				if((j==2||j==3)&&w[i][j]!=0) flag=0;
				x[i][j]=j;
			}
		}
		int an=0;
		if(flag){
			vector<int> ans;
			for(int i=0;i<n;i++){
				ans.push_back(w[i][0]);
			}
			sort(ans.begin(),ans.end(),greater<int>());
			
			for(int i=0;i<n/2;i++){
				an+=ans[i];
			}			
		}
		cout<<an<<endl;
	}
	return 0;
}
