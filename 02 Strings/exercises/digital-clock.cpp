#include <string> 
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int hour = minutes/60; 
    int minute = minutes%60;
    string strHour = to_string(hour);
    string strMinute = minute < 10 ? "0"+ to_string(minute) : to_string(minute);
    return strHour+":"+strMinute;
}