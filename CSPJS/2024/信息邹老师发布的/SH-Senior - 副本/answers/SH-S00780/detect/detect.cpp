#include<bits/stdc++.h>
using namespace std;
#define int long long
/*given n intervals, calculate how many interval contains (sum), and the least sum needed.(union-find?)*/
int n,m,L,V,l[100010],r[100010];//[l,r]
int su[1000010],pos[100010],nums[70],ncnt;
				map<int,int>M;
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		int flg=0,tot=0;
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		memset(su,0,sizeof su);
		memset(pos,0,sizeof pos);
		for(int i=1;i<=n;i++){
			int d,v,a;
			scanf("%d%d%d",&d,&v,&a);
			if(a==0){
				l[i]=max(0ll,d),r[i]=L;
				if(v<=V)l[i]=r[i]=-1;
			}
			else if(a>0){
				if(v>V)l[i]=d,r[i]=L;
				else r[i]=L,l[i]=max(((V*V-v*v)/(2ll*a)+1),0ll)+d;
				if(l[i]>L)r[i]=l[i]=-1;
			}
			else if(a<0){
				if(v>V)l[i]=d,r[i]=min(L,d+(((V*V-v*v)%(2ll*a)==0)?((V*V-v*v)/(2ll*a)-1):((V*V-v*v)/(2ll*a))));
				else r[i]=l[i]=-1;
				flg=1;
			}
			//cout<<'a'<<l[i]<<' '<<r[i]<<endl;
		}for(int i=1;i<=m;i++){
			scanf("%d",pos+i);
			su[pos[i]]=1;
		}for(int i=1;i<=L;i++)su[i]+=su[i-1];
		for(int i=1;i<=n;i++){
			if(l[i]==-1)continue;
			if(l[i]==0){
				if(su[r[i]])tot++;
			}else if(su[r[i]]-su[l[i]-1])tot++;
		}cout<<tot<<' ';
		if(!flg){
			cout<<m-1<<endl;
		}else{
			if(m<=20){
				int ans=m;
				M.clear();
				memset(nums,0,sizeof nums);
				ncnt=0;
				for(int i=1;i<=n;i++){
					if(l[i]==-1)continue;
					if(M.find(l[i])==M.end()){
						M[l[i]]=1;nums[++ncnt]=l[i];
					}
					if(M.find(r[i])==M.end()){
						M[r[i]]=1;nums[++ncnt]=r[i];
					}
				}
				for(int i=1;i<=m;i++){
					if(M.find(pos[i])==M.end()){
						M[pos[i]]=1;nums[++ncnt]=pos[i];
					}
				}
				sort(nums+1,nums+ncnt+1);M.clear();
				for(int i=1;i<=ncnt;i++){
					M[nums[i]]=i;
				}for(int i=1;i<=n;i++){
					if(l[i]!=-1){
						l[i]=M[l[i]];
						r[i]=M[r[i]];
					}
				}L=ncnt;
				for(int i=1;i<=m;i++)pos[i]=M[pos[i]];
//				cout<<"\ndebug:"<<L;
//				for(int i=1;i<=n;i++)cout<<l[i]<<' '<<r[i]<<endl;
//				for(int i=1;i<=m;i++)cout<<pos[i]<<' ';
//				cout<<"eof\n";
				for(int i=0;i<(1<<m);i++){
					int cnt=0,popc=0;
					for(int k=0;k<=L;k++)su[k]=0;
					for(int k=0;k<m;k++){
						if(i&(1<<k))su[pos[k+1]]=1;
					}
					for(int k=1;k<=L;k++)su[k]+=su[k-1];
					for(int i=1;i<=n;i++){
						if(l[i]==-1)continue;
						if(l[i]==0){
							if(su[r[i]])cnt++;
						}else if(su[r[i]]-su[l[i]-1])cnt++;
					}
					int ii=i;
					while(ii){
						popc+=(ii&1);
						ii>>=1;
					}
					//if(i==148)cout<<"A"<<cnt<<endl;
					if(cnt==tot)ans=min(ans,popc);
				}
				cout<<(m-ans)<<endl;
			}
		}
	}
	return 0;
}

