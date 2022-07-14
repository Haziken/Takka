#include <Camera.h>

Takka::Camera::Camera(GLuint widht, GLuint height, glm::vec3 position, glm::vec3 worldUp, float yaw, float pitch, float fov)
	: position(position), worldUp(worldUp), yaw(yaw), pitch(pitch), fov(fov), w(widht), h(height)
{
	UpdateVectors();
}

void Takka::Camera::LoadMatrixInShader(Shader& sheder, std::string viewMatrixName, std::string projectionMatrix)
{
	sheder.LoadUniformData(viewMatrixName, GetViewMatrix());
	sheder.LoadUniformData(projectionMatrix, GetProjectMatrix());
}

glm::mat4 Takka::Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

glm::mat4 Takka::Camera::GetProjectMatrix()
{
	return glm::perspective(fov, 1.0f, 0.1f, 100.f);
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
}

GLfloat Takka::Camera::GetPitch()
{
	return pitch;
}

void Takka::Camera::SetPitch(GLfloat pitch)
{
	this->pitch = pitch;
}

GLfloat Takka::Camera::GetFov()
{
	return fov;
}

void Takka::Camera::SetFov(GLfloat fov)
{
	this->fov = fov;
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
