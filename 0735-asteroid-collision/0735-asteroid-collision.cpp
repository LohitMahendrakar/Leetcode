#include <vector>
#include <list>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) { // arr == asteroids
        list<int> li;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                // Positive asteroid → always push
                li.push_back(arr[i]);
            } else {
                // Negative asteroid
                while (!li.empty() && li.back() > 0 && li.back() < abs(arr[i])) {
                    li.pop_back();
                }

                if (!li.empty() && li.back() == abs(arr[i])) {
                    // Same size → both explode
                    li.pop_back();
                }
                else if (li.empty() || li.back() < 0) {
                    // No collision or last asteroid moving left
                    li.push_back(arr[i]);
                }
            }
        }

        // Convert list to vector for return
        return vector<int>(li.begin(), li.end());
    }
};
