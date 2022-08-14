#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 p;

uniform mat4 model;
uniform mat4 view;
uniform mat4 project;

void main()
{
    gl_Position = project * view * model * vec4(position, 1.0f);
}