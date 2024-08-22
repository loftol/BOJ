
#include <bits/extc++.h>
#define all(v) v.begin(), v.end()
#define zip(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
typedef long double ld;
using PP=pair<ll,pair<int,int>>;
using namespace __gnu_pbds;
template<class T> using PBDS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using multiPBDS = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll n_=1e5+100;
ll n,m,S,T;
ll H[n_];
vector<ll>v[n_];
ll get(ll x,ll y){
    return (x-y)*(x-y);
}
ll ans=1e18;
vector<ll>distS,distT;
void dijk(ll s,vector<ll>&dist){
    for(int i=0;i<=n;i++)dist[i]=1e18;
    std::priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,s});
    dist[s]=0;
    while(pq.size()){
        auto [a,b]=pq.top();pq.pop();
        if(dist[b]<a)continue;
        for(auto& nxt:v[b]){
            if(dist[nxt]>a+get(H[nxt],H[b])){
                dist[nxt]=a+get(H[nxt],H[b]);
                pq.push({dist[nxt],nxt});
            }
        }
    }
}

const ll inf = 1e18;
struct line{
	ll a, b;
	ll get(ll x){return a * x + b;}
};

struct node{
	ll lc, rc, l, r;
	line ln;
};
vector<node> Tree;
int t;  // Tree 노드 개수

void upd_line(int ix, line hi){
	ll l = Tree[ix].l, r = Tree[ix].r;
	ll m = (l + r) >> 1;

	line lw = Tree[ix].ln;
	if(lw.get(l) > hi.get(l)) swap(lw, hi);
	if(hi.get(r) >= lw.get(r)) {
		Tree[ix].ln = hi; return;
	}

	if(hi.get(m) >= lw.get(m)){
		Tree[ix].ln = hi;
		if(Tree[ix].rc == -1) {
			Tree[ix].rc = ++t;
			Tree.push_back({-1, -1, m + 1, r, {0, -inf}});  // to modify : 더미 선분
		}
		upd_line(Tree[ix].rc, lw);
	}
	else{
		Tree[ix].ln = lw;
		if(Tree[ix].lc == -1){
			Tree[ix].lc = ++t;
			Tree.push_back({-1, -1, l, m, {0, -inf}});   // to modify : 더미 선분
		}
		upd_line(Tree[ix].lc, hi);
	}
	return;
}

ll qry(int ix, ll x){
	if(ix == -1) return -inf;
	ll m = (Tree[ix].l + Tree[ix].r) >> 1;
	if(x <= m) return max(Tree[ix].ln.get(x), qry(Tree[ix].lc, x));
	else return max(Tree[ix].ln.get(x), qry(Tree[ix].rc, x));
}

void solve() {  
    cin>>n>>m>>S>>T;
    for(int i=1;i<=n;i++)cin>>H[i];
    while(m--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    distS.resize(n+1),distT.resize(n+1);
    dijk(S,distS),dijk(T,distT);
    ans=distS[T]*2;
    for(auto& nxt:v[S])ans=min(ans,distT[nxt]*2);
    for(auto& nxt:v[T])ans=min(ans,distS[nxt]*2);
    for(int i=1;i<=n;i++){
        Tree.push_back({-1, -1, -1, (ll)1e5+10, {0ll, -inf}});
        for(auto& nxt:v[i]){
            upd_line(0,{2*H[nxt],-H[nxt]*H[nxt]-2*distT[nxt]});
        }
        for(auto& nxt:v[i]){
            ll val=-qry(0,H[nxt])+H[nxt]*H[nxt]+2*distS[nxt];
            //cout<<i<<' '<<nxt<<' '<<val<<endl;
            ans=min(ans,val);
        }
        t=0;
        Tree.clear();
    }
    cout<<ans/2;
    if(ans%2)cout<<".5";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc=1; //cin>>tc;
    for(int i=1;i<=tc;i++) solve();
}
