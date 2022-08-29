#include "Input.hpp"

bool Input::isKeyPressed(SDL_Scancode key)
{
    return keys[key];
}