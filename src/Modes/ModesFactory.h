#pragma once

#include <memory>

#include "../ArgumentParser.h"
#include "Mode.h"

std::unique_ptr<Mode> CreateMode(const ArgumentParser &argParser);
