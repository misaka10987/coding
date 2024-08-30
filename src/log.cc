#pragma once

#include "root.cc"

#include <chrono>
#include <iostream>

#define trace(msg) {if(coding::log::LOG_LEVEL>=40)std::cerr<<coding::log::log_time()<<" \e[35mTRACE\e[0m "<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define debug(msg) {if(coding::log::LOG_LEVEL>=30)std::cerr<<coding::log::log_time()<<" \e[34mDEBUG\e[0m "<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define info(msg) {if(coding::log::LOG_LEVEL>=20)std::cerr<<coding::log::log_time()<<" \e[32mINFO\e[0m  "<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define warn(msg) {if(coding::log::LOG_LEVEL>=10)std::cerr<<coding::log::log_time()<<" \e[33;1mWARN\e[0m  "<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

#define error(msg) {if(coding::log::LOG_LEVEL>=0)std::cerr<<coding::log::log_time()<<" \e[31;1mERROR\e[0m "<<__FILE__<<":"<<__LINE__<<" :: "<<msg<<std::endl;}

namespace coding::log {

    static volatile int LOG_LEVEL = 255;

    constexpr int LOG_LEVEL_DISABLED = -255;
    constexpr int LOG_LEVEL_ERROR = 0;
    constexpr int LOG_LEVEL_WARN = 10;
    constexpr int LOG_LEVEL_INFO = 20;
    constexpr int LOG_LEVEL_DEBUG = 30;
    constexpr int LOG_LEVEL_TRACE = 40;

    auto log_time() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_t = std::chrono::system_clock::to_time_t(now);
        return std::put_time(std::localtime(&now_t), "%Y%m%d.%H%M%S");
    }
}
