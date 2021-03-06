#include <iostream>
#include <lv_cpp/ranges/concat.hpp>
#include <lv_cpp/io/console.hpp>
#include <vector>
#include <list>


int main()
{
    std::vector v1{7, 8, 9};
    std::list ls1{4, 5, 6}, ls2{1, 2, 3};

    for (auto& val : leviathan::ranges::concat_view(ls2, ls1, v1)) 
        val ++, console::write("{0} ", val);
    for (auto val : leviathan::ranges::concat_view(ls2, ls1, v1)) 
        console::write("{0} ", val);
    auto view = leviathan::ranges::concat_view(ls2, ls1, v1);
    auto iter1 = view.begin();
    auto iter2 = view.end();
    console::write_line(std::input_iterator<decltype(iter1)>);
    console::write_line(iter2 == iter1);
}