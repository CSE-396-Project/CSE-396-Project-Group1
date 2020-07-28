#include "cube.h"

using namespace godot;

void Cube::_register_methods() {
    register_method("_process", &Cube::_process);
}

Cube::Cube() {
}

Cube::~Cube() {
    // add your cleanup here
}

void Cube::_init() {
    // initialize any variables here
    time_passed = 0.0;
}

void Cube::_process(float delta) {
    time_passed += delta;

    Vector3 new_position = Vector3(1,1,1);

    Transform t = get_transform();
    t.origin += new_position;
    set_transform(t);
}