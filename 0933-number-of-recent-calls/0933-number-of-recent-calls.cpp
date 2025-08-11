#include <queue>
using namespace std;

class RecentCounter {
    private:
        queue<int> q; // To store request times

    public:
        RecentCounter() {
            // Queue automatically initialized as empty
        }

        int ping(int t) {
            q.push(t); // Add the new request

            // Remove requests older than t - 3000
            while (!q.empty() && q.front() < t - 3000) {
                q.pop();
            }

            return q.size(); // Number of requests in range
        }
};
