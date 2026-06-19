#include<bits/stdc++.h>
using namespace std;

struct op{
	string a;
	string b;
}s[20010];

int n,q;

int len(string x){
	int ans=0;
	int i=0;
	while(x[i]!=0){
		ans++;
		i++;
	}
	return ans;
}

string change(string x,string y,string z,int sum){
	int cur;
	int count=0;
	string ans=x;
	for(int i=0;i<len(x);i++){
		cur=i;
		for(int j=0;j<len(y);j++){
			if(x[i+j]!=y[j]){
				cur=-1;
				break;
			}
		}
		count++;
		if(cur!=-1&&count>sum){
			int p=0;
			for(int k=cur;k<cur+len(y);k++){
				ans[k]=z[p];
				p++;
			}
			ans[len(x)]=1;
			break;
		}
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++){
		int ans=0,sum=0;
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			if(len(s[j].a)>len(x)){
				continue;
			}
			while(1){
				string u=change(x,s[j].a,s[j].b,sum);
				if(u==x){
					break;
				}
				if(u[len(x)]==1){
					sum++;
					u[len(x)]=0;
				}
				if(u==y){
					ans++;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
