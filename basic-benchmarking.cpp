// Basic Benchmarking lab exercise
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <chrono>
#include <iostream>
#include <thread>
#include <algorithm>

// Import things we need from the standard library
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;

// Define the alias "the_clock" for the clock type we're going to use.
// (You can change this to make the code below use a different clock.)
typedef std::chrono::steady_clock the_clock;


// The size of the array
#define WIDTH 5000
#define HEIGHT 10000
#define TIMES 11;

float array[HEIGHT][WIDTH];
long long theTimes[11];


int main(int argc, char *argv[])
{
	// Fill the array with data
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			array[y][x] = float(x + y);
		}
	}

	for (int i = 0; i < 11; ++i)
	{
		// Start timing
		the_clock::time_point start = the_clock::now();

		// Do something that takes some time
		/*sleep_for(milliseconds(300));*/

		float sum = 0; 
		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				sum += array[y][x];
			}
		}

		//cout << sum << endl;

		// Stop timing
		the_clock::time_point end = the_clock::now();

		// Compute the difference between the two times in milliseconds
		auto time_taken = duration_cast<milliseconds>(end - start).count();
		theTimes[i] = time_taken;

		
	}

	std::sort(theTimes, theTimes + 11);
	//cout << "It took on average " << theTimes[6] << " ms.\n";
	for (int i = 0; i < 11; ++i)
	{
		cout << "It took on average " << theTimes[i] << " ms.\n";
	}

	return 0;
}