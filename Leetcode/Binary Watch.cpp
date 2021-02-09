class Solution {
public:
    int bitCnt(int n){
        int count = 0;
        int mask = 1;
        for(int i=0;i<8;i++){
            if((n&mask)!=0){
                count++;
            }
            mask<<=1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int n) {
        vector<string>ans;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                if(bitCnt(h) + bitCnt(m) == n){
                    ans.push_back(to_string(h) + (m<10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return ans;
    }
};