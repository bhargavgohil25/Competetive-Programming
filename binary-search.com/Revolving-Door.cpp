/* You are given a list of list of integers requests. requests[i] contains [time, direction] meaning at time time, a person arrived at the door and either wanted to go in (1) or go out (0).

Given that there's only one door and it takes one time unit to use the door, we have the following rules to resolve conflicts:

The door starts with in position and then is set to the position used by the last person.
If there's only one person at the door at given time, they can use the door.
When two or more people want to go in, earliest person goes first and then the direction previously used holds precedence.
If no one uses the door for one time unit, it reverts back to the starting in position.
Return a sorted list of lists where each element contains [time, direction], meaning at time, a person either went in or out.

Constraints

0 ≤ n ≤ 100,000 where n is the length of requests
Example 1
Input
requests = [
    [1, 0],
    [2, 1],
    [5, 0],
    [5, 1],
    [2, 0]
]
Output
[
    [1, 0],
    [2, 0],
    [3, 1],
    [5, 1],
    [6, 0]
]
Explanation
The door starts as in

At time 1, there's only one person so they can go out. Door becomes out.
At time 2, there's two people but the person going out has priority so they go out.
At time 3, the person looking to go in can now go in.
At time 5, there's two people but the person going in has priority so they go out.
At time 6, the last person can go out. */

vector<vector<int>> solve(vector<vector<int>>& req) {
    
    // create two priority queue for IN and OUT directions

    priority_queue<int, vector<int>, greater<int>> inq;
    priority_queue<int, vector<int>, greater<int>> ouq;

    vector<vector<int>> ans;

    for(int i = req.size() - 1; i >= 0; i--){
        if(req[i][1] == 0){
            ouq.push(req[i][0]);
        }else{
            inq.push(req[i][0]);
        }
    }

    int time = -1;
    int door = 1;

    for(int i = 0; i < req.size(); i++){

        if(inq.size() == 0 || ouq.size() != 0 && ouq.top() < inq.top()){
            int top = ouq.top();
            time = max(time + 1, top);
            ouq.pop();
            ans.push_back({time, 0});
            door = 0;
            // break;
        }else if(ouq.size() == 0 || inq.top() < ouq.top()){
            int top = inq.top();
            time = max(time + 1, top);
            inq.pop();
            ans.push_back({time, 1});
            door = 1;
        }else{
            // means that if the door is not used continuously it will change it to default i.e door  = 1
            if(inq.top() - time > 1){
                door = 1;
            }

            if(door == 1){
                int top = inq.top();
                time = max(time + 1, top);
                inq.pop();
                ans.push_back({time, 1});
            } else{
                int top = ouq.top();
                time = max(time + 1, top);
                ouq.pop();
                ans.push_back({time, 0});
            }
        }
    }
    return ans;

}