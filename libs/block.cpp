#include "block.h"

Block::Block() {
    full_text = "";
}

Block::Block(std::string full_text_v) {
    full_text = full_text_v;
}

json Block::get_json() {
    json obj;
    obj["full_text"] = full_text;
    if (short_text.length() > 0) {
        obj["short_text"] = short_text;
    }

    if (color.length() > 0) {
        obj["color"] = color;
    }

    switch(align) {
        case Align::center:
            obj["align"] = "center";
            break;
        case Align::left:
            obj["align"] = "left";
            break;
        case Align::right:
            obj["align"] = "right";
            break;
        case Align::undefined:
            break;
    }

    return obj;
}
