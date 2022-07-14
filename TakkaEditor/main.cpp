#include <Application.h>
#include <Shader.h>
#include <Video/VAO.h>

class App : public Takka::Application
{
public:
    App() : Application("test", 500, 500)
    {

    }

    struct point
    {
        GLfloat x, y, z;
    };

    void Setup() override
    {
        sh.CreateProgram(
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Vertex.glsl"), 
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Fragment.glsl"));

        ebo.LoadData(Takka::Array<GLuint>({ 0,1,2,2,1,3 }), GL_STATIC_DRAW);
        ebo.SetIndices(6);
        vbo.LoadData(Takka::Array<GLfloat>({
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f }), GL_STATIC_DRAW);

        vao.AddEBO(ebo);
        vao.AddVBO(vbo);
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
    Takka::EBO ebo;
    Takka::VBO vbo;
};

int main()
{
    std::cout << "Hello Takka" << std::endl;    

    App p;
    p.Run();
}