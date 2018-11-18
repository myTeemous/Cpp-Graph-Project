#ifndef __PRIORITYQ_H__
#define __PRIORITY_H__

#include <set>
#include <map>

#include "Types.h"

class PriorityQ
{
public:
	typedef std::tuple<Priority, State, StateInfo> MapTuple;
	
	struct PrioritySetElem {
		const Priority priority;
		const State state;

		bool operator<(const PrioritySetElem& other) const;
	};

	PriorityQ() = default;
	PriorityQ(const PriorityQ& orig) = default;
	PriorityQ(PriorityQ&& orig) = delete;
	PriorityQ& operator=(const PriorityQ& orig) = default;
	~PriorityQ() = default;

	bool isEmpty() const;
	MapTuple pop();
	void push(const MapTuple& thing);

	bool contains(const State& state) const;

	MapTuple get(const State& state) const;
	MapTuple remove(const State& state);

private:
	std::set<PrioritySetElem> _prioritySet;
	std::map<State, MapTuple> _infoMap;
};

#endif // !__PRIORITYQ_H__

