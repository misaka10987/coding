#pragma once

#include "root.cc"

#include <chrono>
#include <ctime>
#include <iostream>

#define coding_log(msg,level,prefix) {if(coding::log::LOG_LEVEL>=level)std::cerr<<coding::log::log_time()<<prefix<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define coding_trace(msg) log(msg,40," \e[35mTRACE\e[0m ")

#define coding_debug(msg) log(msg,30," \e[34mDEBUG\e[0m ")

#define coding_info(msg) log(msg,20," \e[32mINFO\e[0m  ")

#define coding_warn(msg) log(msg,10," \e[33;1mWARN\e[0m  ")

#define coding_error(msg) log(msg,0," \e[31;1mERROR\e[0m ")

namespace coding::log {

    /// @brief Assign to this variable to control log level.
    /// 
    inline volatile int LOG_LEVEL = 255;

    constexpr int LOG_LEVEL_DISABLED = -255;
    constexpr int LOG_LEVEL_ERROR = 0;
    constexpr int LOG_LEVEL_WARN = 10;
    constexpr int LOG_LEVEL_INFO = 20;
    constexpr int LOG_LEVEL_DEBUG = 30;
    constexpr int LOG_LEVEL_TRACE = 40;

    inline auto log_time() noexcept {
        auto t = std::time({});
        char s[std::size("yyyy-mm-ddThh:mm:ssZ")];
        std::strftime(std::data(s), std::size(s), "%FT%TZ", std::gmtime(&t));
        return s;
    }
}
