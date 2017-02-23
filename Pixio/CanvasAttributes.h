#pragma once

#include "Math/Vector.h"
#include <string>

struct CanvasAttributes
{
    CanvasAttributes(const Vec2& position, const Vec2& size, std::string name);
    Vec2        position;
    Vec2        size;
    std::string name;
};