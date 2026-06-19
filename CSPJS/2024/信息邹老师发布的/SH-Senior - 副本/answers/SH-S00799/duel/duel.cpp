#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i = a;i < b;i++)

const int N = 1e5+50;
int i,j,k;

int R[N],n,turn[N],att[N];
long long cnt;
void ex(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
	return;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	f(i,0,n)scanf("%d",&R[i]);
	cnt = n;
	
	for(int mid = n/2;mid >= 1;mid /= 2){
		f(j,0,mid){
			f(k,1,n/mid){
				int u = k;
				while(u>0 && R[u*mid+j] < R[(u-1)*mid+j]){
					ex(R[u*mid+j],R[(u-1)*mid+j]);
					u--;
				}
			}
		}
	}
	f(i,0,n){
		turn[i] = i+1;
	}
	for(int ju = cnt+1;ju != cnt;){ju = cnt;
		for(i = 0;i < n;i = turn[i]){
			if(R[i] == 0)continue;
			while(R[turn[i]] == 0 && turn[i] < n)turn[i] = turn[turn[i]];
			if(R[i]<R[turn[i]] && att[turn[i]] == 0){
				cnt--;
				R[i] = 0;
				int u = turn[i];
				while(u<n && R[u] == R[u+1] && att[u+1] == 0)u++;
				if(att[u] >= 1)u--;
				att[u]+=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
