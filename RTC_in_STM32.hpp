/**
 * @file RTC_in_STM32.hpp
 * @author 谷 優之心 (yunoshin.tani.0819@gmail.com)
 * @brief STM32内蔵のRTCを制御する
 * @version 1.1
 * @date 2024-11-19
 * @copyright Copyright (c) 2024
 */

#ifndef RTC_IN_STM32_HPP
#define RTC_IN_STM32_HPP

#include <mbed.h>

class RTC_in_STM32
{
public:
    /**
     * @brief コンストラクタ 内臓RTCのセットアップ
     * @param NOW_YEAR 現在の年
     * @param NOW_MONTH 現在の月
     * @param NOW_DATE 現在の日
     * @param NOW_HOUR 現在の時
     * @param NOW_MINUTE 現在の分
     * @param NOW_SECOND 現在の秒
     * @return なし
     * @note 内臓RTCのオブジェクトを複数作れるか不明
     */
    RTC_in_STM32(uint16_t NOW_YEAR, uint8_t NOW_MONTH, uint8_t NOW_DATE, uint8_t NOW_HOUR, uint8_t NOW_MINUTE, uint8_t NOW_SECOND);

    /**
     * @brief RTCの現在時刻を設定する
     * @param NOW_YEAR 現在の年
     * @param NOW_MONTH 現在の月
     * @param NOW_DATE 現在の日
     * @param NOW_HOUR 現在の時
     * @param NOW_MINUTE 現在の分
     * @param NOW_SECOND 現在の秒
     * @return なし
     * @note これを呼び出した時点で、割り込み処理が開始されます
     */
    void reset_time(uint16_t NOW_YEAR, uint8_t NOW_MONTH, uint8_t NOW_DATE, uint8_t NOW_HOUR, uint8_t NOW_MINUTE, uint8_t NOW_SECOND);

    /**
     * @brief RTCの時刻を返す
     * @param SELECT_DATA どの値を取得するか
     * @return 時刻の数字
     * @note 0:全てをprintfする(debug用) 1:年 2:月 3:日 4:時 5:分 6:秒
     */
    int read_time(uint8_t SELECT_DATA);

private:
    /**
     * @brief 内部RTCのデータ保存用
     */   
    struct tm RTC_data;

    /**
     * @brief 内臓RTCの内部データ用
     */   
    time_t RTC_seconds;
};

#endif // RTC_IN_STM32_HPP