﻿#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

typedef long long LL;

struct Edge {
  int from, to, cap, flow, cost;
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[MAXN];
  int inq[MAXN];
  int d[MAXN];
  int p[MAXN];
  int a[MAXN];

  void init(int n) {
    this->n = n;
    for(int i = 1; i <= n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge{from, to, cap, 0, cost});
    edges.push_back(Edge{to, from, 0, 0, -cost});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BellmanFord(int s, int t, int& flow, LL& cost) {
    for(int i = 1; i <= n; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }
    if(d[t] == INF) return false;
    cost += (LL)d[t] * (LL)a[t];
    flow += a[t]; 
    int u = t;
    while(u != s) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
      u = edges[p[u]].from;      
    }
    return true;
  }

  LL MincostMaxflow(int s, int t, LL& cost) {
    int flow = 0; cost = 0;
    while (BellmanFord(s, t, flow, cost));
    return flow;
  }

};
