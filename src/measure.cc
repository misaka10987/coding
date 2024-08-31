#pragma once

#include "root.cc"

#include <cmath>

/// @brief Helpers with real-world measurement units.
/// 
namespace coding::measure {

    /// @brief The angle in radian.
    /// 
    using Angle = double;

    /// @brief Convert radian to radian.
    /// @param p angle in radian
    /// @return `Angle` in radian
    /// 
    inline constexpr auto operator"" _rad(long double p) noexcept -> Angle { return p; }

    /// @brief Convert degree to radian
    /// @param p angle in degree
    /// @return `Angle` in radian
    /// 
    inline constexpr auto operator"" _deg(long double p) noexcept -> Angle { return p * M_PI / 180; }

    /// @brief Convert rotation to radian
    /// @param p angle in rotation
    /// @return `Angle` in radian
    /// 
    inline constexpr auto operator"" _rot(long double p) noexcept -> Angle { return p * 360.0_deg; }

    /// @brief The length in metre.
    /// 
    using Length = double;

    /// @brief Convert metre to metre.
    /// @param l length in metre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _m(long double l) noexcept -> Length { return l; }

    /// @brief Convert kilometre to metre.
    /// @param l length in kilometre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _km(long double l) noexcept -> Length { return l * 1e3; }

    /// @brief Convert decimetre to metre.
    /// @param l length in decimetre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _dm(long double l) noexcept -> Length { return l * 0.1; }

    /// @brief Convert centimetre to metre.
    /// @param l length in centimetre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _cm(long double l) noexcept -> Length { return l * 0.01; }

    /// @brief Convert milimetre to metre.
    /// @param l length in milimetre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _mm(long double l) noexcept -> Length { return l * 1e-3; }

    /// @brief Convert micrometre to metre.
    /// @param l length in micrometre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _um(long double l) noexcept -> Length { return l * 1e-6; }

    /// @brief Convert nanometre to metre.
    /// @param l length in nanometre
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _nm(long double l) noexcept -> Length { return l * 1e-9; }

    /// @brief Convert inch to metre.
    /// @param l length in inch
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _in(long double l) noexcept -> Length { return l * 0.0254; }

    /// @brief Convert foot to metre.
    /// @param l length in foot
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _ft(long double l) noexcept -> Length { return l * 0.3048; }

    /// @brief Convert nautical mile to metre.
    /// @param l length in nautical mile
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _nmi(long double l) noexcept -> Length { return l * 1852; }

    /// @brief Convert astronomical unit to metre.
    /// @param l length in astronomical unit
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _au(long double l) noexcept -> Length { return l * 1.495979e11; }

    /// @brief Convert light year to metre.
    /// @param l length in light year
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _ly(long double l) noexcept -> Length { return l * 9.4607e15; }

    /// @brief Convert parsec to metre.
    /// @param l length in parsec
    /// @return `Length` in metre
    /// 
    inline constexpr auto operator"" _pc(long double l) noexcept -> Length { return l * 3.0857e16; }

    /// @brief The area in m^2.
    /// 
    using Area = double;

    /// @brief Convert square metre to square metre.
    /// @param a area in square metre
    /// @return `Area` in square metre
    /// 
    inline constexpr auto operator"" _m2(long double s) noexcept -> Area { return s; }

    /// @brief The volume in m^3.
    /// 
    using Volume = double;

    /// @brief Convert cubic metre to cubic metre.
    /// @param v volume in cubic metre
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _m3(long double v) noexcept -> Volume { return v; }

    /// @brief Convert litre to cubic metre.
    /// @param v volume in litre
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _L(long double v) noexcept -> Volume { return v * 1e-3; }

    /// @brief Convert mililitre to cubic metre.
    /// @param v volume in mililitre
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _mL(long double v) noexcept -> Volume { return v * 1e-6; }

    /// @brief Convert US quart to cubic metre.
    /// @param v volume in US quart
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _qt(long double v) noexcept -> Volume { return v * 0.946353e-3; }

    /// @brief Convert US pint to cubic metre.
    /// @param v volume in US pint
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _pt(long double v) noexcept -> Volume { return v * 0.4731765e-3; }

    /// @brief Convert US gallon to cubic metre.
    /// @param v volume in US gallon
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _gal(long double v) noexcept -> Volume { return v * 3.785412e-3; }

    /// @brief Convert US cup to cubic metre.
    /// @param v volume in US cup
    /// @return `Volume` in cubic metre
    /// 
    inline constexpr auto operator"" _cup(long double v) noexcept -> Volume { return v * 0.24e-3; }

    /// @brief The mass in kilogram.
    /// 
    using Mass = double;

    /// @brief Convert kilogram to kilogram.
    /// @param m mass in kilogram
    /// @return `Mass` in kilogram
    /// 
    inline constexpr auto operator"" _kg(long double m) noexcept -> Mass { return m; }

    /// @brief Convert ton to kilogram.
    /// @param m mass in ton
    /// @return `Mass` in kilogram
    /// 
    inline constexpr auto operator"" _t(long double m) noexcept -> Mass { return m * 1e3; }

    /// @brief Convert gram to kilogram.
    /// @param m mass in gram
    /// @return `Mass` in kilogram
    /// 
    inline constexpr auto operator"" _g(long double m) noexcept -> Mass { return m * 1e-3; }

    /// @brief Convert pound to kilogram.
    /// @param m mass in pound
    /// @return `Mass` in kilogram
    /// 
    inline constexpr auto operator"" _lbs(long double m) noexcept -> Mass { return m * 0.4535924; }

    /// @brief The time in second.
    /// 
    using Time = double;

    /// @brief Convert second to second.
    /// @param t time in second
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _s(long double t) noexcept -> Time { return t ; }

    /// @brief Convert milisecond to second.
    /// @param t time in milisecond
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _ms(long double t) noexcept -> Time { return t * 1e-3; }

    /// @brief Convert microsecond to second.
    /// @param t time in microsecond
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _us(long double t) noexcept -> Time { return t * 1e-6; }

    /// @brief Convert nanosecond to second.
    /// @param t time in nanosecond
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _ns(long double t) noexcept -> Time { return t * 1e-9; }

    /// @brief Convert minute to second.
    /// @param t time in minute
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _min(long double t) noexcept -> Time { return t * 60; }

    /// @brief Convert hour to second.
    /// @param t time in hour
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _h(long double t) noexcept -> Time { return t * 3600; }

    /// @brief Convert day to second.
    /// @note A day here is strictly equal to 24 hours.
    /// @param t time in day
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _d(long double t) noexcept -> Time { return t * 86400; }

    /// @brief Convert year to second.
    /// @note A year here is strictly equal to 365.25 days.
    /// @param t time in day
    /// @return `Time` in second
    /// 
    inline constexpr auto operator"" _yr(long double t) noexcept -> Time { return t * 3.15576E7; }

    using Impulse = double;

    using Momentum = Impulse;

    /// @brief The force in Newton.
    /// 
    using Force = double;

    /// @brief Convert Newton to Newton.
    /// @param f force in Newton
    /// @return `Force` in Newton
    /// 
    inline constexpr auto operator"" _N(long double f) noexcept -> Force { return f; }

    /// @brief The work in Joule.
    /// 
    using Work = double;

    /// @brief Convert Joule to Joule.
    /// @param w work in Joule
    /// @return `Work` in Joule
    /// 
    inline constexpr auto operator"" _J(long double w) noexcept -> Work { return w; }

    /// @brief Convert kilojoule to Joule.
    /// @param w work in kilojoule
    /// @return `Work` in Joule
    /// 
    inline constexpr auto operator"" _kJ(long double w) noexcept -> Work { return w * 1e3; }

    /// @brief Convert megajoule to Joule.
    /// @param w work in megajoule
    /// @return `Work` in Joule
    /// 
    inline constexpr auto operator"" _MJ(long double w) noexcept -> Work { return w * 1e6; }

    /// @brief Convert gigajoule to Joule.
    /// @param w work in gigajoule
    /// @return `Work` in Joule
    /// 
    inline constexpr auto operator"" _GJ(long double w) noexcept -> Work { return w * 1e9; }

    /// @brief Convert terajoule to Joule.
    /// @param w work in terajoule
    /// @return `Work` in Joule
    /// 
    inline constexpr auto operator"" _TJ(long double w) noexcept -> Work { return w * 1e12; }

    /// @brief Convert calorie to Joule.
    /// @param w work in calorie
    /// @return `Work` in Joule
    /// 
    inline constexpr auto operator"" _cal(long double w) noexcept -> Work { return w * 4.184; }

    using Energy = Work;

    /// @brief The current in ampere.
    /// 
    using Current = double;

    /// @brief Convert Ampere to Ampere.
    /// @param i current in Ampere
    /// @return `Current` in Ampere
    /// 
    inline constexpr auto operator"" _A(long double i) noexcept -> Current { return i; }

    /// @brief Convert miliampere to Ampere.
    /// @param i current in miliampere
    /// @return `Current` in Ampere
    /// 
    inline constexpr auto operator"" _mA(long double i) noexcept -> Current { return i * 1e-3; }

    /// @brief The voltage in Volt.
    /// 
    using Voltage = double;

    /// @brief Convert Volt to Volt
    /// @param v voltage in Volt
    /// @return `Voltage` in Volt
    /// 
    inline constexpr auto operator"" _V(long double v) noexcept -> Voltage { return v ; }
}
