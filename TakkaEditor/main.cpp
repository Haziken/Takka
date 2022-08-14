#include <Application.h>
#include <Shader.h>
#include <Video/VAO.h>
#include <Camera.h>
#include <Texture.h>
#include <algorithm>
#include <Logger.h>
#include <EventManager.h>
#include <Model.h>

class App : public Takka::Application, public virtual Takka::Event
{
public:
    App() : Application("test", 800, 600), Event()
    {
        EVENTMANAGER->Init(this->GetWindow()->GetWindow());
    }

    void Setup() override
    {
        lastX = 400; lastY = 300;
        EVENTMANAGER->SetInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);
       
        md.LoadModel("../../RoomModel/Room.obj");

        cam = new Takka::Camera(800,600);
        cam->SetPosition(glm::vec3(0, 0, 3));
        cam->SetYaw(270);
        model = glm::mat4(1.0f);

        sh.CreateProgram(
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Vertex.glsl"), 
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Fragment.glsl"));

        Takka::Texture t;

        tex.LoadTexture("../../TakkaEngineCore/Textures/texture1.jpg");

        vao.AddVBO(Takka::VBO(Takka::Array<GLfloat>({
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f })));

        vao.AddAttribPointer(0, 3, 5 * sizeof(GLfloat));
        vao.AddAttribPointer(1, 2, 5 * sizeof(GLfloat), 3 * sizeof(GLfloat));
    }



    void Update(float delta) override
    {
        if (EVENTMANAGER->GetState(GLFW_KEY_W) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() + cam->GetFront() * 0.01f * delta);
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_S) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() - cam->GetFront() * 0.01f * delta);
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_A) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() - cam->GetRight() * 0.01f * delta);
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_D) == GLFW_PRESS)
        {
            cam->SetPosition(cam->GetPosition() + cam->GetRight() * 0.01f * delta);
        }
        //model = glm::rotate(model, glm::radians(0.1f * delta), glm::vec3(0.0,1.0,0.0));
    }

    void CursorPosition(double x, double y) override
    {
        GLfloat offsetX = x - lastX, offsetY = y - lastY;
        lastX = x;
        lastY = y;

        cam->SetPitch(cam->GetPitch() - offsetY * 0.1);
        cam->SetYaw(cam->GetYaw() + offsetX * 0.1);

    }

    void KeyPress(int key, int mode) override
    {
        if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(GetWindow()->GetWindow(), GLFW_TRUE);
    }

    void Render() override
    {
        cam->LoadMatrixInShader(sh, "view", "project");
        sh.LoadUniformData("model", model);
        md.Draw(sh);
    }

private:
    Takka::Texture tex;
    Takka::Shader sh;
    Takka::VAO vao;
    glm::mat4 model;
    Takka::Camera* cam;
    GLfloat lastX, lastY;
    Takka::Model md;
};

int main()
{
    std::cout << "Hello Takka" << std::endl;
    App p;
    p.Run();
}