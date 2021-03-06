﻿#include <Engine/Graphics/View.hpp>

View::View() :
	center(glm::vec2(0.f)),
	size(glm::vec2(1920.f, 1080.f)),
	scale(1.f),
	matrix(glm::mat4(1.f)),
	dirty(true)
{
}

View::View(const glm::vec2& size) :
	center(glm::vec2(0.f)),
	size(size),
	scale(1.f),
	matrix(glm::mat4(1.f)),
	dirty(true)
{
}

void View::setSize(const glm::vec2& value)
{
	size = value;

	dirty = true;
}

const glm::vec2& View::getSize() const
{
	return size;
}

void View::setScale(float value)
{
	if (value <= 0)
		return;

	scale = value;

	dirty = true;
}

float View::getScale() const
{
	return scale;
}

void View::setCenter(const glm::vec2& value)
{
	center = value;

	dirty = true;
}

const glm::vec2& View::getCenter() const
{
	return center;
}

void View::move(const glm::vec2& offset)
{
	// должен быть +, но с - работает как надо
	center -= offset;

	dirty = true;
}

const glm::mat4& View::getMatrix() const
{
	if (dirty)
	{
		matrix = glm::mat4(1.f);
		matrix = glm::ortho((-size.x / 2), (size.x / 2), (-size.y / 2), (size.y / 2));
		matrix = glm::scale(matrix, glm::vec3(scale, scale, 1.f));
		matrix = glm::translate(matrix, glm::vec3(center, 0.f));

		dirty = false;
	}

	return matrix;
}
