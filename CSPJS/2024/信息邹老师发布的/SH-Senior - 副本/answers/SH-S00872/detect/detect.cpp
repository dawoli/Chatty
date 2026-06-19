#include<bits/stdc++.h>
using namespace std;
const int L=1e6+10;
const int N=1e5+10;
struct node{
	int d,v,acc,pl,pr;
}a[N];
vector<int> overspeed;
int p[N],n,m,sl[L],sr[L];
//bool cmp(int x,int y){
//	if(a[x].pl!=a[y].pl) return a[x].pl<a[y].pl;
//	else if(a[x].pr!=a[y].pr) return a[x].pr<a[y].pr;
//	else return 0;
//}
//int shut(){
//	sort(overspeed.begin(),overspeed.end(),cmp);
//	int ans=f[p[m]];
//	for(int i=0;i<=overspeed.size();i++){
//			ans&=f[i];
//	}
//	return ans;
//}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int L,V,ans1=0,ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].acc;
		for(int i=1;i<=m;i++){
			cin>>p[i];
			//f[p[i]]+=1<<i;
			for(int j=p[i-1]+1;j<=p[i];j++){
				//f[j]=f[p[i]];
				sr[j]=i;
				sl[j]=i-1;
			}
			sr[p[i]]=i;
			sl[p[i]]=i;
		}
		for(int i=p[m]+1;i<=L;i++){
			sl[i]=p[m];
			sr[i]=m+1;
		}
		for(int i=1;i<=n;i++){
			if(a[i].acc==0){
				if(a[i].v>V&&a[i].d<=p[m]){
					//if(a[i].d>p[m-1]) uni[M].push_back(x);
					ans1++;
					overspeed.push_back(i);
					///f[i]+=1<<sr[a[i].d]
					//f[i]+=1<<m;
					a[i].pl=sr[a[i].d];
					a[i].pr=m;
				}
			}
			if(a[i].acc<0&&a[i].v>V){
				int x;
				if(((V+a[i].v)*(V-a[i].v))%(2*a[i].acc)==0) x=((V+a[i].v)*(V-a[i].v))/(2*a[i].acc)+a[i].d-1;
				else x=floor((V+a[i].v)*(V-a[i].v)/(double)(2*a[i].acc))+a[i].d;//where vi decreases to maximum
				int pos1=sl[x],pos2=sr[a[i].d];
				if(a[i].v>V&&pos1>=pos2){//if at least 1 camera available
					overspeed.push_back(i);
					ans1++;
					a[i].pl=pos2,a[i].pl=pos1;
					//f[i]+=1<<pos2;
					//f[i]+=1<<pos1;
				}
			}
			if(a[i].acc>0){
				int x=floor((double)(V+a[i].v)*(V-a[i].v)/(2*a[i].acc))+a[i].d+1;//where vi reaches maximum
				if(x>L) continue;//juegement
				int pos=sr[x];
				if(pos!=m+1){
					ans1++;
					////f[i]+=1<<pos;
					//f[i]+=1<<m;
					a[i].pr=m,a[i].pl=pos;//store cameras
				}
			}
		}
		//cout<<ans1<<" "
		if(ans1) cout<<ans1<<" "<<m-1<<"\n";
		else cout<<ans1<<" "<<m<<"\n";
//		while(ans){
//			if(ans&1) cnt++;
//			ans=ans>>1;
//		}
		//cout<<cnt<<"\n";
	}
	return 0;
}

