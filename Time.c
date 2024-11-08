#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep function

void display_time() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int hour = timeinfo->tm_hour % 12;
    if (hour == 0) hour = 12;
    const char* am_pm = (timeinfo->tm_hour >= 12) ? "PM" : "AM";

    printf("\rCurrent time: %02d:%02d:%02d %s", 
            hour, 
            timeinfo->tm_min, 
            timeinfo->tm_sec,
            am_pm);
    fflush(stdout); // Clear the output buffer
}

int main() {
    while (1) {
        display_time();
        sleep(1); // Wait for 1 second
    }
    return 0;
}
