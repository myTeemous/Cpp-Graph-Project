#include <utility>

#include "PriorityQ.h"
#include "Types.h"

bool PriorityQ::PrioritySetElem::operator<(const PrioritySetElem& other) const
{
	return std::tie(priority, state) < std::tie(other.priority, other.state);
}

bool PriorityQ::isEmpty() const
{
	return _prioritySet.empty();
}

PriorityQ::MapTuple PriorityQ::pop()
{
	// find minimum in set
	
	auto setPos = _prioritySet.begin();
	auto elem = *setPos;

	// remove from set
	
	_prioritySet.erase(setPos);

	// remove from map
	
	auto mapPos = _infoMap.find(elem.state);
	auto tuple = (*mapPos).second;
	//auto tuple = mapPos->second;   <-- same as the line above
	_infoMap.erase(mapPos);

	//return the right thing
	
	return tuple;
}

bool PriorityQ::contains(const State& state) const
{
	return _infoMap.find(state) != _infoMap.end();
}

void PriorityQ::push(const PriorityQ::MapTuple& tuple)
{
	auto priority = std::get<0>(tuple);
	auto state = std::get<1>(tuple);

	PrioritySetElem elem{ priority, state };
	_prioritySet.insert(elem);

	_infoMap.insert({ state, tuple });
}

PriorityQ::MapTuple PriorityQ::get(const State& state) const
{
	auto pos = _infoMap.find(state);
	return pos->second;
}

PriorityQ::MapTuple PriorityQ::remove(const State& state)
{
	auto mapPos = _infoMap.find(state);
	auto tuple = mapPos->second;
	_infoMap.erase(mapPos);

	//auto [priority, state, info] = tuple;

	auto priority = std::get<0>(tuple);
	auto info = std::get<2>(tuple);

	auto setPos = _prioritySet.find({ priority, state });
	_prioritySet.erase(setPos);

	return tuple;
}