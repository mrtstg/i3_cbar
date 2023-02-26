#include <iostream>
#include "libs/exec.h"
#include "libs/block.h"
#include <optional>
#include "libs/block_funcs.h"
#include <chrono>
#include <thread>

std::string process_data() {
    json list = json::array();

    list.push_back(time_block());
    list.push_back(brightness_block());
    list.push_back(volume_block());
    list.push_back(battery_block());
    return list.dump();
}

int main() {
    using namespace std;
    cout << "{\"version\": 1}" << endl;
    cout << "[" << endl;

    for(;;) {
        try {
            cout << process_data() << "," << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        } catch (...) {
            cout << "[]," << endl;
        }
    }
    return 0;
}
