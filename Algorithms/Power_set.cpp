// Algorithm For The Power Set;

// 1) Get the size of the power set:
// 	power_set_size = pow(2, set_size)

// 2) Loop for the counter from 0 to pow_set_size:
// 	a) Loop for i = 0 to set_size
// 		i)If ith bit in the counter is set
// 			Print ith element from set for this subset

// 	b) Print seperator for subsets i.e, newline 

// Left Shifting: (x << i) simply means that (x * 2^i)
				  // or in bitwise the bits are shifted to the left

#include <iostream> 
#include <math.h> 
using namespace std; 

class gfg{
	public:
	void printPowerSet(char *set,int set_size){
		unsigned int pow_set_size = pow(2, set_size);
		int counter,j;
		for(counter = 0;counter<pow_set_size;counter++){
			for(j=0;j<set_size;j++){
				if(counter & (1 << j)){
					cout << set[j];
				}
			}
			cout << endl;
		}
	} 
}

int main(){
	gfg g;
	char set[] = {'a','b','c'};
	g.printPowerSet(set,3);
	return 0;
}

