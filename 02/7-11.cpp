#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a.length() < b.length();
}

int main(){
    int n, i, j, k, l, m, mina, minb, minWPL = 0, wpl;
    cin >> n;
    string c, code[n];
    bool ishuf;
    map<string, int> f;
    priority_queue<int, vector<int>, greater<int>> q;

    for(i = 0; i < n; i++){
        cin >> c >> m;
        q.push(m);
        f[c] = m;
    }
    // Calculator WPL
    while(q.size() >= 2){
        mina = q.top();
        q.pop();
        minb = q.top();
        q.pop();
        minWPL += (mina + minb);
        q.push(mina + minb);
    }
    // Check
    cin >> m;
    for(i = 0; i < m; i++){
        for(j = 0, wpl = 0; j < n; j++){
            cin >> c >> code[j];
            wpl += (f[c] * code[j].length());
        }
        if(minWPL != wpl){
            cout << "No" << endl;
        }else{
            ishuf = true;
            sort(code, code + n, cmp);
            for(k = 0; k < n; k++){
                for(l = k + 1; l < n; l++){
                    if(code[k] == code[l].substr(0, code[k].length())){
                        ishuf = false;
                        break;
                    }
                }
                if(ishuf == false){
                    break;
                }
            }
            if(ishuf){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}