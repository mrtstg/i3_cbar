#include "block_funcs.h"
#include <time.h>
#include "exec.h"

json time_block() {
    Block time_block = Block();
    time_t t = time(NULL);
    tm* datetime = localtime(&t);
    char buf[50];
    snprintf(
        buf,
        50,
        "%s%i.%s%i.%i %s%i:%s%i:%s%i",
        datetime->tm_mday < 10 ? "0" : "",
        datetime->tm_mday,
        datetime->tm_mon + 1 < 10 ? "0" : "",
        datetime->tm_mon + 1,
        datetime->tm_year + 1900,
        datetime->tm_hour < 10 ? "0" : "",
        datetime->tm_hour,
        datetime->tm_min < 10 ? "0" : "",
        datetime->tm_min,
        datetime->tm_sec < 10 ? "0" : "",
        datetime->tm_sec
    );
    std::string text = buf;
    time_block.align = Align::center;
    time_block.full_text = text;
    return time_block.get_json();
}

json volume_block() {
    Block volume_block = Block();
    bool muted = exec("amixer sget Master").find("[off]") != std::string::npos;
    volume_block.full_text = muted ? "[M]" : exec("awk -F\"[][]\" \'/Left:/ { print $2 }\' <(amixer sget Master)");
    volume_block.min_width = 50;
    volume_block.align = Align::center;
    return volume_block.get_json();
}

json brightness_block() {
    using std::string;
    Block block;

    uint32_t current = static_cast<uint32_t>(
        std::stoul(
            exec("brightnessctl get")
        )
    );

    double max = static_cast<double>(
        std::stoul(
            exec("brightnessctl max")
        )
    );

    int32_t percentage = static_cast<int32_t>(
        (current / max) * 10
    );

    block.short_text = std::to_string(
        static_cast<int32_t>((current / max) * 100)
    ) + "%";
    string full_text;
    for (size_t i = 0; i < percentage; i++) {
        full_text += "=";
    }
    for (size_t i = 0; i < 10 - percentage; i++) {
        full_text += "-";
    }
    block.full_text = full_text;
    return block.get_json();
}
