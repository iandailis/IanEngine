#include "SelectionsFromEngine.cpp"
#include "IanEngine.h"

std::vector<Cube> objects;

RenderEngine_API::RenderEngine_API() {
	RenderEngine app;
	app.run();
}

RightTriangle::RightTriangle() {
	color = {1.0f, 1.0f, 1.0f};
	texCoord = {0.0f, 0.0f};
	startIndex_ = -1;
	length_ = 0;
	width_ = 0;
}

RightTriangle::RightTriangle(glm::vec3 position, float length, float width) {
	int i = vertices.size();
	startIndex_ = i;

	color = {1.0f, 1.0f, 1.0f};
	texCoord = {-1.0f, 1.0f};

	length_ = length;
	width_ = width;

	int hello = 0;
	vertices.push_back({{position.x - length_/2.0, position.y - width_/2.0, position.z}, color, texCoord});
	vertices.push_back({{position.x + length_/2.0, position.y - width_/2.0, position.z}, color, texCoord});
	vertices.push_back({{position.x - length_/2.0, position.y + width_/2.0, position.z}, color, texCoord});

	indices.push_back(i);
	indices.push_back(i+1);
	indices.push_back(i+2);

	position_ = position;
}

void RightTriangle::rotate(float angleX, float angleY, float angleZ) {
	int i;
	glm::vec4 pos_vec4;
	glm::mat4 model;
	for (i=startIndex_; i < startIndex_+3; i++) {
		vertices[i].pos -= position_;
		pos_vec4 = glm::vec4(vertices[i].pos, 1.0f);
		model = glm::mat4(1.0f);
		model = glm::rotate(model, angleX, {1.0f, 0.0f, 0.0f});
		model = glm::rotate(model, angleY, {0.0f, 1.0f, 0.0f});
		model = glm::rotate(model, angleZ, {0.0f, 0.0f, 1.0f});
		pos_vec4 = model * pos_vec4;
		vertices[i].pos = glm::vec3(pos_vec4);
		vertices[i].pos += position_;
	}
}

void RightTriangle::rotate(glm::vec3 pivot, float angleX, float angleY, float angleZ) {
	int i;
	glm::vec4 pos_vec4;
	glm::mat4 model;
	for (i=startIndex_; i < startIndex_+3; i++) {
		vertices[i].pos -= pivot;
		pos_vec4 = glm::vec4(vertices[i].pos, 1.0f);
		model = glm::mat4(1.0f);
		model = glm::rotate(model, angleX, {1.0f, 0.0f, 0.0f});
		model = glm::rotate(model, angleY, {0.0f, 1.0f, 0.0f});
		model = glm::rotate(model, angleZ, {0.0f, 0.0f, 1.0f});
		pos_vec4 = model * pos_vec4;
		vertices[i].pos = glm::vec3(pos_vec4);
		vertices[i].pos += pivot;
	}
}

void RightTriangle::rotate(glm::vec3 pivot, glm::vec3 axis, float angle) {
	int i;
	glm::vec4 pos_vec4;
	glm::mat4 model;
	for (i=startIndex_; i < startIndex_+3; i++) {
		vertices[i].pos -= pivot;
		pos_vec4 = glm::vec4(vertices[i].pos, 1.0f);
		model = glm::mat4(1.0f);
		model = glm::rotate(model, angle, axis);
		pos_vec4 = model * pos_vec4;
		vertices[i].pos = glm::vec3(pos_vec4);
		vertices[i].pos += pivot;
	}
}

void RightTriangle::translate(float x, float y, float z) {
	int i;
	glm::vec4 pos_vec4;
	glm::mat4 model;
	for (i=startIndex_; i < startIndex_ + 3; i++) {
		pos_vec4 = glm::vec4(vertices[i].pos, 1.0f);
		model = glm::mat4(1.0f);
		model = glm::translate(model, {x, y, z});
		pos_vec4 = model * pos_vec4;
		vertices[i].pos = glm::vec3(pos_vec4);
	}
}

void RightTriangle::moveTo(glm::vec3 position) {
	translate(position_.x - position.x, position_.y - position.y, position_.z - position.z);
}

Rect::Rect() {
	length_ = 0;
	width_ = 0;

	position_ = {0, 0, 0};
}

Rect::Rect(glm::vec3 position, float length, float width) {
	length_ = length;
	width_ = width;

	botLeft_ = RightTriangle(position, length_, width_);
	topRight_ = RightTriangle(position, -1 * length_, -1 * width_);

	position_ = position;
}

void Rect::translate(float x, float y, float z) {
	botLeft_.translate(x, y, z);
	topRight_.translate(x, y, z);
	position_.x += x;
	position_.y += y;
	position_.z += z;
}

void Rect::rotate(glm::vec3 pivot, float angleX, float angleY, float angleZ) {
	botLeft_.rotate(pivot, angleX, angleY, angleZ);
	topRight_.rotate(pivot, angleX, angleY, angleZ);
}

void Rect::rotate(float angleX, float angleY, float angleZ) {
	botLeft_.rotate(angleX, angleY, angleZ);
	topRight_.rotate(angleX, angleY, angleZ);
}

void Rect::rotate(glm::vec3 pivot, glm::vec3 axis, float angle) {
	botLeft_.rotate(pivot, axis, angle);
	topRight_.rotate(pivot, axis, angle);
}

void Rect::moveTo(glm::vec3 position) {
	translate(position_.x-position.x, position_.y-position.y, position_.z-position.z);
}

Cube::Cube() {
	position_ = {0.0f, 0.0f, 0.0f};
}
Cube::Cube(glm::vec3 position, float length, float width, float height) {
	
	r1 = Rect({position.x, position.y, position.z + height/2.0}, length, width);

	r2 = Rect({position.x, position.y, position.z - height/2.0}, length, width);
	r2.rotate(glm::radians(180.0f), 0.0, 0.0);

	r3 = Rect({position.x + length/2.0, position.y, position.z}, height, width);
	r3.rotate(0.0, glm::radians(90.0f), 0.0);

	r4 = Rect({position.x - length/2.0, position.y, position.z}, height, width);
	r4.rotate(0.0, glm::radians(-90.0f), 0.0);

	r5 = Rect({position.x, position.y + width/2.0, position.z}, length, height);
	r5.rotate(glm::radians(-90.0f), 0.0, 0.0);

	r6 = Rect({position.x, position.y - width/2.0, position.z}, length, height);
	r6.rotate(glm::radians(90.0f), 0.0, 0.0);

	position_ = position;
	objects.push_back(*this);
}

void Cube::rotate(float angleX, float angleY, float angleZ) {
	r1.rotate(position_, angleX, angleY, angleZ);
	r2.rotate(position_, angleX, angleY, angleZ);
	r3.rotate(position_, angleX, angleY, angleZ);
	r4.rotate(position_, angleX, angleY, angleZ);
	r5.rotate(position_, angleX, angleY, angleZ);
	r6.rotate(position_, angleX, angleY, angleZ);
}
void Cube::rotate(glm::vec3 axis, float angle) {
	r1.rotate(position_, axis, angle);
	r2.rotate(position_, axis, angle);
	r3.rotate(position_, axis, angle);
	r4.rotate(position_, axis, angle);
	r5.rotate(position_, axis, angle);
	r6.rotate(position_, axis, angle);
}

void Cube::translate(float x, float y, float z) {
	r1.translate(x, y, z);
	r2.translate(x, y, z);
	r3.translate(x, y, z);
	r4.translate(x, y, z);
	r5.translate(x, y, z);
	r6.translate(x, y, z);
	position_ = {position_.x + x, position_.y + y, position_.z + z};
}

void Cube::moveTo(glm::vec3 position) {
	translate(position_.x-position.x, position_.y-position.y, position_.z-position.z);
}

glm::vec3 Cube::getPosition() {
	return position_;
}

Cylinder::Cylinder(glm::vec3 position, float radius, float height, int detail) {
	int i;
	for(i=0; i < detail; i++) {
		cubes_.push_back(Cube(position, 2 * radius, 2 * radius, height));
		cubes_[i].rotate(0.0, 0.0, glm::radians(i * 180.0 / detail));
	}
	position_ = position;
}

void Cylinder::rotate(float x, float y, float z) {
	int i;
	for (i=0; i < cubes_.size(); i++) {
		cubes_[i].rotate(x, y, z);
	}
}
void Cylinder::rotate(glm::vec3 axis, float angle) {
	int i;
	for (i=0; i < cubes_.size(); i++) {
		cubes_[i].rotate(axis, angle);
	}
}

void Cylinder::translate(float x, float y, float z) {
	int i;
	for (i=0; i < cubes_.size(); i++) {
		cubes_[i].translate(x, y, z);
	}
	position_ = {position_.x + x, position_.y + y, position_.z + z};
}

void Cylinder::moveTo(glm::vec3 position) {
	translate(position_.x-position.x, position_.y-position.y, position_.z-position.z);
}

glm::vec3 Cylinder::getPosition() {
	return position_;
}