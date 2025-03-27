#include <iostream>
#include <windows.h>
#include <thread>

void trackMousePosition() {
    POINT cursorPos;
    while (true) {
        GetCursorPos(&cursorPos); // Get the current mouse position
        std::cout << "\rMouse Position: (" << cursorPos.x << ", " << cursorPos.y << ")  " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Update every 100ms
    }
}

int main() {
    std::cout << "Move your mouse over the button to check its coordinates.\n";
    std::cout << "Press Ctrl + C to stop the program.\n";
    trackMousePosition(); // Run the function
    return 0;
}