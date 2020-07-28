#ifndef CUBE_H
#define CUBE_H

#include <Godot.hpp>
#include <MeshInstance.hpp>

namespace godot {

class Cube : public MeshInstance {
    GODOT_CLASS(Cube, MeshInstance)

private:
    float time_passed;

public:
    static void _register_methods();

    Cube();
    ~Cube();

    void _init(); // our initializer called by Godot

    void _process(float delta);
};

}

#endif