#pragma once
#include <string>
#include <optional>
#include "json.hpp"

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
    Align align = Align::undefined;

    Block(std::string full_text_v);
    json get_json();
};
