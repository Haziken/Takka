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
       
        md.LoadModel("../../bg.obj");

        cam = Takka::Camera(800,600);
        cam.SetPosition(glm::vec3(0, 0, 3));
        cam.SetYaw(270);
        model = glm::mat4(1.0f);

        sh.CreateProgram(
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Vertex_cube.glsl"), 
            Takka::ReadFile("../../TakkaEngineCore/Shaders/Fragment_cube.glsl"));
    }



    void Update(float delta) override
    {
        if (EVENTMANAGER->GetState(GLFW_KEY_W) == GLFW_PRESS)
        {
            cam.SetPosition(cam.GetPosition() + cam.GetFront() * 0.01f * delta);
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_S) == GLFW_PRESS)
        {
            cam.SetPosition(cam.GetPosition() - cam.GetFront() * 0.01f * delta);
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_A) == GLFW_PRESS)
        {
            cam.SetPosition(cam.GetPosition() - cam.GetRight() * 0.01f * delta);
        }
        if (EVENTMANAGER->GetState(GLFW_KEY_D) == GLFW_PRESS)
        {
            cam.SetPosition(cam.GetPosition() + cam.GetRight() * 0.01f * delta);
        }
    }

    void CursorPosition(double x, double y) override
    {
        GLfloat offsetX = x - lastX, offsetY = y - lastY;
        lastX = x;
        lastY = y;

        cam.SetPitch(cam.GetPitch() - offsetY * 0.1);
        cam.SetYaw(cam.GetYaw() + offsetX * 0.1);

    }

    void KeyPress(int key, int mode) override
    {
        if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(GetWindow()->GetWindow(), GLFW_TRUE);
    }

    void Render() override
    {
        cam.LoadMatrixInShader(sh, "view", "project");
        sh.LoadUniformData("model", model);
        md.Draw(sh);
    }

private:
    Takka::Shader sh;
    glm::mat4 model;
    Takka::Camera cam;
    GLfloat lastX, lastY;
    Takka::Model md;
};

int main()
{
    LOGGER->Init("DUMP.txt");
    App p;
    p.Run();
}