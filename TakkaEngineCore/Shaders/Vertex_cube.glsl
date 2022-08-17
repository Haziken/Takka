#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec2 texcord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 project;

out vec2 texcrd;

void main()
{
    texcrd = texcord;
    gl_Position = project * view * model * vec4(position, 1.0f);
}