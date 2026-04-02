#include <iostream>
#include <vector>
using namespace std;

void powerSet(string &s, int index, string current, vector<string>& result) {
    // Base case
    if (index == s.length()) {
        result.push_back(current);
        return;
    }

    // Exclude current character
    powerSet(s, index + 1, current, result);

    // Include current character
    powerSet(s, index + 1, current + s[index], result);
}

int main() {
    string s = "abcd";
    vector<string> result;

    powerSet(s, 0, "", result);

    cout << "All subsets:\n";
    for (string x : result)
        cout << x << endl;

    return 0;
}
