
#include <windows.h>
#include <cstdint>

#include <vector>

#include "asciilibur.hpp"

constexpr const uint8_t k_width = 120;
constexpr const uint8_t k_height = 30;

bool on_update(double delta_time) {
    if (asciilibur::input::get_key_state(VK_ESCAPE)) {
        // Quit game
        return false;
    }

    // ---- Game logic here ----

    // Conitue running game
    return true;
}

void on_draw(asciilibur::FrameBuffer& buffer) {
    // Draw something into the frame buffer
    buffer.draw(asciilibur::Char::SMILE_LIGHT, 10, 10);
    buffer.draw(asciilibur::Char::SMILE_DARK, 11, 10);

    const char* test_sprite_1 = " o \n"
                                "/|\\\n"
                                "/ \\";

    buffer.draw_sprite(test_sprite_1, 12, 10);

    std::vector<uint8_t> test_sprite_2 = {
        32,     1,      32,     10,
        47,     124,    92,     10,
        47,     32,     92,     0,
    };

    buffer.draw_sprite(test_sprite_2.data(), test_sprite_2.size(), 20, 10);

    buffer.draw_sprite("Howdy!", 22, 9);
}

int main() {
    asciilibur::FrameBuffer buffer(k_width, k_height);

    bool should_run = true;
    uint64_t last_time = asciilibur::time::get_time();

    while (should_run) {
        // Get delta time
        uint64_t time_now = asciilibur::time::get_time();
        uint64_t diff = time_now - last_time;
        double delta_time = static_cast<double>(time_now - last_time) / 1000.0f;
        last_time = time_now;

        // Update game
        should_run = on_update(delta_time);

        // Draw things into the buffer
        on_draw(buffer);

        // Render buffer to screen
        buffer.render_buffer();
    }
}
