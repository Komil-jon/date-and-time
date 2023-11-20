#include <iostream>
using namespace std;

void time(long secs){
    bool finished = false;
    long day, hour, min;
    string month;
    int year = 1970;
    hour = 0;
    min = 0;
    while(!finished){
        if(secs >= 86400){
            day = secs / 86400;
            secs = secs - day * 86400;
        } else if(secs >= 3600){
            hour = secs / 3600;
            secs = secs - hour * 3600;
        } else if(secs >= 60){
            min = secs / 60;
            secs = secs - min * 60;
        } else{
            finished = true;
        }
    }
    finished = false;
    while (!finished) {
        if (year % 4 == 0) {
            if (year % 100 == 0 and year % 400 != 0) {
                break;
            } else {
                if (day > 60)
                    day = day - 1;
            }
        }
        if (day >= 365) {
            year = year + 1;
            day = day - 365;
        } else {
            finished = true;
        }
    }
    switch(day){
        case 0 ... 31:
            month = "January";
            break;
        case 32 ... 59:
            month = "February";
            day = day - 30;
            break;
        case 60 ... 90:
            month = "March";
            day = day - 58;
            break;
        case 91 ... 120 :
            month = "April";
            day = day - 89;
            break;
        case 121 ... 151:
            month = "May";
            day = day - 119;
            break;
        case 152 ... 181:
            month = "June";
            day = day - 150;
            break;
        case 182 ... 212:
            month = "July";
            day = day - 180;
            break;
        case 213 ... 243:
            month = "August";
            day = day - 211;
            break;
        case 244 ... 273:
            month = "September";
            day = day - 242;
            break;
        case 274 ... 304:
            month = "October";
            day = day - 272;
            break;
        case 305 ... 334:
            month = "November";
            day = day - 303;
            break;
        case 335 ... 365:
            month = "December";
            day = day - 333;
            break;
    }
    string second = (secs >= 10) ? to_string(secs) : '0' + to_string(secs) ;
    string time = to_string(hour +5 ) + ':' + to_string(min) + ':' + second;
    cout << "Current date and time is " << month << " " << day << ", " << year << " " << time;
}

int main(){
    long seconds;
    cin >> seconds;
    time(seconds);
}