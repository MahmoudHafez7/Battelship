#include "grid.h"
#include <stdbool.h>
#include <stdio.h>
#include "cs136-trace.h"

const bool HORIZONTAL = false;
const bool VERTICAL = true;



// grid_get_cell(g, x, y) determines the status of a cell (x, y)
// note: returns  1 if (x, y) contains a boat
//       returns  0 if (x, y) does not contain a boat and within bounds
//       returns -1 if (x, y) is out of bounds



// see grid.h
int grid_get_cell(const struct grid *g, int x, int y) {
  int cell_status = (x + (y * 10));
  int hundrend = 100;
  int minus_one = -1;
  if(minus_one < cell_status < hundrend) {
    if (g->cell[cell_status]){
      return 1;
    } else {
      return -1;
    }
  }
  else {
      return -1;
  }
}


// grid_print(g) prints the grid g

void grid_print(const struct grid *g) {
  printf("   0 1 2 3 4 5 6 7 8 9\n");
  int grid = 65;
  for (int i = 0; i < 100; ++i) {
    if (i == 0) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 10) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 20) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 30) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 40) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 50) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 60) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 70) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 80) {
      printf("%c ", grid);
      ++grid;
    }
    if (i == 90) {
      printf("%c ", grid);
      ++grid;
    }
    printf("%c", 124);

    if (g->cell[i]) {
      printf("%c", 120);
    } else {
      printf("%c", 32);
    } if (i == 9) {
      printf("%c\n", 124);
    }
    if (i == 19) {
      printf("%c\n", 124);
    }
    if (i == 29) {
      printf("%c\n", 124);
    }
    if (i == 39) {
      printf("%c\n", 124);
    }
    if (i == 49) {
      printf("%c\n", 124);
    }
    if (i == 59) {
      printf("%c\n", 124);
    }
    if (i == 69) {
      printf("%c\n", 124);
    }
    if (i == 79) {
      printf("%c\n", 124);
    }
    if (i == 89) {
      printf("%c\n", 124);
    }
    if (i == 99) {
      printf("%c\n", 124);
    }
  }
}


// grid_is_complete(g) checks if the grid g is complete or not
// requires: g is valid [not asserted]
bool grid_is_complete(const struct grid *g) {
  int one =g->total_ships[3];
  int two = g->total_ships[2];
  int three = g->total_ships[1];
  int four = g->total_ships[0];
  if (one == 1 && two == 2 && three == 3 && 4 == four) {
    return true;
  }
    return false;
}


static bool grid_add_ship_helper(int x, int y, bool a[]) {
  bool boundaries = (x < 10 && y==0 );
  bool boundaries_2 =(x == 0 && y < 10);
  if (boundaries || boundaries_2) {
    return false;
  } else if (a[x - 11 + y * 10 ]) {
    return true;
    } else {
      return false;
  }
}


// grid_add_ship(g, x, y, size, orientation) adds a ship to the grid
// requires: g is valid [not asserted]
// effects: modifies *g

bool grid_add_ship(struct grid *g, int x, int y, int size, bool orientation) {
  bool false_1 =  !orientation && 10 - size < x;
  bool false_2 = size > 4;
  bool false_4 = size < 1;
  bool false_5 = g->total_ships[size - 1] + size == 5;
  bool false_6 = grid_add_ship_helper(x, y, g->cell);
  bool false_7 = orientation &&
              grid_add_ship_helper(x, y + size - 1, g->cell);
  bool false_8 = (!orientation &&
             grid_add_ship_helper(x + size - 1, y, g->cell));

  if (false_1 || false_2 || false_4 || false_5 ||
      false_6 || false_7 || false_8 )  {
    return false;
  } else {
     ++g->total_ships[size - 1];

    if (!orientation) {
      for (int i = 0; i < size;   ++i) {
        g->cell[y * 10 + x + i] = true;
      }
    } else {
      for (int i = 0; i < size * 10;i = i + 10) {
        g->cell[y * 10 + x + i] = true;
      }
    }
    return true;
  }
}
