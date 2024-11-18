/**
 * @file RTC_in_STM32.hpp
 * @author 谷 優之心 (yunoshin.tani.0819@gmail.com)
 * @brief STM32内蔵のRTCを制御する
 * @version 1.0
 * @date 2024-11-18
 * @copyright Copyright (c) 2024
 */

#ifndef RTC_IN_STM32_HPP
#define RTC_IN_STM32_HPP

#include <mbed.h>

class RTC_in_STM32
{
public:
    RTC_in_STM32(uint16_t NOW_YEAR, uint8_t NOW_MONTH, uint8_t NOW_DATE, uint8_t NOW_HOUR, uint8_t NOW_MINUTE, uint8_t NOW_SECOND);

    void reset_time(uint16_t NOW_YEAR, uint8_t NOW_MONTH, uint8_t NOW_DATE, uint8_t NOW_HOUR, uint8_t NOW_MINUTE, uint8_t NOW_SECOND);

    int read_time(uint8_t SELECT_DATA);

private:
    struct tm RTC_data;

    time_t RTC_seconds;
};

#endif // RTC_IN_STM32_HPP