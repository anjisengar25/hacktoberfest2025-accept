#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& arr) {
    vector<int> ans;

    // traverse each element in the array
    for (int i = 0; i < arr.size(); i++) {
        int cnt = 0;

        // check if element is already added to result
        for (auto &it : ans) {
            if (arr[i] == it) {
                cnt++;
                break;
            }
        }

        // if already added, skip checking again
        if (cnt) continue;

        // check if current element appears 
        // again in the rest of the array
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]){
                cnt++;
                break;
            }
        }

        // if duplicate found, add to result
        if (cnt) ans.push_back(arr[i]);
    }

    return ans;
}

int main() {

    vector<int> arr = {2, 3, 1, 2, 3};
    vector<int> res = findDuplicates(arr);
    for (int ele : res) {
        cout << ele << ' ';
    }
    cout << endl;

    return 0;
}
