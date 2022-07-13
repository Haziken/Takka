#version 460 core

layout (location=0) vec3 position;

void main()
{
    gl_Position = vec4(pos, 1.0f);
}