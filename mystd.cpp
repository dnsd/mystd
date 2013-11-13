#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

using namespace std;

string get_localtime();
double get_time(void);
string IntToString(int number);
void sleep_const_freq(double cycle_start_time, double cycle_end_time, double freq);

string get_localtime()
{
    time_t timer;
    struct tm *t_st;
    string jst;

    time(&timer);

    t_st = localtime(&timer);

    jst += IntToString(t_st->tm_year+1900);
    jst += IntToString(t_st->tm_mon+1);
    jst += IntToString(t_st->tm_mday);
    jst += IntToString(t_st->tm_hour);
    jst += IntToString(t_st->tm_min);
    jst += IntToString(t_st->tm_sec);

    return jst;
}

double get_time(void) 
{
    //-現在時刻を取得-//
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

string IntToString(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

void sleep_const_freq(double cycle_start_time, double cycle_end_time, double freq)
{
    //-周期を合わせるために待機-//
    //freqの単位は「秒」
    usleep(freq * 1000000 - (cycle_end_time - cycle_start_time) * 1000000);
}
