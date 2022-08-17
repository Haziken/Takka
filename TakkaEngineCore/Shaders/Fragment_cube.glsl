#version 460 core

out vec4 color;
in vec2 texcrd;

uniform sampler2D diffuse1;

void main()
{
    color = texture(diffuse1, texcrd);
}