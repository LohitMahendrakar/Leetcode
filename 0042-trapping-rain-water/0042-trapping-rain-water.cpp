class Solution {
public:
    int trap(vector<int>& a) { //a ==heights array
        int ans = 0;

        for(int i=1; i<a.size()-1; i++){

            int lb = a[i]; // lb = left boundary
            for(int j=0; j<=i-1; j++){
                if(a[j] > lb) lb = a[j];
            }

            int rb = a[i]; // rb = right boundary
            for(int j=i+1; j<a.size(); j++){
                if(a[j] > rb) rb = a[j];
            }

            int wl = min(lb, rb);  // wl = water level
            int tw = wl - a[i];
            ans += tw;
        }

        return ans;
    }
};