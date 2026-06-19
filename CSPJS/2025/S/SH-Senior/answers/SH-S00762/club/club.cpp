#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
int ans = 0;
int n;
node arr[100005];
void dfs(int i,int sum,int a,int b,int c){
	if(a>n/2||b>n/2||c>n/2) return;
	if(i == n+1){
		ans = max(ans,sum);
		return;
	}
	
	dfs(i+1,sum+arr[i].a,a+1,b,c);
	dfs(i+1,sum+arr[i].b,a,b+1,c);
	dfs(i+1,sum+arr[i].c,a,b,c+1);
}
long long maxn(node x){
	return max(x.a,max(x.b,x.c));
}
long long next(node x){
	if(x.a>x.b){
		if(x.b>x.c) return x.b;
		else return x.a>x.c?x.c:x.a;
	}else{
		if(x.a>x.c) return x.a;
		else return x.b>x.c?x.c:x.b;
	}
}
long long minn(node x){
	return min(x.a,min(x.b,x.c));
}
bool bigx(node x,node y,long long op){
	if(op==1) return (maxn(x)-next(x))!=(maxn(y)-next(y));
	else return (maxn(x)-next(x))>(maxn(y)-next(y));
}
bool lowx(node x,node y,long long op){
	if(op==1) return (maxn(x)-minn(x))!=(maxn(y)-minn(y));
	else return (maxn(x)-minn(x))>(maxn(y)-minn(y));
}
bool cmp(node x,node y){
	return abs(x.a-x.b)>abs(y.a-y.b);
}
bool cmp2(node x,node y){
	return x.a>y.a;
}
bool cmp3(node x,node y){
	if(bigx(x,y,1)){
		return bigx(x,y,2);
	}else if(lowx(x,y,1)){
		return lowx(x,y,2);
	}else return maxn(x)>maxn(y);
}
vector<long long> maxk(node x){
	vector<long long>v;
	if(x.a == maxn(x)) v.push_back(1);
	else if(x.b == maxn(x)) v.push_back(2);
	else v.push_back(3);
	return v;
}
vector<long long> nextk(node x){
	vector<long long>v;
	if(x.a == next(x)) v.push_back(1);
	else if(x.b == next(x)) v.push_back(2);
	else v.push_back(3);
	return v;
}
long long cul(long long i,long long &a,long long &b,long long &c){
	vector<long long>idx = maxk(arr[i]);
	for(int j = 0;j<idx.size();j++){
		if(idx[j]==1 && a<n/2){
			a++;
			return maxn(arr[i]);
		}else if(idx[j]==2 && b<n/2){
			b++;
			return maxn(arr[i]);
		}else if(idx[j]==3 && c<n/2){
			c++;
			return maxn(arr[i]);
		}
	}
	
	vector<long long>idx2 = nextk(arr[i]);
	for(int j = 0;j<idx2.size();j++){
		if(idx2[j]==1 && a<n/2){
			a++;
			return next(arr[i]);
		}else if(idx2[j]==2 && b<n/2){
			b++;
			return next(arr[i]);
		}else if(idx2[j]==3 && c<n/2){
			c++;
			return next(arr[i]);
		}
	}
	
	return minn(arr[i]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=10){
			for(int i = 1;i<=n;i++) cin>>arr[i].a>>arr[i].b>>arr[i].c;
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			ans = 0;
		}else{
			bool flag = false;
			bool flag2 = false;
			for(long long i = 1;i<=n;i++){
				cin>>arr[i].a>>arr[i].b>>arr[i].c;
				if(arr[i].b!=0) flag = true;
				if(arr[i].c!=0) flag2 = true;
			}
			if(flag2){
				sort(arr+1,arr+n+1,cmp3);
				long long suma=0,sumb=0,sumc=0;
				for(long long i = 1;i<=n;i++){
					ans+=cul(i,suma,sumb,sumc);
				}
				cout<<ans<<endl;
				ans=0;
			}
			else if(flag){
				sort(arr+1,arr+n+1,cmp);
				long long suma=0,sumb=0;
				for(long long i = 1;i<=n;i++){
					node x = arr[i];
					if(x.a>x.b && suma<n/2){
						ans+=x.a;
						suma++;
					}else{
						ans+=x.b;
						sumb++;
					}
				}
				cout<<ans<<endl;
			}else{
				sort(arr+1,arr+n+1,cmp2);
				for(long long i = 1;i<=n/2;i++) ans+=arr[i].a;
				cout<<ans<<endl;
			}
			ans = 0;
		}
	}
	return 0;
}
