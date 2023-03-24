
#include <windows.h>
#include <cstdint>
#include <sys/timeb.h>

#include "asciilibur.hpp"

constexpr const uint8_t k_width = 120;
constexpr const uint8_t k_height = 30;

uint64_t system_current_time_millis() {
    struct _timeb timebuffer;
    _ftime(&timebuffer);
    return static_cast<uint64_t>((timebuffer.time * 1000) + timebuffer.millitm);
}

bool on_update(double delta_time) {
    if (GetAsyncKeyState(VK_ESCAPE)) {
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
}

int main() {
    asciilibur::FrameBuffer buffer(k_width, k_height);

    bool should_run = true;
    uint64_t last_time = system_current_time_millis();

    while (should_run) {
        // Get delta time
        uint64_t time_now = system_current_time_millis();
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
