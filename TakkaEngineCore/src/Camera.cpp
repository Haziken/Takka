#include "../include/Camera.h"

Takka::Camera::Camera(const Camera& cam) noexcept
	: fov(cam.fov), worldUp(cam.worldUp), position(cam.position), w(cam.w), h(cam.h), pitch(cam.pitch), yaw(cam.yaw)
{
	UpdateVectors();
}

Takka::Camera::Camera(Camera&& cam) noexcept
{
	std::swap(this->h, cam.h);
	std::swap(this->w, cam.w);
	std::swap(this->fov, cam.fov);
	std::swap(this->yaw, cam.yaw);
	std::swap(this->pitch, cam.pitch);
	std::swap(this->worldUp, cam.worldUp);
	std::swap(this->position, cam.position);
}

Takka::Camera& Takka::Camera::operator=(const Camera& cam) noexcept
{
	this->h = cam.h;
	this->w = cam.w;
	this->fov = cam.fov;
	this->yaw = cam.yaw;
	this->pitch = cam.pitch;
	this->worldUp = cam.worldUp;
	this->position = cam.position;
	return *this;
}

Takka::Camera& Takka::Camera::operator=(Camera&& cam) noexcept
{
	std::swap(this->h, cam.h);
	std::swap(this->w, cam.w);
	std::swap(this->fov, cam.fov);
	std::swap(this->yaw, cam.yaw);
	std::swap(this->pitch, cam.pitch);
	std::swap(this->worldUp, cam.worldUp);
	std::swap(this->position, cam.position);
	return *this;
}

Takka::Camera::Camera(GLuint widht, GLuint height, glm::vec3 position, glm::vec3 worldUp, float yaw, float pitch, float fov) noexcept
	: position(position), worldUp(worldUp), yaw(yaw), pitch(pitch), fov(fov), w(widht), h(height)
{
	UpdateVectors();
}

Takka::Camera::~Camera() noexcept {}

void Takka::Camera::LoadMatrixInShader(Shader& sheder, std::string viewMatrixName, std::string projectionMatrix)
{
	//sheder.Use();
	sheder.LoadUniformData(viewMatrixName, GetViewMatrix());
	sheder.LoadUniformData(projectionMatrix, GetProjectMatrix());
}

glm::mat4 Takka::Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

glm::mat4 Takka::Camera::GetProjectMatrix()
{
	return glm::perspective(glm::radians(fov), (float)w / (float)h, 0.1f, 100.f);
}

glm::vec3 Takka::Camera::GetPosition()
{
	return position;
}

void Takka::Camera::SetPosition(glm::vec3 position)
{
	this->position = position;
}

GLfloat Takka::Camera::GetYaw()
{
	return yaw;
}

void Takka::Camera::SetYaw(GLfloat yaw)
{
	this->yaw = yaw;
	UpdateVectors();
}

GLfloat Takka::Camera::GetPitch()
{
	return pitch;
}

void Takka::Camera::SetPitch(GLfloat pitch)
{
	this->pitch = std::max(std::min(pitch, (GLfloat)89.9), (GLfloat)-89.9);
	UpdateVectors();
}

GLfloat Takka::Camera::GetFov()
{
	return fov;
}

void Takka::Camera::SetFov(GLfloat fov)
{
	this->fov = fov;
}

glm::vec3 Takka::Camera::GetFront()
{
	return front;
}

glm::vec3 Takka::Camera::GetRight()
{
	return right;
}

void Takka::Camera::UpdateVectors()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}
