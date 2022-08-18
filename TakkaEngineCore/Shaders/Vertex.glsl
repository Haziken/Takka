#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 p;

uniform mat4 model;
layout (std140, binding = 0) uniform Matrices
{
    mat4 view;
    mat4 project;
};

void main()
{
    gl_Position = project * view * model * vec4(position, 1.0f);
}