class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
         map<int,int> m1;
        vector<int> vec;
        for(int i:nums)
        {
            if(i%2==0)
            m1[i]++;
        }
        int max=0;
        if(m1.size()==0){
            return -1;
        }
        else{
           for(auto i:m1){
            if(i.second>max){
                max=i.second;
            }
           }
        }
        for(auto i:m1){
            if(max==i.second){
                vec.push_back(i.first);
            }
        }
        return vec[0];
    }
};