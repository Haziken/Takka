#include <Application.h>
#include <Shader.h>
#include <Video/VAO.h>
#include <Camera.h>
#include <Texture.h>
#include <algorithm>
#include <Logger.h>
#include <EventManager.h>
#include <Object.h>

class App : public Takka::Application
{
public:
    App() : Application("test", 500, 500)
    {
        EVENTMANAGER->Init(this->GetWindow()->GetWindow());
    }

    void Setup() override
    {
        cam = new Takka::Camera(500,500, {-4, 3, 2});
        cam->SetYaw(-30);
        cam->SetPitch(-30);
        sh.CreateProgram(
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Vertex.glsl"), 
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Fragment.glsl"));

        tex.LoadTexture("../../TakkaEngineCore/Textures/texture1.jpg");


        vao.AddVBO(Takka::VBO(Takka::Array<GLfloat>({
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.5f,
            -0.5f,  0.5f, 0.5f,
             0.5f, -0.5f, 0.5f,
             0.5f,  0.5f, 0.5f, })));

        vao.AddEBO(Takka::EBO(Takka::Array<GLuint>({ 
            0,1,2,1,2,3,
            3,2,6,6,7,3,
            7,6,4,4,7,5,
            5,4,1,1,4,0,
            0,4,2,2,4,6,
            7,5,3,3,1,5 })));

        vao.AddAttribPointer(0, 3, 3 * sizeof(GLfloat));
        //vao.AddAttribPointer(1, 2, 5 * sizeof(GLfloat), 3 * sizeof(GLfloat));
    }

    void Update() override
    {
        if (EVENTMANAGER->GetState(GLFW_KEY_W) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() + cam->GetFront());
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_S) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() - cam->GetFront());
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_A) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() - cam->GetRight());
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_D) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() + cam->GetRight());
        }
    }

    void Render() override
    {
        cam->LoadMatrixInShader(sh);
        sh.LoadUniformData("model", glm::mat4(1.0));
        //sh.LoadUniformData("project", glm::mat4(1.0));
        //sh.LoadUniformData("view", glm::mat4(1.0));
        //tex.Activate(GL_TEXTURE0);
        //tex.Bind();
        vao.Draw(sh);
    }

private:
    Takka::Texture tex;
    Takka::Shader sh;
    Takka::VAO vao;
    Takka::Camera* cam;
};

int main()
{
    std::cout << "Hello Takka" << std::endl;
    App p;
    p.Run();
}