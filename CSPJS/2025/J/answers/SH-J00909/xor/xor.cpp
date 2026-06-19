#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans3=0,ans4=0;
	long long n,k;
long long f1(int g,int h){
	long long p=0;
	int cnt[30],cnt2[30],cnt3=1,cnt4=1,cnt5[30];
	memset(cnt,0,sizeof(cnt));
	
	memset(cnt2,0,sizeof(cnt2));
	while(g>0){
		cnt[cnt3]=g%2;
		g/=2;
		cnt3++;
	}
	
	while(h>0){
		cnt2[cnt4]=h%2;
		h/=2;
		cnt4++;
	}
	for(int i=1;i<=(max(cnt3,cnt4)-1);i++){
		if(cnt[i]==cnt2[i]){
			cnt5[i]=0;
		}
		else{
			cnt5[i]=1;
		}
	}
	for(int i=1;i<=(max(cnt3,cnt4)-1);i++){
		p+=cnt5[i]*pow(2,i-1);
	}
	return p;
}
long long f2(int l,int r){
	long long ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=f1(ans,a[i]);
	} 
	return ans;
}
void f(int b){
	if(a[b]==k){
		ans3++;
		ans4=max(ans4,ans3);
		f(b+1);
		ans3--;
	}
		for(int j=b;j<=n;j++){
			if(f2(b,j)==k){
				ans3++;
				ans4=max(ans4,ans3);
				f(j+1);
				ans3--; 
			}
		}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[n]==k){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(n==2){
		int w=0;
		if(a[1]==k){
			w++;
		}
		if(a[2]==k){
			w++;
		}
		if(w>0){
			cout<<w;
			return 0;
		}
		if(f1(a[1],a[2])==k){
			w++;
		}
		cout<<w;
		return 0;
	}
	if(k==1){
		int w=0;
		for(int i=1;i<=n;){
			if(a[i]==1){
				w++;
				i++;
				continue;
			}
			if(a[i]==(a[i+1]+1)){
				w++;
				i+=2;
				continue;
			}
			if(a[i]==(a[i+1]-1)){
				w++;
				i+=2;
				continue;
			}
			i++;
		}
		cout<<w;
		return 0;
	}
	if(k==0){
		int w;
		for(int i=1;i<=n;){
			if(a[i]==0){
				w++;
				i++;
				continue;
			}
			if(a[i]==a[i+1]){
				w++;
				i+=2;
			}
			i++;
		}
		cout<<w;
		return 0;
	}
	f(1);
	cout<<ans4;
	return 0;
}
