#ifndef __TYPES_H__
#define __TYPES_H__

#include<optional>

typedef int State;
typedef double Cost;
typedef double Heuristic;
typedef State Action;
typedef double Priority;

struct StateInfo {
	State state;
	std::optional<State> predecessor;
	Cost pathCost;
	Heuristic heuristic;
};
#endif // !__TYPES_H__
