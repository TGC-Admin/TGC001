#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i=0;i<(long long)(n);i++)
#define all(v) v.begin(),v.end()
using ll=long long;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll,ll>;
const ll INF=(1ll<<60);
template<class T> void chmin(T &a,T b){
    if(a>b){
        a=b;
    }
}
template<class T> void chmax(T &a,T b){
    if(a<b){
        a=b;
    }
}
struct edge{
    ll to;
	ll cost;
	edge(ll to,ll cost) : to(to),cost(cost) {};
};
struct graph{
    ll v;
    vector<vector<edge>> g;
    vector<ll> d,prev;
    graph(ll n){
        v=n;
        g.resize(v);
        d.resize(v,INF);
        prev.resize(v,-1);
    }
    void add_edge(ll s,ll t,ll cost){
        g[s].push_back({t,cost});
    }
    void dijkstra(ll s){
        rep(i,d.size()){
            d[i]=INF;
        }
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        d[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            ll x_dist,x_vertex;
            tie(x_dist,x_vertex)=pq.top();
            pq.pop();
            if(d[x_vertex]<x_dist) continue;
            for(auto edge:g[x_vertex]){
                if(d[x_vertex]+edge.cost<d[edge.to]){
                    d[edge.to]=d[x_vertex]+edge.cost;
                    prev[edge.to]=x_vertex;
                    pq.push({d[edge.to],edge.to});
                }
            }
        }
    }
};
int main(){
    ll n,t;
    cin >> n >> t;
    vector<vector<ll>> a(n,vector<ll>(n));
    ll mx=-INF;
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
            chmax(mx,a[i][j]);
        }
    }
    vector<ll> d;
    vector<pll> pd;
    rep(i,n){
        rep(j,n){
            d.push_back(mx-a[i][j]);
            if(i==0&&j==0) pd.push_back({mx-a[i][j],1});
            else pd.push_back({mx-a[i][j],0});
        }
    }
    sort(all(d));
    sort(all(pd));
    vector<ll> sum(d.size()+1,0);
    rep(i,d.size()) sum[i+1]=sum[i]+d[i];
    vector<bool> start(d.size(),false);
    ll h=d.size();
    rep(i,d.size()){
        if(pd[i].second==1) h=i;
    }
    rep(i,d.size()){
        if(i<=h) start[i]=true;
    }
    while(t--){
        ll k;
        cin >> k;
        ll ng=-1,ok=INF;
        while(1<abs(ng-ok)){
            ll mid=(ng+ok)/2;
            ll upp=upper_bound(all(d),mid)-d.begin();
            ll cost=d.size()-upp;
            if(start[upp]) cost=max(0ll,cost);
            cost+=(sum[d.size()]-sum[upp])-mid*(d.size()-upp);
            if(cost<=k) ok=mid;
            else ng=mid;
        }
        cout << ok << endl;
    }
}
