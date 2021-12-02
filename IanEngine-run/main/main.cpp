#include <IanEngine.h>

int main() {
    
    try {
        Cube xAxis = Cube({0.0f, 0.0f, 0.0f}, 20.0, 0.05, 0.05);
        Cube yAxis = Cube({0.0f, 0.0f, 0.0f}, 0.05, 20.0, 0.05);
        Cube zAxis = Cube({0.0f, 0.0f, 0.0f}, 0.05, 0.05, 20.0);
    
        int i;
        for (i=0; i < 1000; i++) {
            Cube cub= Cube({-3 + (i*0.01), 0.0f, 2.0 - (i*0.01)}, 1.0, 1.0, 1.0);
        }
        
        RenderEngine_API app;
     
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}