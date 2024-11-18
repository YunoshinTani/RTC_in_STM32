#include <mbed.h>
#include "RTC_in_STM32.hpp"

RTC_in_STM32 myRTC1(2024,11,19,2,37,25);

int main()
{
    while (true)
    {
        myRTC1.read_time(0);
        ThisThread::sleep_for(1s);
    }
}