#pragma

#include <lv_cpp/ranges/zip.hpp>


namespace leviathan
{

namespace views
{

inline constexpr auto enumerate = []<typename... Ranges>(Ranges&&... rgs)
{
    auto iota_view = ::std::views::iota(0);
    return ::leviathan::views::zip(std::move(iota_view), ::std::forward<Ranges>(rgs)...);
};

/*
inline constexpr auto enumerate = []<typename... Ranges>(Ranges&&... rgs)
{
    auto iota_view = ::std::views::iota(0);
    return ::std::views::zip(std::move(iota_view), ::std::forward<Ranges>(rgs)...);
};
*/

}



}