#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec2 texcord;

layout (std140, binding = 0) uniform Matrices
{
    mat4 view;
    mat4 project;
};

uniform mat4 model;

out vec2 texcrd;
out vec3 Normal;
out vec3 FragPos;

void main()
{
    texcrd = texcord;

    FragPos = vec3(model * vec4(position, 1.0));
    Normal = mat3(transpose(inverse(model))) * normals;

    gl_Position = project * view * vec4(FragPos, 1.0);
}