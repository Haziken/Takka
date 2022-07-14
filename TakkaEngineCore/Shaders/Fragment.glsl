#version 460 core

in vec3 mycol;

out vec4 color;

void main()
{
    color = vec4(mycol, 1.0f);
}