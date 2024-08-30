#pragma once

#include "root.cc"

#include <chrono>
#include <iostream>

#define log(msg,level,prefix) {if(coding::log::LOG_LEVEL>=level)std::cerr<<coding::log::log_time()<<prefix<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define trace(msg) log(msg,40," \e[35mTRACE\e[0m ")

#define debug(msg) log(msg,30," \e[34mDEBUG\e[0m ")

#define info(msg) log(msg,20," \e[32mINFO\e[0m  ")

#define warn(msg) log(msg,10," \e[33;1mWARN\e[0m  ")

#define error(msg) log(msg,0," \e[31;1mERROR\e[0m ")

namespace coding::log {

    /// @brief Assign to this variable to control log level.
    /// 
    volatile int LOG_LEVEL = 255;

    constexpr int LOG_LEVEL_DISABLED = -255;
    constexpr int LOG_LEVEL_ERROR = 0;
    constexpr int LOG_LEVEL_WARN = 10;
    constexpr int LOG_LEVEL_INFO = 20;
    constexpr int LOG_LEVEL_DEBUG = 30;
    constexpr int LOG_LEVEL_TRACE = 40;

    inline auto log_time() noexcept {
        auto now = std::chrono::system_clock::now();
        std::time_t now_t = std::chrono::system_clock::to_time_t(now);
        return std::put_time(std::localtime(&now_t), "%Y%m%d.%H%M%S");
    }
}
