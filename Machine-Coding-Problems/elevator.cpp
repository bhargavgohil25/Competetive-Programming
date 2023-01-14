#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Elevator
{
	enum Direction
	{
		UP,
		DOWN
	};
	Direction direction;

	vector<int> requests = {}; // valid request array entered by the users (validity depends on the direction of the lift as well as valid floor number)
	int min_floor;					// Underground floor will be shown using negative value
	int max_floor;					// top most floor number, ground floor = 0
	int current_floor = 0;			// ground floor
	size_t passengers = 0;		// current number of passangers in the lift
	size_t capacity;			// total capacity of the lift

public:
	// constructor function for elevator object - builds the elevator your building needs
	Elevator(int min_floor, int max_floor, size_t capacity) :
		min_floor(min_floor), max_floor(max_floor), capacity(capacity)
	{}
	~Elevator() {}

	// starts the elevator after setting up the required parameters
	void start_elevator();

private:
	// functional components of the lift

	void set_request();					// takes the requested floor no by the passangers on every floor (from outside only - simplicity) and add them to requests array
	int check_request(int floor) const; // examine all the requested destination floor numbers entered by the passanges on every stoppage (floor)
	int is_valid_request(int floor);	// display invalid messages to the passanger and returns the issue number
	void set_direction(int floor);		// Used to set the direction of the lift for the first time a user requests a floor number from the ground floor
};

void Elevator::set_request()
{
	string dest_floors_str; // stores all floors request
	string dest_floor_str;	 // stores single floor in string
	int dest_floor;				 // stores single floor as integer

	size_t num_of_reqs = capacity - passengers;
	cout << "\n"
	     << num_of_reqs << " passengers can enter in the elevator right now\n";

	cout << "\nEnter \"GO\" if no one enters from the floor \nOr to exit from program if elevator is idle\n";

	cout << "\nEnter destination floor number.\n";

	getline(cin, dest_floors_str);
	stringstream sstream(dest_floors_str);

	// this will take floor number request in one line (space seperated) under the user enters enter key
	while (sstream >> dest_floor_str)
	{
		if (dest_floor_str == "GO" || dest_floor_str == "Go" || dest_floor_str == "go" || dest_floor_str == "gO")
		{
			return;
		}
		else
		{
			// convert destination floor string to int
			dest_floor = stoi(dest_floor_str);
			if (passengers < capacity)
			{
				int is_valid = is_valid_request(dest_floor);

				// if the request is the valid one
				if (is_valid == 0)
				{
					// the lift was empty before
					if (passengers == 0)
					{
						// set its direction based on the first request
						// for ex - if lift is currently at 4th floor and its empty, p1 enters -1 then it will only take those next requests which goes down and
						// if p1 enters 5 then the lift will go in the upward direction (assuming building has -2 min and 6 max floor)
						set_direction(dest_floor);
					}
					requests.push_back(dest_floor); // add this valid request floor in the requests array
					passengers++;					// Also increase the passanger count
				}
			}

			// if the lift gets full, it will discard all the other requests.
			else if (passengers == capacity)
			{
				cout << "Elevator full!! Cannot accept more requests\n";
				return;
			}
		}
	}
}

int Elevator::is_valid_request(int floor)
{
	int issue_num = check_request(floor);

	if (issue_num == 1)
	{
		cout << "Elevator is going UP.\n";
	}
	else if (issue_num == 2)
	{
		cout << "Elevator is going DOWN.\n";
	}
	else if (issue_num == 3)
	{
		cout << "This floor does not exist\n";
	}
	return issue_num;
}

int Elevator::check_request(int floor) const
{
	// if the lift is going up taking its passangers, and the new passenger wants to go down
	if (passengers != 0 && direction == UP && floor < current_floor)
	{
		return 1;
	}

	// if the lift is going down taking its passangers, and the new passange wants to go up
	else if (passengers != 0 && direction == DOWN && floor > current_floor)
	{
		return 2;
	}

	// if the passanger enters some invalid floor number
	else if (floor > max_floor || floor < min_floor)
	{
		return 3;
	}

	// if there is no passanger alreaedy in the lift or above cases does not apply
	else
	{
		return 0;
	}
}

void Elevator::set_direction(int floor)
{
	if (floor > current_floor)
	{
		direction = UP;
	}
	else if (floor < current_floor)
	{
		direction = DOWN;
	}
}

void Elevator::start_elevator()
{
	// Display the elevator details on the ground floor
	cout << "\nFLOOR : " << current_floor << "\tNumber of Occupants : " << passengers << "\n";

	// Entering requests for first time
	set_request();								 // get the requests
	sort(requests.begin(), requests.end()); // sort the requests in increasing order
	int next_floor;								 // stores the next floor to go based on the direction and request array

	// run the elevator until there is no request left
	while (!requests.empty())
	{
		// if the lift goes up, get the smallest floor request from the request array
		if (direction == UP)
		{
			next_floor = requests[0];
		}
		// otherwise get the largest floor request from the request array
		else if (direction == DOWN)
		{
			next_floor = requests[requests.size() - 1];
		}

		// this block of code will ensure that as soon as lift reaches a destination floor (next_floor),all the passangers who requested for the next_floor will leave the lift
		auto next_floor_req = find(requests.begin(), requests.end(), next_floor);
		while (next_floor_req != requests.end())
		{
			requests.erase(next_floor_req); // removing next floor's requests
			passengers--;
			next_floor_req = find(requests.begin(), requests.end(), next_floor);
		}

		// here we have reached our destination floor -> next_floor
		current_floor = next_floor;

		// Now, if the current floor is the topmost floor in the building, then the lift can no more go in the upward direction (as it was going earlier), so we have to change it's direction to down so that other waiting passenges who wanted to go downwards will request for their destination floor
		if (current_floor == max_floor)
		{
			direction = DOWN;
		}

		// same applies if the lift is standing at lowest floor of the building
		else if (current_floor == min_floor)
		{
			direction = UP;
		}

		// get the string versions of the direction enum type
		string dir;
		if (direction == UP)
		{
			dir = "UP";
		}
		else
		{
			dir = "DOWN";
		}

		// As we have reached our destination floor (next_floor), we need to again display the info about the lift
		// current floor the lift is waiting at
		// how many passangers are already there in the lift
		// which direction the lift will be moving to
		// total capacity
		// maximum and minimum floor the building have

		cout << "\n=======================================================\n"
		     "FLOOR : "
		     << current_floor
		     << "\tNumber of Occupants : " << passengers
		     << "\n\nDIRECTION : " << dir
		     << "\tTotal Capacity : " << capacity
		     << "\n\nMinimum floor number is " << min_floor
		     << "\tMaximum floor number is " << max_floor
		     << "\n\n=======================================================\n";

		// Since the lift is waiting for new passangers to get in, we will again get their request through our set_request method and sort it.
		set_request();
		sort(requests.begin(), requests.end());
	}
}

int main()
{
	string capacity_str, min_floor_num_str, max_floor_num_str;
	int min_floor_num, max_floor_num;
	size_t capacity;

	cout << "Enter minimum floor number, maximum floor number in the building\n";
	cin >> min_floor_num_str;
	cin >> max_floor_num_str;

	min_floor_num = stoi(min_floor_num_str);
	max_floor_num = stoi(max_floor_num_str);

	cout << "Enter capacity for the elevator\n";
	cin >> capacity_str;
	cin.ignore();
	stringstream capacity_stream(capacity_str);
	capacity_stream >> capacity;

	Elevator elevator(min_floor_num, max_floor_num, capacity);
	elevator.start_elevator();
}