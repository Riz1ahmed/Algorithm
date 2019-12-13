#include<bits/stdc++.h>
#define ll long long int
const ll M=1e9+7;
using namespace std;
vector<ll>v[100005];
ll ans,m;
void solve(ll p,ll mn,ll mx){
	//printf("%lld %lld %lld\n",p,mn,mx);
	if (p==m){
		ans=min(ans,mx-mn);
		return;
	}
	ll mx1=upper_bound(v[p].begin(),v[p].end(),mx)-v[p].begin()-1;
	if (mx1<0) mx1++;
	if (mn<=v[p][mx1] && v[p][mx1]<=mx){
		solve(p+1,mn,mx);
		return;
	}

	if (v[p][mx1]<mx) mx1++;
	ll mn1=upper_bound(v[p].begin(),v[p].end(),mn)-v[p].begin()-1;
	if (mn1<0) mn1++;
	//printf("mn1=%lld mx1=%lld\n",mn1,mx1);

	if (mx1>=v[p].size()) solve(p+1,v[p][mn1],mx);
	else{
		if (mn<v[p][mn1] || v[p][mx1]-mx < mn-v[p][mn1])
			 solve(p+1,mn,v[p][mx1]);
		else if(v[p][mx1]-mx == mn-v[p][mn1]){
			solve(p+1,v[p][mn1],mx);
			solve(p+1,mn,v[p][mx1]);
		}
		else solve(p+1,v[p][mn1],mx);
	}
	return;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll t,n,i,x;
	cin>>t;
	while(cin>>n>>m){
		for (i=0; i<m; i++)v[i].clear();
		for (i=0; i<n; i++){
			cin>>x;
			v[i%m].push_back(x);
		}
		for (i=0; i<m; i++)
			sort(v[i].begin(),v[i].end());
//		for (i=0; i<m; i++){
//			for (int j=0; j<v[i].size(); j++)
//				printf("%lld ",v[i][j]);
//			puts("");
//		}
		ans=1e9;
		for (i=0; i<v[0].size(); i++)
			solve(1,v[0][i],v[0][i]);
		cout<<ans<<endl;
	}
	return 0;
}
