#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int ans,m;
void solve(int p,int mn,int mx){
	if (mx-mn>=ans) return;
	if (p==m){
		ans=min(ans,mx-mn);
		return;
	}
	for (int i=0; i<v[p].size(); i++){
		if (v[p][i]<mn) solve(p+1,v[p][i],mx);
		else if (v[p][i]>mx) solve(p+1,mn,v[p][i]);
		else solve(p+1,mn,mx);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t,n,i,x;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (i=0; i<m; i++)v[i].clear();
		for (i=0; i<n; i++){
			cin>>x;
			v[i%m].push_back(x);
		}
		ans=1e9;
		for (i=0; i<v[0].size(); i++)
			solve(1,v[0][i],v[0][i]);
		cout<<ans<<endl;
	}
	return 0;
}
