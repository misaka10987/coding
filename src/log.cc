#pragma once

#include "root.cc"

#include <chrono>
#include <ctime>
#include <iostream>

#define coding_log(msg,level,prefix) {if(coding::log::LOG_LEVEL>=level)std::cerr<<coding::log::log_time()<<prefix<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define coding_trace(msg) coding_log(msg,40," \033[35mTRACE\033[0m ")

#define coding_debug(msg) coding_log(msg,30," \033[34mDEBUG\033[0m ")

#define coding_info(msg) coding_log(msg,20," \033[32mINFO\033[0m  ")

#define coding_warn(msg) coding_log(msg,10," \033[33;1mWARN\033[0m  ")

#define coding_error(msg) coding_log(msg,0," \033[31;1mERROR\033[0m ")

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

    inline auto log_time() noexcept -> std::string {
        auto t = std::time({});
        char s[std::size("yyyy-mm-ddThh:mm:ssZ")];
        std::strftime(std::data(s), std::size(s), "%FT%TZ", std::gmtime(&t));
        return s;
    }
}
