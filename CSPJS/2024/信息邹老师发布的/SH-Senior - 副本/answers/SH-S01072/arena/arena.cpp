#include<bits/stdc++.h>
using namespace std;
int T,n,m,ap[140000],c[100005],d[18][70000],a[140000],x[4],K,k,f[140000],A[100005];
bool vst[140000],po[140000];
string s;

int toK(int x){
	int i=0,j=18;
	while(i<j){
		int mid=(i+j)/2;
		if(pow(2,mid)<x)
			i=mid+1;
		else if(pow(2,mid)==x)	
			return mid;
		else
			j=mid;
	}
	return (i+j)/2;
}

void deal(){
	bool vst1[140000]={0};
	int lz=0;
	for(int i=1;i<=pow(2,k);i++){
		if(vst1[f[i]])
			return;
		else
			vst1[f[i]]=1;
	}
//	cout<<endl;
//	for(int i=1;i<=pow(2,k);i++){
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
	for(int i=k;i>=1;i--){ // kÂÖ 
//		cout<<"di"<<k-i+1<<"lun"<<endl; 
		for(int j=1;j<=pow(2,i);j+=2){
			if(d[k-i+1][j/2+1]){
				lz=max(f[j],f[j+1]);
//				cout<<"lz:"<<lz<<" shili:"<<a[lz]<<endl;
				if(a[lz]==-1){
//					cout<<"buqueding,jinji:"<<f[j]<<endl;
					f[j/2+1]=f[j];
				}
				else{
					if(a[lz]>=k-i+1)
						f[j/2+1]=lz;
					else
						f[j/2+1]=min(f[j],f[j+1]);
//					cout<<"jinji:"<<f[j/2+1]<<endl;
				}
			} 
			else{
				lz=min(f[j],f[j+1]);
//				cout<<"lz:"<<lz<<" shili:"<<a[lz]<<endl;
				if(a[lz]==-1){
//					cout<<"buqueding,jinji:"<<f[j]<<endl;
					f[j/2+1]=f[j];
				}
				else{
					if(a[lz]>=k-i+1)
						f[j/2+1]=lz;
					else
						f[j/2+1]=min(f[j],f[j+1]);
//					cout<<"jinji:"<<f[j/2+1]<<endl;
				}
			} 
		}
	}
	po[f[1]]++;
//	for(int i=1;i<=pow(2,k);i++)
//		cout<<po[i]<<" ";
//	cout<<endl;
}

void dfs(int x){
	if(x==pow(2,k)+1){
		deal();
		return;
	}
	for(int i=1;i<=pow(2,k);i++){
		if(!vst[i]){
			vst[i]=1;
			f[x]=i;
			dfs(x+1);
			vst[i]=0;
		}
	}
	return;
}

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	K=toK(n);
	for(int i=1;i<=n;i++)
		cin>>ap[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	for(int i=1;i<=K;i++){
		cin>>s;
		for(int j=0;j<s.size();j++)
			d[i][j+1]=s[j];
	}
	cin>>T;
	for(int ti=1;ti<=T;ti++){
		for(int i=0;i<4;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++){
			a[i]=ap[i]^x[i%4];
//			cout<<a[i]<<" ";
		}
		for(int i=1;i<=m;i++){
			if(c[i]==1)
				A[i]=1;
			else{
				k=toK(c[i]);
//				cout<<"k:"<<k<<endl;
				
				for(int j=c[i]+1;j<=pow(2,k);j++)
					a[j]=-1;
				for(int j=1;j<=pow(2,k);j++){
					vst[j]=0;
					po[j]=0;
				}
				dfs(1);
				for(int j=1;j<=pow(2,k);j++){
//					cout<<po[j]<<" ";
					if(po[j])
						A[i]+=j;
				}
			}
		}
		int ans=A[1];
		for(int i=2;i<=m;i++)
			ans^=(i*A[i]);
		cout<<ans<<endl;
	}
	return 0;
}
