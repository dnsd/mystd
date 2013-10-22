#include <iostream>
#include <cmath>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

double get_time(void) 
{
    //-現在時刻を取得-//
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

void sleep_const_freq(double cycle_start_time, double cycle_end_time, double freq)
{
    //-周期を合わせるために待機-//
    usleep(freq * 1000000 - (cycle_end_time - cycle_start_time) * 1000000);
}
