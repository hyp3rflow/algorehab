#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> p;

int INF = 1e9;
int N, M, X, s, e, t;
vector<bool> paren;
vector<vector<char> > av;

string res;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  av.resize(1);

  string x;
  cin >> x;
  for (int i = 0; i < x.size(); i++) {
    char curr = x[i];
    switch (curr)
    {
    case '(':
      av.push_back(vector<char>());
      break;
    case ')':
    {
      vector<char> c = av.back();
      av.pop_back();
      for (int j = c.size() - 1; j >= 0; j--)
      {
        res.push_back(c[j]);
      }
      break;
      }
      case '+':
      case '-': {
        vector<char> c = av.back();
        if (!c.empty())
        {
          for (int j = c.size() - 1; j >= 0; j--) {
            res.push_back(c[j]);
          }
          av.back().clear();
        }
        av.back().push_back(curr);
        break;
      }
      case '/':
      case '*': {
        vector<char> c = av.back();
        if (!c.empty())
        {
          for (int j = c.size() - 1; j >= 0; j--) {
            if (c[j] != '*' && c[j] != '/')
              break;
            res.push_back(c[j]);
            av.back().pop_back();
          }
        }
        av.back().push_back(curr);
        break;
      }
      default:
        res.push_back(curr);
        break;
      }
  }

  vector<char> c = av.back();
  if (!c.empty())
  {
    for (int j = c.size() - 1; j >= 0; j--) {
      res.push_back(c[j]);
    }
  }

  cout << res;

  return 0;
}