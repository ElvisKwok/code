#include <iostream>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>
using namespace std;

long getCurrentTime() {
	struct timeval tv;		// 可获取毫秒 usec
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


int main() {
    time_t start = time(NULL);
    sleep(2);
    time_t end = time(NULL);
    //cout << (end-start)/60 << " minutes elapsed" << endl;
    cout << (end-start) << " seconds elapsed" << endl;

	cout << getCurrentTime() << endl;
    sleep(2);
	cout << getCurrentTime() << endl;

	clock_t c1 = clock();
	sleep(2);
	clock_t c2 = clock();
	double cost = (c2 - c1) * 1.0 / CLOCKS_PER_SEC;
	cout << cost << endl;
    return 0;
}
