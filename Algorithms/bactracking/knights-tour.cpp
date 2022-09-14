class Solution {
public:
		/*
		Problem Statement : 

		Given a N*N board with the Knight placed on the first block of an empty board. 
		Moving according to the rules of chess knight must visit each square exactly once. 
		Print the order of each cell in which they are visited.

		Input : 
		N = 8
		Output:
		0  59  38  33  30  17   8  63
		37  34  31  60   9  62  29  16
		58   1  36  39  32  27  18   7
		35  48  41  26  61  10  15  28
		42  57   2  49  40  23   6  19
		47  50  45  54  25  20  11  14
		56  43  52   3  22  13  24   5
		51  46  55  44  53   4  21  12
		
		Algorithm for Knight's Tour:
		If all squares are visited 
    	print the solution
		Else
	   a) Add one of the next moves to solution vector and recursively 
	   check if this move leads to a solution. (A Knight can make maximum 
	   eight moves. We choose one of the 8 moves in this step).
	   b) If the move chosen in the above step doesn't lead to a solution
	   then remove this move from the solution vector and try other 
	   alternative moves.
	   c) If none of the alternatives work then return false (Returning false 
	   will remove the previously added item in recursion and if false is 
	   returned by the initial call of recursion then "no solution exists" )

		*/
	vector<int> xMove = { 2, 2, -1, -2, -2, -1, 1, 2 };
	vector<int> yMove = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int n;

	bool isSafe(int x, int y, vector<vector<int>>& sol) {
		return (x >= 0 and x < n and y >= 0 and y < n and sol[x][y] == -1);
	}

	bool solveKnightTour(int x, int y, int move, vector<vector<int>>& sol) {
		int k, next_x, next_y;

		if(move == n * n) {
			return 1;
		}

		for(int k = 0; k < 8; k++) {

			next_x = x + xMove[k];
			next_y = y + yMove[k];

			if(isSafe(next_x, next_y, sol)) {

				sol[next_x][next_y] = move;

				if(solveKnightTour(next_x, next_y, move + 1, sol)) {
					return 1;
				}
				sol[next_x][next_y] = -1;
			}
		}

	}

	vector<vector<int>> solveKT(int N) {
		n = N;
		vector<vector<int>> sol(n, vector<int>(n, -1));

		sol[0][0] = 0;

		if(solveKnightTour(0, 0, 1, sol)) {
			return sol;
		}

		return -1;
	}

};