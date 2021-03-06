/*
 * ################################################################################
 *
 *      _______ __
 *     /_  __(_) /__
 *      / / / / / _ \
 *     / / / / /  __/
 *    /_/ /_/_/\___/
 *
 *    Tile Class Declaration
 *    MASH Team
 *    January 2017
 *
 * ################################################################################
*/

#ifndef TILE_MACRO
#define TILE_MACRO

#include <vector>
#include <memory>

#include "MACRO-DEBUG.hpp"

class human;

using humanP = std::unique_ptr<human>;

class tile {

public:
  tile();
  ~tile();

private:

  std::vector<humanP>                 Humans;

};

#endif
