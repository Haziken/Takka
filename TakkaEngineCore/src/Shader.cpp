#include <Shader.h>

Takka::Shader::Shader() {}

Takka::Shader::Shader(GLuint id) : id(id)
{}

Takka::Shader::Shader(const std::string& vertex, const std::string& fragment)
{
	CreateProgram(vertex, fragment);
}

Takka::Shader::~Shader()
{
	glDeleteProgram(id);
}

GLuint Takka::Shader::GetID()
{
	return id;
}

void Takka::Shader::Use()
{
	glUseProgram(id);
}

GLuint Takka::Shader::GetUniformID(const std::string& uniform)
{
	return glGetUniformLocation(id, uniform.c_str());
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::mat4 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::mat4 data)
{
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(data));
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::mat3 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::mat3 data)
{
	glUniformMatrix3fv(uniformID, 1, GL_FALSE, glm::value_ptr(data));
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::mat2 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::mat2 data)
{
	glUniformMatrix2fv(uniformID, 1, GL_FALSE, glm::value_ptr(data));
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::vec4 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::vec4 data)
{
	glUniform4f(uniformID, data[0], data[1], data[2], data[3]);
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::vec3 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::vec3 data)
{
	glUniform3f(uniformID, data[0], data[1], data[2]);
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::vec2 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::vec2 data)
{
	glUniform2f(uniformID, data[0], data[1]);
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, glm::vec1 data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, glm::vec1 data)
{
	glUniform1f(uniformID, data[0]);
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, GLint data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, GLint data)
{
	glUniform1i(uniformID, data);
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, GLuint data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, GLuint data)
{
	glUniform1ui(uniformID, data);
}

void Takka::Shader::LoadUniformData(const std::string& uniformName, GLfloat data)
{
	LoadUniformData(GetUniformID(uniformName), data);
}

void Takka::Shader::LoadUniformData(GLuint uniformID, GLfloat data)
{
	glUniform1f(uniformID, data);
}

void Takka::Shader::CreateProgram(const std::string& vertex, const std::string& fragment)
{
	glDeleteProgram(id);
	id = glCreateProgram();

	GLuint vert = CreateShaderProgram(vertex, GL_VERTEX_SHADER);
	GLuint frag = CreateShaderProgram(fragment, GL_FRAGMENT_SHADER);

	glAttachShader(id, vert);
	glAttachShader(id, frag);

	glLinkProgram(id);

	GLint success;
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(id, 1024, nullptr, infoLog);
		//LERROR("Shader not link: ", infoLog);
		std::cout << infoLog;
		glDeleteShader(vert);
		glDeleteShader(frag);
	}

	glDeleteShader(vert);
	glDeleteShader(frag);
}

GLuint Takka::Shader::CreateShaderProgram(const std::string& code, GLenum shaderType)
{
	GLuint shaderID = glCreateShader(shaderType);
	const char* c = code.c_str();
	glShaderSource(shaderID, 1, &c, nullptr);
	glCompileShader(shaderID);
	GLint success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(shaderID, 1024, nullptr, infoLog);
		//LERROR("Shader not compile: ", infoLog);
		std::cout << infoLog;
		return 0;
	}
	return shaderID;
}
