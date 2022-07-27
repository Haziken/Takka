#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 cord;

out vec2 coord;

void main()
{
    gl_Position = vec4(position, 1.0f);
    coord = cord;
}