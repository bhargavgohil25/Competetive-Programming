/* You are given a string s containing "1", "2", "3" and "?". Given that you can replace any “?” with "1", "2" or "3", return the smallest number you can make as a string such that no two adjacent digits are the same.

Constraints

n ≤ 100,000 where n is the length of s
Example 1
Input
s = "3?2??"
Output
"31212" */


int findMissing(vector<int> m){
    sort(m.begin(), m.end());
    int res;
    for(int i = 1; i <= 3; i++){
        if(m[i-1] != i){
            res = i;
            break;
        }
    }
    return res;
}

string solve(string s) {
    int n = s.length();

    if(s[0] == '?'){
        if(s[1] == '?'){
            s[0] = '1';
        }else{
            vector<int> m;
            m.push_back(s[1] - '0');
            int missing = findMissing(m);
            char add = missing + '0';
            s[0] = add;
        }
    }

    for(int i = 1; i < n - 1; i++){
        if(s[i] == '?'){
            if(s[i - 1] != '?' and s[i + 1] != '?'){
              // find the smallest missing number
              vector<int> m;
              m.push_back(s[i - 1] - '0');
              m.push_back(s[i + 1] - '0');
              int missing = findMissing(m);
              char add = missing + '0';
              s[i] = add;
            }else if(s[i - 1] != '?' and s[i + 1] == '?'){
              vector<int> m;
              m.push_back(s[i - 1] - '0');
              int missing = findMissing(m);
              char add = missing + '0';
              s[i] = add;
            }
        }
    }

    if(s[n - 1] == '?'){
        vector<int> m;
        m.push_back(s[n - 2] - '0');
        int missing = findMissing(m);
        char add = missing + '0';
        s[n - 1] = add;
    }

    return s;
}