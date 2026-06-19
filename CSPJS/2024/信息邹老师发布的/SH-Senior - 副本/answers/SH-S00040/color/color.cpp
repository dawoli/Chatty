#include<bits/stdc++.h>
using std::fstream;
using std::endl;
using std::cerr;
using std::max;

typedef long long ll;

// #define int ll

fstream fin("color.in",std::ios::in);
#define cin fin
fstream fout("color.out",std::ios::out);
//#define fout std::cout // for the time being

const int N=2e5+100,A=1e6+100;

int n,a[N];
int ssa[N]; // same sum answer
// if all paint red, the answer when n=k is sa[k]
ll ddp[N]; // if only the last difference color
ll diff[A];

void test() {
	cin>>n;
	for(int i=0;i<n+10;i++) a[i]=ssa[i]=ddp[i]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		diff[a[i]]=0;
	}
	for(int i=1;i<=n;i++) {
		ssa[i]=ssa[i-1];
		if(a[i]==a[i-1]) ssa[i]+=a[i];
	}
	ll ddiff=0;
	for(int i=1;i<=n+1;i++) {		
		// choice 2: paint diff, in [j,i-1]
	
		// do ddp decrease? obviously not. assert(ddp[i]>=ddp[i-1]);
		// what we have to do are two things:
		
		// No.1 find max ddp[j]-ssa[j]+a[j-1] if a[j-1]==a[i]
		ddp[i]=max(ddp[i],diff[a[i]]+ssa[i-1]);
		
		// No.2 find max ddp[j]-ssa[j]
		ddp[i]=max(ddp[i],ddiff+ssa[i-1]);
		
		// No.1 upd
		diff[a[i-1]]=max(diff[a[i-1]],ddp[i]-ssa[i]+a[i-1]);
		
		// No.2 upd
		ddiff=max(ddiff,ddp[i]-ssa[i]);
		
		if(0) {
			// far too slow
			ll some_var=0;
			for(int j=1;j<i;j++) { // find last same color
				ll ans=ddp[j]-ssa[j];
				// else continue; will lead to wa
				some_var=max(some_var,ans);
				if(a[i]==a[j-1]) some_var=max(some_var,ans+a[i]);
			}
			some_var+=ssa[i-1];
			assert(some_var==ddp[i]);
		}
	}
	fout<<ddp[n+1]<<endl;
}

signed main() {
	int t;
	cin>>t;
	assert(t);
	while(t--)
		test();
	
	return 0;
}
