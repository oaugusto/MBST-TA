#ifndef MST_H
#define MST_H

#include <limits.h>
#include "types.h"
#include "graph.h"

#define INF INT_MAX

W_t mst_prim(graph *g);

#endif