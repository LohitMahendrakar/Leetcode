class Solution {
public:
    struct Job {
        int start, end, profit;
    };

    static bool cmp(Job &a, Job &b) {
        return a.end < b.end; // sort by end time
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for(int i=0; i<n; i++){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end(), cmp);

        vector<int> dp(n, 0); // dp[i] = max profit until job i
        dp[0] = jobs[0].profit;

        for(int i=1; i<n; i++){
            int include = jobs[i].profit;

            // Find the last non-conflicting job with binary search
            int l=0, r=i-1, idx=-1;
            while(l <= r){
                int mid = (l+r)/2;
                if(jobs[mid].end <= jobs[i].start){
                    idx = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }

            if(idx != -1) include += dp[idx];
            
            dp[i] = max(dp[i-1], include);
        }

        return dp[n-1];
    }
};
