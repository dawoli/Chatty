#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],f[N],cnt=0;
//priority_queue<int,vector<int>,greater<int> >q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		sort(a+1,a+1+n);
		for(int j=1;j<=n;j++){
			if(a[j]>a[i]&&f[j]==0){
				a[i]=-1;
				f[j]=1;
				cnt++;
				i++;
				break;
				cout<<j<<" "<<i<<" "<<a[j]<<" "<<a[i]<<endl;
			}
		}
//		if(x==i||x>n||f[x]) continue;
//		else{
//			a[i]=-1;
//			f[x]=1,f[i]=1;
//			cnt++;
//		}
//		int shaguai=upper_bound(a+1,a+1+n,a[i])-a;
//		if(shaguai==i||shaguai>n||f[shaguai]) continue;
//		else{
//			cnt++;
//			a[i]=-1,f[shaguai]=1,f[i]=1;
//			i++;
//			cout<<i<<" "<<shaguai<<endl;
//		}
	}
	cout<<n-cnt;
	return 0;
}
/*
5
1 2 3 1 2
ans=2

10
136 136 136 2417 136 136 2417 136 136 136
ans=8

30
100001 100000 100000 100000 100000 100000 100000 100000 100000 100000 100001 100002 100000 100000 100000 100000 100000 100000 100000 100000 100001 100002 100000 100000 100000 100000 100000 100000 100000 100000
ans=25 
*/ 
