#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> p;

int INF = 1e9;
int N, M, X, s, e, t;
bool arr[1010][1010];
bool visited[1010][1010][2];
deque<pair<p, pair<bool, int> > > q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for(int i = 0; i<N; i++) {
    for (int j = 0; j < M; j++) {
      char x;
      cin >> x;
      if (x == '1')
        arr[i][j] = true;
    }
  }
  pair<p, pair<bool, int> > t = make_pair(make_pair(0, 0), make_pair(false, 1));
  q.push_back(t);
  int res = -1;
  while (!q.empty())
  {
    pair<p, pair<bool, int> > curr = q.front();
    q.pop_front();
    p curp = curr.first;
    bool f = curr.second.first;
    int dist = curr.second.second;
    if(visited[curp.first][curp.second][f ? 1 : 0])
      continue;
    visited[curp.first][curp.second][f ? 1 : 0] = true;
    if (curp.first == N - 1 && curp.second == M - 1)
    {
      res = dist;
      break;
    }
    for (int i = 0; i < 4; i++)
    {
      int x = curp.first + dx[i];
      int y = curp.second + dy[i];
      if (x < 0 || x >= N || y < 0 || y >= M || arr[x][y]) continue;
      q.push_back(make_pair(make_pair(x, y), make_pair(f, dist + 1)));
    }
    if(f)
      continue;
    for (int i = 0; i < 4; i++)
    {
      int x = curp.first + dx[i] * 2;
      int xx = curp.first + dx[i];
      int y = curp.second + dy[i] * 2;
      int yy = curp.second + dy[i];
      if (x < 0 || x >= N || y < 0 || y >= M || !arr[xx][yy] || arr[x][y]) continue;
      q.push_back(make_pair(make_pair(x, y), make_pair(true, dist + 2)));
    }
  }

  cout << res;

  return 0;
}