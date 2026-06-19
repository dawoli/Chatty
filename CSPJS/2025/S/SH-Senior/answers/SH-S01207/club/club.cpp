#include<bits/stdc++.h>
using namespace std;
int t,n,a[100009][4],s1,s2,s3,ans,m1,m2,m3;
bool xuan[100009];
struct murasame{
	int ab;
	int ac;
	int id;
}aa[100009];
bool cmp1(murasame x,murasame y){
	return min(x.ab,x.ac)>min(y.ab,y.ac);
}
bool cmp2(murasame x,murasame y){
	return min(-x.ab,x.ac-x.ab)>min(-y.ab,y.ac-y.ab);
}
bool cmp3(murasame x,murasame y){
	return min(-x.ac,x.ab-x.ac)>min(-y.ac,y.ab-y.ac);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int lmax=n/2;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
			}
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])m1++;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])m2++;
			else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])m3++;
			aa[i].ab=a[i][1]-a[i][2];
			aa[i].ac=a[i][1]-a[i][3];
			aa[i].id=i;
		}
		if(m1<=lmax&&m2<=lmax&&m3<=lmax){
			for(int i=1;i<=n;++i){
				ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
		}
		else if(m1>lmax){
			sort(aa+1,aa+1+n,cmp1);
			for(int i=1;i<=n;++i){
				s1++;
				if(s1<=lmax){
					ans+=a[aa[i].id][1];
				}
				else ans+=max(a[aa[i].id][2],a[aa[i].id][3]);
			}
		}
		else if(m2>lmax){
			sort(aa+1,aa+1+n,cmp2);
			for(int i=1;i<=n;++i){
				s2++;
				if(s2<=lmax){
					ans+=a[aa[i].id][2];
				}
				else ans+=max(a[aa[i].id][1],a[aa[i].id][3]);
			}
		}
		else if(m3>lmax){
			sort(aa+1,aa+1+n,cmp3);
			for(int i=1;i<=n;++i){
				s3++;
				if(s3<=lmax){
					ans+=a[aa[i].id][3];
				}
				else ans+=max(a[aa[i].id][1],a[aa[i].id][2]);
			}
		}
		cout<<ans<<"\n";
		ans=0;
		s1=0;
		s2=0;
		s3=0;
		m1=0;
		m2=0;
		m3=0;
	}
} 
