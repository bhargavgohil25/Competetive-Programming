class Solution {
public:
	/*
	- A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block 
		i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down. 

		In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination. 
		Note that this is a simple version of the typical Maze problem. 
		For example, a more complex version can be that the rat can move in 4 directions and a more complex version can be with a limited number of moves.
	
	*/
	vector<vector<int>> ans;

	bool solveMazeFunc(vector<vector<int>>& maze, int x, int y) {

		if(x == n - 1 and y == n - 1 and maze[x][y] == 1) {
			ans[x][y] = 1;
			return true;
		}

		if(isSafe(maze[x][y])) {

			if(ans[x][y] == 1) return false;

			ans[x][y] = 1;

			if(solveMazeFunc(maze, x + 1, y)) return true;

			if(solveMazeFunc(maze, x, y + 1)) return true;

			ans[x][y] = 0;

			return false;

		}

		return false;

	}

	vector<vector<int>> solveMaze(vector<vector<int>>& maze) {

		int n = maze.size();

		ans.resize(n, vector<int>(m, 0));

		if(solveMazeFunc(maze, 0, 0)) {
			return ans;
		}
		return -1;

	}


};
