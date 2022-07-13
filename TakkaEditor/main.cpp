#include <Application.h>
#include <Shader.h>
#include <Video/VAO.h>

class App : public Takka::Application
{
public:
    App() : Application("test", 500, 500)
    {

    }

    void Setup() override
    {
        /*Takka::Shader sh;
        Takka::VAO vao;
        sh.CreateProgram(
            Takka::ReadFile("../TakkaEngineCore/Shaders/Vertex.glsl"), 
            Takka::ReadFile("../TakkaEngineCore/Shaders/Fragment.glsl"));

        vao.AddEBO(Takka::EBO(Takka::Array<GLuint>({0,1,2,2,1,3})));
        vao.AddVBO(Takka::VBO(Takka::Array<GLfloat>({
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f })));*/
    }

    void Update() override
    {

    }

    void Render() override
    {
        //vao.Draw(sh);
    }

private:
    
};

int main()
{
    std::cout << "Hello Takka" << std::endl;    

    App p;
    p.Run();
}