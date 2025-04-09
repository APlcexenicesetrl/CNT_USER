#include "client.h"

int main() {
    FreeConsole();

    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "CNT USER", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render graphics here

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}