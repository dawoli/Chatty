#include<bits/stdc++.h>
using namespace std;
typedef long long qwq;
const qwq maxn=1e5+5;

qwq T,n,A[4];
qwq a1[maxn],a2[maxn],a3[maxn],ma[maxn];
struct stu{
	qwq id,ls;
};
stu s[maxn];
bool cmp(stu s1,stu s2){
	return s1.ls>s2.ls;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	qwq ans=0;
	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++){
			A[i]=0;
		}
		memset(ma,0,sizeof(ma));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				ma[i]=1;
			}
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				ma[i]=2;
			}
			else {
				ma[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			if(ma[i]==1){
				s[i].ls=a1[i]-max(a2[i],a3[i]);
			}
			else if(ma[i]==2){
				s[i].ls=a2[i]-max(a1[i],a3[i]);
			}
			else {
				s[i].ls=a3[i]-max(a1[i],a2[i]);
			}
			s[i].id=i;
		}
		sort(s+1,s+n+1,cmp);
		for(int j=1;j<=n;j++){
			qwq i=s[j].id;
			if(A[ma[i]]<(n/2)){
				A[ma[i]]++;
				if(ma[i]==1){
					ans+=a1[i];
				}
				else if(ma[i]==2){
					ans+=a2[i];
				}
				else ans+=a3[i];
			}
			else{
				if(ma[i]==1){
					if(a2[i]>=a3[i]&&A[2]<(n/2)){
						A[2]++;
						ans+=a2[i];
					}
					else if(a3[i]>=a2[i]&&A[3]<(n/2)){
						A[3]++;
						ans+=a3[i];
					}
					else{
						if(A[2]<(n/2)){
							A[2]++;
							ans+=a2[i];
						}
						if(A[3]<(n/2)){
							A[3]++;
							ans+=a3[i];
						}
					}
				}
			    if(ma[i]==2){
					if(a1[i]>=a3[i]&&A[1]<(n/2)){
						A[1]++;
						ans+=a1[i];
					}
					else if(a3[i]>=a1[i]&&A[3]<(n/2)){
						A[1]++;
						ans+=a1[i];
					}
					else{
						if(A[1]<(n/2)){
							A[1]++;
							ans+=a1[i];
						}
						if(A[3]<(n/2)){
							A[3]++;
							ans+=a3[i];
						}
					}
				}
				if(ma[i]==3){
					if(a1[i]>=a2[i]&&A[1]<(n/2)){
						A[1]++;
						ans+=a1[i];
					}
					else if(a2[i]>=a1[i]&&A[2]<(n/2)){
						A[2]++;
						ans+=a2[i];
					}
					else{
						if(A[1]<(n/2)){
							A[1]++;
							ans+=a1[i];
						}
						if(A[2]<(n/2)){
							A[2]++;
							ans+=a2[i];
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
