#include <Application.h>
#include <Shader.h>
#include <Video/VAO.h>
#include <Camera.h>
#include <Texture.h>
#include <algorithm>
#include <Logger.h>

class App : public Takka::Application
{
public:
    App() : Application("test", 500, 500)
    {

    }

    void Setup() override
    {
        sh.CreateProgram(
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Vertex.glsl"), 
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Fragment.glsl"));

        tex.LoadTexture("../../TakkaEngineCore/Textures/texture1.jpg");


        vao.AddVBO(Takka::VBO(Takka::Array<GLfloat>({
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f })));

        vao.AddEBO(Takka::EBO(Takka::Array<GLuint>({ 0,1,2,2,1,3 })));

        vao.AddAttribPointer(0, 3, 5 * sizeof(GLfloat));
        vao.AddAttribPointer(1, 2, 5 * sizeof(GLfloat), 3 * sizeof(GLfloat));
    }

    void Update() override
    {

    }

    void Render() override
    {
        tex.Activate(GL_TEXTURE0);
        tex.Bind();
        vao.Draw(sh);
    }

private:
    Takka::Texture tex;
    Takka::Shader sh;
    Takka::VAO vao;
};


int main()
{
    std::cout << "Hello Takka" << std::endl;    
    App p;
    p.Run();
}