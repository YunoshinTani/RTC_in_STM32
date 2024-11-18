/**
 * @file RTC_in_STM32.cpp
 * @author 谷 優之心 (yunoshin.tani.0819@gmail.com)
 * @brief STM32内蔵のRTCを制御する
 * @version 1.1
 * @date 2024-11-19
 * @copyright Copyright (c) 2024
 */

#include "RTC_in_STM32.hpp"

RTC_in_STM32::RTC_in_STM32(uint16_t NOW_YEAR, uint8_t NOW_MONTH, uint8_t NOW_DATE, uint8_t NOW_HOUR, uint8_t NOW_MINUTE, uint8_t NOW_SECOND){
    // setup time structure for Wed
    RTC_data.tm_sec  = NOW_SECOND;       // 0-59
    RTC_data.tm_min  = NOW_MINUTE;       // 0-59
    RTC_data.tm_hour = NOW_HOUR;         // 0-23
    RTC_data.tm_mday = NOW_DATE;         // 1-31
    RTC_data.tm_mon  = NOW_MONTH - 1;    // 0-11
    RTC_data.tm_year = NOW_YEAR  - 1900; // year since 1900

    // convert to timestamp and set (1256729737)
    RTC_seconds = mktime(&RTC_data);
    set_time(RTC_seconds);
}

void RTC_in_STM32::reset_time(uint16_t NOW_YEAR, uint8_t NOW_MONTH, uint8_t NOW_DATE, uint8_t NOW_HOUR, uint8_t NOW_MINUTE, uint8_t NOW_SECOND){
    // setup time structure for Wed
    RTC_data.tm_sec  = NOW_SECOND;       // 0-59
    RTC_data.tm_min  = NOW_MINUTE;       // 0-59
    RTC_data.tm_hour = NOW_HOUR;         // 0-23
    RTC_data.tm_mday = NOW_DATE;         // 1-31
    RTC_data.tm_mon  = NOW_MONTH - 1;    // 0-11
    RTC_data.tm_year = NOW_YEAR  - 1900; // year since 1900

    // convert to timestamp and set (1256729737)
    RTC_seconds = mktime(&RTC_data);
    set_time(RTC_seconds);
}

int RTC_in_STM32::read_time(uint8_t SELECT_DATA)
{
    RTC_seconds = time(NULL);
    struct tm *RTC_data = localtime(&RTC_seconds);

    switch (SELECT_DATA)
    {
    case 0:
        printf("%04d / %02d / %02d  %02d : %02d : %02d\n",
        RTC_data->tm_year + 1900, RTC_data->tm_mon + 1, RTC_data->tm_mday, RTC_data->tm_hour, RTC_data->tm_min, RTC_data->tm_sec);
        return 0;
        break;

    case 1:
        return RTC_data->tm_year + 1900;
        break;

    case 2:
        return RTC_data->tm_mon + 1;
        break;

    case 3:
        return RTC_data->tm_mday;
        break;

    case 4:
        return RTC_data->tm_hour;
        break;

    case 5:
        return RTC_data->tm_min;
        break;

    case 6:
        return RTC_data->tm_sec;
        break;

    case 7:
        return 0;
        break;
    
    default:
        return 0;
        break;
    }
}