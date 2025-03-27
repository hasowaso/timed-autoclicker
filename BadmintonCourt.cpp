#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <iomanip>

void clickAtPosition(int x, int y) {
    SetCursorPos(x, y); // Move the mouse
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); // Click down
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);   // Click up
}

void waitForTime(int targetHour, int targetMinute, int targetSecond, int x1, int y1, int x2, int y2) {
    while (true) {
        // Get current time
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // Convert to local time
        std::tm localTime;
        localtime_s(&localTime, &now_time);

        // Check if the current time matches the target time
        if (localTime.tm_hour == targetHour && localTime.tm_min == targetMinute && localTime.tm_sec == targetSecond) {
            std::cout << "\nTime matched! Clicking at (" << x1 << ", " << y1 << ") and then at (" << x2 << ", " << y2 << ") 3 times.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(700)); // Short delay before second clicks

            clickAtPosition(x1, y1); // First click

            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Short delay before second clicks

            // Click the second position 3 times
            for (int i = 0; i < 10; ++i) {
                clickAtPosition(x2, y2); // Second click
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Small delay between clicks
            }

            break; // Exit after clicking
        }

        // Sleep to avoid excessive CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    int targetHour = 21;    // Set the target hour
    int targetMinute = 59;  // Set the target minute
    int targetSecond = 59;   // Set the target second
    int clickX1 = 654;      // First click X-coordinate
    int clickY1 = 283;      // First click Y-coordinate
    int clickX2 = 821;      // Second click X-coordinate
    int clickY2 = 741;      // Second click Y-coordinate

    std::cout << "Waiting for " << std::setw(2) << std::setfill('0') << targetHour << ":"
        << std::setw(2) << std::setfill('0') << targetMinute << ":"
        << std::setw(2) << std::setfill('0') << targetSecond << "...\n";

    waitForTime(targetHour, targetMinute, targetSecond, clickX1, clickY1, clickX2, clickY2);

    return 0;
}
