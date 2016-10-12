#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> zigZagSort(vector<int>);
int main() {

	vector<int> testArr = { 5,-1,-5,20,7,-23,5,2,-7};

	for (std::vector<int>::const_iterator i = testArr.begin(); i != testArr.end(); ++i)
		std::cout << *i << ' ';
	cout << endl << testArr[1] << endl;

	//cout << n / 2;
	vector<int> newArr = zigZagSort(testArr);

	for (std::vector<int>::const_iterator k = newArr.begin(); k != newArr.end(); ++k)
		std::cout << *k << ' ';
	
	return 0;
}


vector<int> zigZagSort(vector<int> inputVector)
{
	vector<int> returnVector;

	//Sort the inputVector so that we know where the highest and lowest values lie within the vector.
	//
	sort(inputVector.begin(), inputVector.end());

	//print out the sorted vector just to see what we have.
	for (std::vector<int>::const_iterator k = inputVector.begin(); k != inputVector.end(); ++k)
		std::cout << *k << ' ';
	cout << endl;

	int n = inputVector.size();
	returnVector.resize(n); //I was getting errors when I tried using indexes that lied outside of the vectors 
							//size, so we must make sure the size is the same as the input vector.

	//index counters for the high and low values of the input vector
	int front = 0;  //The smallest values will be at the front of the vector
	int end = n - 1; //while the largest values will have indexes near the end of the vector.
	//Right now, front and end correspond to the min and max values within the vector. 


	for (int i = 0; i < n-1; i+=2) //Increment i by two since we are inserting values into the return vector at indexes i and i+1
	{
		returnVector[i] = inputVector[end]; //insert the high value in the return vector before the low value
		returnVector[i + 1] = inputVector[front];
		front++; //increment the front index of the input vector to move to the next min value
		end--;	//decrement the end index of the input vector to move to the next max value
	}

	if(n%2!=0) //In the case that the vector has an odd number of elements, we add the last high value from the input vector.
	{
		returnVector[n-1] = inputVector[end];
	}
	return returnVector;
}
