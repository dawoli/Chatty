#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
vector<int> ans1,ans2,ans3;
bool cmp1(int x,int y){
	int aa=min(a[x][0]-a[x][1],a[x][0]-a[x][2]);
	int bb=min(a[y][0]-a[y][1],a[y][0]-a[y][2]);
	return aa>bb;
}bool cmp2(int x,int y){
	int aa=min(a[x][1]-a[x][0],a[x][1]-a[x][2]);
	int bb=min(a[y][1]-a[y][0],a[y][1]-a[y][2]);
	return aa>bb;
}bool cmp3(int x,int y){
	int aa=min(a[x][2]-a[x][1],a[x][2]-a[x][0]);
	int bb=min(a[y][2]-a[y][1],a[y][2]-a[y][0]);
	return aa>bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		unsigned int n;
		cin>>n; 
		for(unsigned int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		ans1.clear();
		ans2.clear();
		ans3.clear();
		for(unsigned int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans1.push_back(i);
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans2.push_back(i);
			}
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				ans3.push_back(i);
			}
		}
		if(ans1.size()>n/2){
			sort(ans1.begin(),ans1.end(),cmp1);
			for(unsigned int i=ans1.size()-1;i>=n/2;i--){
				if(a[ans1[i]][0]-a[ans1[i]][1]<a[ans1[i]][0]-a[ans1[i]][2]){
					ans2.push_back(ans1[i]);
					ans1.pop_back();
				}
				else{
					ans3.push_back(ans1[i]);
					ans1.pop_back();
				}
			}
		}
		else if(ans2.size()>n/2){
			sort(ans2.begin(),ans2.end(),cmp2);
			for(unsigned int i=ans2.size()-1;i>=n/2;i--){
				if(a[ans2[i]][1]-a[ans2[i]][0]<a[ans2[i]][1]-a[ans2[i]][2]){
					ans1.push_back(ans2[i]);
					ans2.pop_back();
				}
				else{
					ans3.push_back(ans2[i]);
					ans2.pop_back();
				}
			}
		}
		else if(ans3.size()>n/2){
			sort(ans3.begin(),ans3.end(),cmp3);
			for(unsigned int i=ans3.size()-1;i>=n/2;i--){
				if(a[ans3[i]][2]-a[ans3[i]][1]<a[ans3[i]][2]-a[ans3[i]][0]){
					ans2.push_back(ans3[i]);
					ans3.pop_back();
				}
				else{
					ans1.push_back(ans3[i]);
					ans3.pop_back();
				}
			}
		}
		long long ans=0;
		for(unsigned int i=0;i<min((unsigned int)ans1.size(),n/2);i++) ans+=a[ans1[i]][0];
		for(unsigned int i=0;i<min((unsigned int)ans2.size(),n/2);i++) ans+=a[ans2[i]][1];
		for(unsigned int i=0;i<min((unsigned int)ans3.size(),n/2);i++) ans+=a[ans3[i]][2];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
