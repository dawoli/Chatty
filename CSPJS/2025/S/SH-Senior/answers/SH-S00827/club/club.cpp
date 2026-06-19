#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][3];
int ans=0,cur[3],op;
struct dic{
	int a1,a2,a3,id;
};
vector<dic> m[3];
bool cmp(dic a,dic b){
	if(op==0){
		return a.a1-max(a.a2,a.a3)<b.a1-max(b.a2,b.a3);
	}
	else if(op==1){
		return a.a2-max(a.a1,a.a3)<b.a2-max(b.a1,b.a3);
	}
	else{
		return a.a3-max(a.a1,a.a2)<b.a3-max(b.a1,b.a2);
	}
}
void did(){
	sort(m[op].begin(),m[op].end(),cmp);
	for(int i=0;i<m[op].size()-n/2;i++){
		dic a=m[op][i];
		if(op==0){
			ans-=a.a1-max(a.a2,a.a3);
		}
		else if(op==1){
			ans-=a.a2-max(a.a1,a.a3);
		}
		else{
			ans-=a.a3-max(a.a1,a.a2);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		m[0].clear();
		m[1].clear();
		m[2].clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			dic t;
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				t.a1=a[i][0];
				t.a2=a[i][1];
				t.a3=a[i][2];
				t.id=i;
				m[0].push_back(t);
				ans+=t.a1;
			}
			else if(a[i][1]>=a[i][2]){
				t.a1=a[i][0];
				t.a2=a[i][1];
				t.a3=a[i][2];
				t.id=i;
				m[1].push_back(t);
				ans+=t.a2;
			}
			else{
				t.a1=a[i][0];
				t.a2=a[i][1];
				t.a3=a[i][2];
				t.id=i;
				m[2].push_back(t);
				ans+=t.a3;
			}
		}
		if(m[0].size()<=n/2&&m[1].size()<=n/2&&m[2].size()<=n/2){
			cout<<ans<<endl;
			continue;
		}
		if(m[0].size()>n/2){
			op=0;
			did();
		}
		else if(m[1].size()>n/2){
			op=1;
			did();
		}
		else{
			op=2;
			did();
		}
		m[0].clear();
		m[1].clear();
		m[2].clear();
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
