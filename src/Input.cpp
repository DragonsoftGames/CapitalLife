#include "Input.hpp"

bool Input::isKeyPressed(SDL_Scancode key)
{
    return keys[key];
}

Vec2 Input::getInputDirection()
{
    Vec2 input = Vec2::Zero;

    // Keyboard input
    if (Input::isKeyPressed(CALI_INPUT_KEY_FORWARD))
    {
        input.y -= 1.0f;
    }
    if (Input::isKeyPressed(CALI_INPUT_KEY_LEFT))
    {
        input.x -= 1.0f;
    }
    if (Input::isKeyPressed(CALI_INPUT_KEY_BACK))
    {
        input.y += 1.0f;
    }
    if (Input::isKeyPressed(CALI_INPUT_KEY_RIGHT))
    {
        input.x += 1.0f;
    }

    return input;
}
