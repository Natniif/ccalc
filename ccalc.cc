#define GL_SILENCE_DEPRECATION // Important to define before OpenGL headers.
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include <GL/freeglut.h>
#include <iostream> 
#include "maths.hpp"

#define WINW 400
#define WINH 600

struct Button {
	float x, y, width, height;
	std::string label;
};

std::vector<Button> buttons;
std::string displayText = "";

// void drawText(float x, float y, const std::string& text, float scale) {
//     glRasterPos2f(x, y);
//     for (char c : text) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//     }
// }

void drawButton(const Button& button) {
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
	// create vertexes
    glVertex2f(button.x, button.y);
    glVertex2f(button.x + button.width, button.y);
    glVertex2f(button.x + button.width, button.y + button.height);
    glVertex2f(button.x, button.y + button.height);
    glEnd();
	// color of button
    // glColor3f(0.0f, 0.0f, 0.0f);
	// text inside button
    // drawText(button.x + 0.02f, button.y + 0.04f, button.label, 0.1f);
}

std::vector<std::vector<char>> button_vals;

void setupButtonVals() {
    button_vals.push_back({'%', 'C', 'CE', '/'});
    button_vals.push_back({'7', '8', '9', '*'});
    button_vals.push_back({'4', '5', '6', '-'});
    button_vals.push_back({'1', '2', '3', '+'});
    button_vals.push_back({' ', '0', '.', '='});
}

setupButtonVals();

void setupButtons() {
    float startX = -0.1f;
    float startY = -0.4f;
    float buttonWidth = WINW/3 - 5*0.1f;
    float buttonHeight = WINH/5 ;
	// col
    for (int i = 0; i < 4; ++i) {
		// row
        for (int j = 0; j < 5; ++j) {
            buttons.push_back({startX + j * buttonWidth, startY + i * buttonHeight, buttonWidth, buttonHeight, button_vals[i][j]});
        }
    }
    buttons.push_back({startX, startY + 3 * buttonHeight, buttonWidth, buttonHeight, "0"});
}

void drawDisplay(GLFWwindow* window) {
    glColor3f(0.5f, 0.5f, 0.5f);
    // drawText(-0.9f, 0.8f, displayText, 1.0f);
}

void draw(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawDisplay(window);
    for (const auto& button : buttons) {
        drawButton(button);
    }
    glfwSwapBuffers(window);
}

void handleMouseClick(double xpos, double ypos) {
    for (const auto& button : buttons) {
        if (xpos > button.x && xpos < button.x + button.width &&
            ypos > button.y && ypos < button.y + button.height) {
            displayText += button.label;
        }
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        handleMouseClick(xpos, ypos);
    }
}

int main(int argc, char** argv) {
	if(!glfwInit()) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(WINW, WINH, "Calculator", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	setupButtons();

    while (!glfwWindowShouldClose(window))
    {
		draw(window);
		glfwPollEvents();	
    }

	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}