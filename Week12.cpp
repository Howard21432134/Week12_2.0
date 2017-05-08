#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<string, vector<string> > suffix;
vector<pair<int, string> > MAX;

void construct(int n, const string &strs) {
  if (strs.length() < n) return;
  else suffix[strs.substr(strs.length() - n, n)].push_back(strs);
}

int main() {
  string fileName;
  string line;
  int n;
  cout << "Dictionary file name?" << endl;
  getline(cin, fileName);
  ifstream fin(fileName.c_str());
  cout << "Please enter n!" << endl;
  cin >> n;
  while (fin >> line) {
    construct(n, line);
  }
  // requirement 1
  map<string, vector<string> >::iterator iter = suffix.begin();
  while (iter != suffix.end()) {
    MAX.push_back(make_pair(iter->second.size(), iter->first));
    ++iter;
  }
  sort(MAX.begin(), MAX.end());
  for (int cnt = 1, i = MAX.size() - 1; i >= MAX.size() - 10 && i >= 0;
       i--, cnt++) {
    cout << "The " << cnt << "th suffix is " << MAX[i].second << endl
         << "it is included by " << MAX[i].first << " words :" << endl;
    vector<string> &tmp = suffix[MAX[i].second];
    for (int i = 0; i < tmp.size(); i++)
      cout << tmp[i] << endl;
    cout << endl;
  }
  // requirement 2
  cout << "Please enter a suffix whose length is " << n << " !" << endl;
  cin >> line;
  cout << "The suffix you input is included by " << suffix[line].size()
       << " words :" << endl;
  vector<string> &tmp = suffix[line];
  for (int i = 0; i < tmp.size(); i++)
    cout << tmp[i] << endl;
  cout << endl;
  return 0;
}
