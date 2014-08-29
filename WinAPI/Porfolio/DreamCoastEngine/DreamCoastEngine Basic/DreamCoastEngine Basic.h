#pragma once

#include "resource.h"
#include "World.h"
#include "WorldRenderer.h"

// global var
World world(10, 10);
WorldRenderer worldRenderer(&world);