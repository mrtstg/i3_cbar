#pragma once
#include <string>
#include <optional>
#include "json.hpp"
#include <cstdint>

using json = nlohmann::json;

enum class Align {
    center,
    right,
    left,
    undefined
};

struct Block {
    std::string full_text;
    std::string short_text = "";
    std::string color = "";
    uint32_t min_width = 0;
    Align align = Align::undefined;

    Block();
    Block(std::string full_text_v);
    json get_json();
};
