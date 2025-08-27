#include <bits/stdc++.h>
using namespace std;

struct interval {
    int start;
    int end;
};

// Comparator to sort by end time
static bool comp(struct interval a, struct interval b) {
    return a.end < b.end;
}

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<interval> arr(n);

        // Fill struct array
        for (int i = 0; i < n; i++) {
            arr[i].start = intervals[i][0];
            arr[i].end   = intervals[i][1];
        }

        // Sort by end time
        sort(arr.begin(), arr.end(), comp);

        int count = 1; // at least one interval we can keep
        int limit = arr[0].end;

        for (int i = 1; i < n; i++) {
            if (arr[i].start >= limit) { 
                // non-overlapping, keep it
                count++;
                limit = arr[i].end;
            }
            // else: overlap → skip (remove this interval)
        }

        return n - count; // removals = total - kept
    }
};
