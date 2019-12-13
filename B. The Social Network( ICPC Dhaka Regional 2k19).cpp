#include<bits/stdc++.h>
using namespace std;
const int mx=1e5;
int par[mx+6],srt[mx+5],cnt;
int findP(int p){
	return par[p]==p? p: par[p]=findP(par[p]);
}
int main(){
	ios_base::sync_with_stdio(false);
	int t,n,q,u,v,tp,p,l,r,cs=1,i;
	cin>>t;
	while(t--){
		cout<<"Case "<<cs++<<":\n";
		cin>>n>>q;
		vector<int> vc[n+5];
		for (i=0; i<=n; i++) par[i]=i, srt[i]=0;
		while(q--){
			cin>>tp;
			if (!tp){
				cin>>u>>v;
				int pu=findP(u), pv=findP(v);
				if (pu==pv) continue;
				if (vc[pv].size()<vc[pu].size()) swap(pv,pu);
				for (auto it:vc[pu]) vc[pv].push_back(it);
				par[pu]=pv;
				srt[pv]=0;
			}else if (tp==1){
				cin>>u>>p;
				int pu=findP(u);
				vc[pu].push_back(p);
				srt[pu]=0;
			}else{
				cin>>u>>l>>r;
				int pu=findP(u),c=0;
				if (!srt[pu]) sort(vc[pu].begin(),vc[pu].end()), srt[pu]=1;
				int low=lower_bound(vc[pu].begin(),vc[pu].end(),l)-vc[pu].begin();
				int up =upper_bound(vc[pu].begin(),vc[pu].end(),r)-vc[pu].begin();
				cout<<up-low<<endl;
			}
		}
	}
	return 0;
}
