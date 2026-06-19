#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct stu{
	ll x,y;
}maxs[N];
ll s1[N],s2[N];
int f1[N],f2[N],f3[N],f[N];
bool cmp(stu a,stu b){
	if(a.x!=b.x){
		return a.x>b.x && a.y<=b.y;
	}
	return a.y<b.y;
}
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(f3,0,sizeof f3);
		memset(s1,0,sizeof s1);
		memset(s2,0,sizeof s2);
		memset(maxs,0,sizeof maxs);
		ll n;
		cin>>n;
		ll a,b,c;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>b && a>c){
				maxs[i].x=a;
				s1[i]=1;
				if(b>c){
					s2[i]=2;
					maxs[i].y=b;
				}
				else if(b<c){
					s2[i]=3;
					maxs[i].y=c;
				}
				else if(b==c){
					if(b==0){
						f1[i]=a;
					}
					s2[i]=4;
					maxs[i].y=b;
				}
			}
			else if(b>a && b>c){
				maxs[i].x=b;
				s1[i]=2;
				if(a>c){
					s2[i]=1;
					maxs[i].y=a;
				}
				else if(a<c){
					s2[i]=3;
					maxs[i].y=c;
				}
				else if(a==c){
					if(a==0){
						f2[i]=b;
					}
					s2[i]=4;
					maxs[i].y=a;
				}
			}
			else if(c>a && c>b){
				maxs[i].x=c;
				s1[i]=3;
				if(a>b){
					s2[i]=1;
					maxs[i].y=a;
				}
				else if(a<b){
					s2[i]=2;
					maxs[i].y=b;
				}
				else if(a==b){
					if(a==0){
						f3[i]=c;
					}
					s2[i]=4;
					maxs[i].y=a;
				}
			}
			else if(a==b && a==c){
				s1[i]=4;
				maxs[i].x=maxs[i].y=a;
			}
		}
		ll cnt1=0,cnt2=0,cnt3=0,sum=0;
		sort(f1+1,f1+1+n,cmp1);
		sort(f2+1,f2+1+n,cmp1);
		sort(f3+1,f3+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(f1[i]){
				if(cnt1<n/2){
					cnt1++;
					sum+=f1[i];
					f[i]=1;
				}
			}
			if(f2[i]){
				if(cnt2<n/2){
					cnt2++;
					sum+=f2[i];
					f[i]=1;
				}
			}
			if(f3[i]){
				if(cnt3<n/2){
					cnt3++;
					sum+=f3[i];
					f[i]=1;
				}
			}
		}
		sort(maxs+1,maxs+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(f[i]){
				continue;
			}
			if(s1[i]==1){
				if(cnt1<n/2){
					sum+=maxs[i].x;
					cnt1++;
					//cout<<i<<" "<<s1[i]<<" "<<cnt1<<" "<<sum<<"\n";
				}
				else{
					sum+=maxs[i].y;
					if(s2[i]==2){
						cnt2++;
					//	cout<<i<<" "<<s2[i]<<" "<<cnt2<<" "<<sum<<"\n";
					}
					else if(s2[i]==3){
						cnt3++;
						//cout<<i<<" "<<s2[i]<<" "<<cnt3<<" "<<sum<<"\n";
					}
					else{
						//cout<<i<<" "<<s2[i]<<" "<<sum<<"\n";
					}
				}
			}
			else if(s1[i]==2){
				if(cnt2<n/2){
					sum+=maxs[i].x;
					cnt2++;
					//cout<<i<<" "<<s1[i]<<" "<<cnt2<<" "<<sum<<"\n";
				}
				else{
					sum+=maxs[i].y;
					if(s2[i]==1){
						cnt1++;
						//cout<<i<<" "<<s2[i]<<" "<<cnt1<<" "<<sum<<"\n";
					}
					else if(s2[i]==3){
						cnt3++;
						//cout<<i<<" "<<s2[i]<<" "<<cnt3<<" "<<sum<<"\n";
					}
					else{
						//cout<<i<<" "<<s2[i]<<" "<<sum<<"\n";
					}
				}
			}
			else if(s1[i]==3){
				if(cnt3<n/2){
					sum+=maxs[i].x;
					cnt3++;
					//cout<<i<<" "<<s1[i]<<" "<<cnt3<<" "<<sum<<"\n";
				}
				else{
					sum+=maxs[i].y;
					if(s2[i]==1){
						cnt1++;
						//cout<<i<<" "<<s2[i]<<" "<<cnt1<<" "<<sum<<"\n";
					}
					else if(s2[i]==2){
						cnt2++;
						//cout<<i<<" "<<s2[i]<<" "<<cnt2<<" "<<sum<<"\n";
					}
					else{
						//cout<<i<<" "<<s2[i]<<" "<<sum<<"\n";
					}
				}
			}
			else if(s1[i]==4){
				sum+=maxs[i].x;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
