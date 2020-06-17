#include <iostream>
#include <unistd.h> // needed for usleep
// we use usleep to simulate a task

#include "loadingBar.h"

using namespace std;

int main(int argc, char const *argv[]){
	
	loadingBar downloadLoadingBar("Downloading, please wait...", 128); // create a loadingBar with 128 states possibles (default to 100)

	int i;
	// here we increase the loadingBar state 128 times
	for (i=0; i<128; i++){
		usleep(100000);
		cout << downloadLoadingBar.increase(1);// use increase whe you want to increase the state (default to 1)
		fflush(stdout); // necessary for printing immediatly
	}

	for (i=0; i<64; i++){
		usleep(100000);
		cout << downloadLoadingBar.decrease(); /* equivalent to : cout << downloadLoadingBar.decrease(1); */
		fflush(stdout);
	}

	for (i=0; i<16; i++){
		usleep(100000);
		cout << downloadLoadingBar.increase(4);
		fflush(stdout);
	}

	cout << endl;

	for (i=0; i<50; i++){
		usleep(100000);
		cout << downloadLoadingBar.getState(); // use getState when there is no state update but you want to refresh the output
		fflush(stdout);
	}

	cout << endl;

	return 0;
}
