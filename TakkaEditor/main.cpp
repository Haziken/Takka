#include <Application.h>
#include <Shader.h>
#include <Video/VAO.h>
#include <Camera.h>

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

        vao.LoadElementData(Takka::Array<GLuint>({ 0,1,2,2,1,3 }), GL_STATIC_DRAW);
        vao.LoadVertexData(Takka::Array<GLfloat>({
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f }), GL_STATIC_DRAW);

        vao.AddAttribPointer(0, 3, 6 * sizeof(GLfloat));
        vao.AddAttribPointer(1, 3, 6 * sizeof(GLfloat), 3 * sizeof(GLfloat));
    }

    void Update() override
    {

    }

    void Render() override
    {
        vao.Draw(sh);
    }

private:
    Takka::Shader sh;
    Takka::VAO vao;
};

int main()
{
    std::cout << "Hello Takka" << std::endl;    

    App p;
    p.Run();
}