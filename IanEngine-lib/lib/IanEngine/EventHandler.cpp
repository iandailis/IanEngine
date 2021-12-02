#include "Objects.cpp"
#include <ctime>

int objectSelect = 0;
std::vector<bool> direction;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_RELEASE) return;
	switch (key) {
		case GLFW_KEY_SPACE:
			unsigned int i;
			if (direction.size() != objects.size()) {
				for (i=0; i < objects.size(); i++) {
					direction.push_back(true);
				}
			}
			for (i=3; i < objects.size(); i++) {
				//objects[i].rotate(0.1, 0.0, 0.0);
				if (direction[i]) {
					objects[i].translate(0.0, 0.0, 0.05);
					if (objects[i].getPosition().z >= 2.0) {
						direction[i] = false;
					}
				} else {
					objects[i].translate(0.0, 0.0, -0.05);
					if (objects[i].getPosition().z <= -2.0) {
						direction[i] = true;
					}
				}
			}
			updatePlz = true;
			break;
		case GLFW_KEY_X:
			xRotate += 5;
			break;
		case GLFW_KEY_C:
			yRotate += 5;
			break;
		case GLFW_KEY_Z:
			zRotate += 5;
			break;

		case GLFW_KEY_W:
			yMoveCam += 0.2;
			break;
		case GLFW_KEY_S:
			yMoveCam -= 0.2;
			break;
		case GLFW_KEY_A:
			xMoveCam -= 0.2;
			break;
		case GLFW_KEY_D:
			xMoveCam += 0.2;
			break;
		case GLFW_KEY_Q:
			zMoveCam += 0.2;
			break;
		case GLFW_KEY_E:
			zMoveCam -= 0.2;
			break;
		
		case GLFW_KEY_I:
			objects[objectSelect].translate(0.0, 0.2, 0.0);
			updatePlz = true;
			break;
		case GLFW_KEY_K:
			objects[objectSelect].translate(0.0, -0.2, 0.0);
			updatePlz = true;
			break;
		case GLFW_KEY_J:
			objects[objectSelect].translate(-0.2, 0.0, 0.0);
			updatePlz = true;
			break;
		case GLFW_KEY_L:
			objects[objectSelect].translate(0.2, 0.0, 0.0);
			updatePlz = true;
			break;
		case GLFW_KEY_U:
			objects[objectSelect].translate(0.0, 0.0, 0.2);
			updatePlz = true;
			break;
		case GLFW_KEY_O:
			objects[objectSelect].translate(0.0, 0.0, -0.2);
			updatePlz = true;
			break;

		case GLFW_KEY_EQUAL:
			if (objectSelect < objects.size() - 1) objectSelect++;
			break;
		case GLFW_KEY_MINUS:
			if (objectSelect > 0) objectSelect--;
			break;

		case GLFW_KEY_PAGE_DOWN:
			zoom -= 5;
			break;
		case GLFW_KEY_PAGE_UP:
			zoom += 5;
			break;

		case GLFW_KEY_H:
			objects[objectSelect].rotate(glm::radians(2.0f), 0.0, 0.0);
			updatePlz = true;
			break;
		case GLFW_KEY_G:
			objects[objectSelect].rotate(0.0, glm::radians(2.0f), 0.0);
			updatePlz = true;
			break;
		case GLFW_KEY_F:
			objects[objectSelect].rotate(0.0, 0.0, glm::radians(2.0f));
			updatePlz = true;
			break;
	}
}