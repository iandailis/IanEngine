#pragma once

#include "Vertices.h"

class RenderEngine_API {
	public:
		RenderEngine_API();
};

class RightTriangle {
	public:
		glm::vec3 color;
		glm::vec2 texCoord;

		RightTriangle();

		RightTriangle(glm::vec3 position, float length, float width);

		void rotate(float angleX, float angleY, float angleZ);

		void rotate(glm::vec3 pivot, float angleX, float angleY, float angleZ);

		void rotate(glm::vec3 pivot, glm::vec3 axis, float angle);

		void translate(float x, float y, float z);

		void moveTo(glm::vec3 position);

	private:
		int startIndex_;
		float length_;
		float width_;
		glm::vec3 position_;
};

class Rect {
	public:
		Rect();

		Rect(glm::vec3 position, float length, float width);

		void translate(float x, float y, float z);

		void rotate(glm::vec3 pivot, float angleX, float angleY, float angleZ);

		void rotate(float angleX, float angleY, float angleZ);

		void rotate(glm::vec3 pivot, glm::vec3 axis, float angle);

		void moveTo(glm::vec3 position);

	private:
		float length_;
		float width_;
		RightTriangle botLeft_;
		RightTriangle topRight_;
		glm::vec3 position_;
};


class Cube {
	public:
		Cube();
		Cube(glm::vec3 position, float length, float width, float height);
		void rotate(float angleX, float angleY, float angleZ);
		void rotate(glm::vec3 axis, float angle);
		void translate(float x, float y, float z);
		void moveTo(glm::vec3 position);
		glm::vec3 getPosition();
	private:
		Rect r1;
		Rect r2;
		Rect r3;
		Rect r4;
		Rect r5;
		Rect r6;
		glm::vec3 position_;
};

class Cylinder {
	public:
		Cylinder(glm::vec3 position, float radius, float height, int detail);
		void rotate(float angleX, float angleY, float angleZ);
		void rotate(glm::vec3 axis, float angle);
		void translate(float x, float y, float z);
		void moveTo(glm::vec3 position);
		glm::vec3 getPosition();
	private:
		std::vector<Cube> cubes_;
		glm::vec3 position_;
};

class bCylinder {
	public:
		bCylinder(glm::vec3 position, float radius, float height);
		void rotate(float angleX, float angleY, float angleZ);
		void translate(float x, float y, float z);
		void rotate(glm::vec3 axis, float angle);
		void moveTo(glm::vec3 position);
	private:
};

