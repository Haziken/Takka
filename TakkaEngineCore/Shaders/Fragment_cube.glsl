#version 460 core

out vec4 color;

in vec2 texcrd;
in vec3 Normal;
in vec3 FragPos;

struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light
{
    vec4 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Material material;
uniform Light light;
uniform vec3 viewPos;

void main()
{
    float attenuation = 1.0;

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, texcord));

    vec3 norm = normalize(Normal);
    if(light.position.w == 0.0)
    {
        vec3 lightDir = normalize(light.position.xyz);
    }
    else if (light.position.w == 1.0)
    {

        float dis = length(light.position.xyz - FragPos);

        attenuation = 1.0 / (light.constant + light.linear * dis + light.quadratic * (dis * dis));

        vec3 lightDir = normalize(light.position - FragPos);
    }
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texcord));

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 refDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, refDir), 0.0f), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texcrd));

    vec3 result = ambient + diffuse + specular;
    result = result * attenuation;
    color = vec4(result, 1.0f);
}