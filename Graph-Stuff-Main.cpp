#include <iostream>
#include <tuple>
#include "Types.h"
#include "PriorityQ.h"

using namespace std;

int main() 
{
	PriorityQ myPQ;

	myPQ.push({ 3.0, 5, {5, {}, 100.0, 45.3} });
	myPQ.push({ -2.0, 2, {2, {}, 10.0, 6.3} });
	myPQ.push({ 1.0, 1, {1, {}, 80.0, 20.1} });

	{
		auto tuple = myPQ.pop();
		cout << "priority = " << std::get<0>(tuple) << endl;
	}

	{
		auto tuple = myPQ.pop();
		cout << "priority = " << std::get<0>(tuple) << endl;
	}

	{
		auto tuple = myPQ.pop();
		cout << "priority = " << std::get<0>(tuple) << endl;
	}
	/*
	SearchProblemBuilder spBuilder;

	spBuilder
		.addTransitions(
			{1, 2, 1, 0}
		)
		.setStartState(1)
		.addGoalState(4)
		.addStateHeuristics({
			{1, 4, 0},
			{1, 2, 0}
			});

	SearchProblem searchProblem = spBuilder.build();

	vector<tuple<string, Solver>> solverInfos{
		{"DFS", Dfs(searchProblem)},
		{"BFS", Bfs(searchProblem)},
	};

	for (auto info : solverInfos) {
		auto solverName = std::<0>(info);
		auto Solver& solver = std::<1>(info);

		cout << "========" << solverName << "========" << endl;
		
		auto solution = solver.solve();

		cout << "solutionWasFound = "
			<< boolAlpha
			<< solution.getSolutionWasFound()
			<< endl;

		cout << "path = " << endl;
		//print path
	}




	cout << "hello world" << endl;
	*/
	cin.get();
}
