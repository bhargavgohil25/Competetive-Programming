

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	int set_size = nums.size();
    	vector<strings> list;
    	vector<vector<>>
    	int counter,j;
    	for(counter=0;counter<pow(2,set_size);counter++){
    		string subset = "";
    		for(j=0;j<set_size;j++){
    			if(counter & (1 << j)){
    				subset += to_string(nums[i]) + "|";
    			}
    		}
    		if(find(list.begin(),list.end(),subset) == list.end()){
    			list.push_back(subset);
    		}
    	}
    	for(string subset : list){
    		vector<string> a = spilt(subset, '|');
    		for(string str : arr){

    		}
    	}
    }
};