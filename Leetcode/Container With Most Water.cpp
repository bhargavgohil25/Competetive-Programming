class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size()-1;
        int maxi = -1;
        
        while(l < r){
            if(h[l] > h[r]){
                maxi = max(maxi,h[r]*(r-l));
                r--;
            }else{
                maxi = max(maxi,h[l]*(r-l));
                l++;
            }
        }
        return maxi;
    }
};