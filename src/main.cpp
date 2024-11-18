#include <Framer/Camera.h>

#include "Framer/Framer.h"
#include "imgui.h"
#include "glm/gtc/type_ptr.hpp"

int main() {

    fr::Window window(800, 800, "Framer-Project");


    glm::vec3 color{1.0f};

    glEnable(GL_DEPTH_TEST);
    while (window.IsRunning()) {
        window.ShowFPS();
        window.BegimFrame();

        ImGui::Begin("Settings");
        ImGui::ColorPicker3("Color", glm::value_ptr(color));
        if (ImGui::Checkbox("VSync", &VSync)) {
            window.SetVSync(VSync);
        }

        if (!ImGui::IsWindowHovered())
            camera.OnUpdate();

        ImGui::End();

        shader.Bind();
        VAO.Bind();

        shader.uni3f("u_Color" , color.r, color.g, color.b);
        shader.uni4mat("u_Proj", glm::value_ptr(camera.GetProjectionMatrix()));
        shader.uni4mat("u_View", glm::value_ptr(camera.GetViewMatrix()));;

        glDrawElements(GL_TRIANGLES, sizeof(cubeIndices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);



        window.EndFrame();
    }
}
