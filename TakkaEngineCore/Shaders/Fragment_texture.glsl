#version 460 core

out vec4 color;
in vec2 texcrd;

uniform sampler2D diffuse1;

void main()
{
    color = vec4(texcrd, 0.0f, 1.0f); //texture(diffuse1, texcrd);
}