#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> p;

int INF = 1e9;
int N, M, X, s, e, t, res;
vector<vector<p> > tree;
bool visited[100010];
bool visited2[100010];
queue<p> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  tree.resize(N);
  for (int i = 0; i < N - 1; i++)
  {
    int x, y, t;
    cin >> x >> y >> t;
    tree[x - 1].push_back(make_pair(y - 1, t));
    tree[y - 1].push_back(make_pair(x - 1, t));
  }

  p res = make_pair(0, 0);
  q.push(make_pair(0, 0));
  visited[0] = true;
  while (!q.empty())
  {
    p curr = q.front();
    q.pop();
    int node = curr.first;
    int dist = curr.second;
    if (res.second < dist)
    {
      res = make_pair(node, dist);
    }
    for (int i = 0; i < tree[node].size(); i++) {
      if (!visited[tree[node][i].first]) {
        q.push(make_pair(tree[node][i].first, dist + tree[node][i].second));
        visited[tree[node][i].first] = true;
      }
    }
  }

  p res2 = make_pair(res.first, 0);
  q.push(make_pair(res.first, 0));
  visited2[res.first] = true;
  while (!q.empty())
  {
    p curr = q.front();
    q.pop();
    int node = curr.first;
    int dist = curr.second;
    if (res2.second < dist)
    {
      res2 = make_pair(node, dist);
    }
    for (int i = 0; i < tree[node].size(); i++) {
      if (!visited2[tree[node][i].first]) {
        q.push(make_pair(tree[node][i].first, dist + tree[node][i].second));
        visited2[tree[node][i].first] = true;
      }
    }
  }

  cout << res2.second;

  return 0;
}