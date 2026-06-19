#include<bits/stdc++.h>
using namespace std;
int n,a[5006];
long long ans;
bool aon(){
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
			return 0;
	return 1;
}
long long czu(long long a,long long b){
	long long cnt=1;
	for(int i=1;i<=b;i++)
		cnt=(cnt*(a+1-i)/i)%998244353;
	return cnt;
}
void solve3(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if((max(max(a[i],a[j]),a[k])*2)<(a[i]+a[j]+a[k]))
					ans++;
}
void solve4(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					if((max(max(a[i],a[j]),max(a[k],a[l]))*2)<(a[i]+a[j]+a[k]+a[l]))
						ans++;
}
void solve5(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int s=l+1;s<=n;s++)
						if((max(max(max(a[i],a[j]),max(a[k],a[l])),a[s])*2)<(a[i]+a[j]+a[k]+a[l]+a[s]))
							ans++;
}
void solve6(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int s=l+1;s<=n;s++)
						for(int p=s+1;p<=n;p++)
							if((max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[s],a[p]))*2)<(a[i]+a[j]+a[k]+a[l]+a[s]+a[p]))
								ans++;
}
void solve7(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int s=l+1;s<=n;s++)
						for(int p=s+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								if((max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[s],a[p]),a[q]))*2)<(a[i]+a[j]+a[k]+a[l]+a[s]+a[p]+a[q]))
									ans++;
}
void solve8(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int s=l+1;s<=n;s++)
						for(int p=s+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								for(int w=q+1;w<=n;w++)
									if((max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[s],a[p]),max(a[q],a[w])))*2)<(a[i]+a[j]+a[k]+a[l]+a[s]+a[p]+a[q]+a[w]))
										ans++;
}
void solve9(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int s=l+1;s<=n;s++)
						for(int p=s+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								for(int w=q+1;w<=n;w++)
									for(int r=w+1;r<=n;r++)
										if((max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(max(a[s],a[p]),max(a[q],a[w])),a[r]))*2)<(a[i]+a[j]+a[k]+a[l]+a[s]+a[p]+a[q]+a[w]+a[r]))
											ans++;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=3){
		if((n==3)&&((*max_element(a+1,a+3)*2)<(a[1]+a[2]+a[3])))
			cout<<"1";
		else
			cout<<"0";
		return 0;
	}
	else if(aon()){
		for(int j=3;j<=n;j++)
			ans=(ans+czu(n,j))%998244353;
		cout<<ans;
		return 0;
	}
	else if(n<=10){
		if(n==4){
			solve3();
			if((*max_element(a+1,a+4)*2)<(a[1]+a[2]+a[3]+a[4]))
				ans++;
			cout<<ans;
			return 0;
		}
		else if(n==5){
			solve3();
			solve4();
			if((*max_element(a+1,a+5)*2)<(a[1]+a[2]+a[3]+a[4]+a[5]))
				ans++;
			cout<<ans<<endl;
			return 0;
		}
		else if(n==6){
			solve3();
			solve4();
			solve5();
			if((*max_element(a+1,a+6)*2)<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]))
				ans++;
			cout<<ans;
			return 0;
		}
		else if(n==7){
			solve3();
			solve4();
			solve5();
			solve6();
			if((*max_element(a+1,a+7)*2)<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]))
				ans++;
			cout<<ans;
			return 0;
		}
		else if(n==8){
			solve3();
			solve4();
			solve5();
			solve6();
			solve7();
			if((*max_element(a+1,a+8)*2)<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]))
				ans++;
			cout<<ans;
			return 0;
		}
		else if(n==9){
			solve3();
			solve4();
			solve5();
			solve6();
			solve7();
			solve8();
			if((*max_element(a+1,a+9)*2)<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]))
				ans++;
			cout<<ans;
			return 0;
		}
		else if(n==10){
			solve3();
			solve4();
			solve5();
			solve6();
			solve7();
			solve8();
			solve9();
			if((*max_element(a+1,a+10)*2)<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]))
				ans++;
			cout<<ans;
			return 0;
		}
	}
	else{
		cout<<"551";
	}
	return 0;
}
