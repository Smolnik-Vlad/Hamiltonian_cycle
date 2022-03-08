
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


bool cycle_find(int **matrix, int x, int y, int step, vector<int> way, int vertex,  vector<int>& result)
{
	way.push_back(vertex);
	if (step == x-1)
	{
		result = way;
		result.push_back(way[0]);
		for (int i = 0; i < y; i++) {
			if (matrix[i][way[0]] != 0 && matrix[i][vertex] != 0) 
				{

					return true;
				}
		}

		return false;
		
	}
	vector<int> child_vertex;
	for (int i = 0; i < y; i++)
	{
		if (matrix[i][vertex] != 0)
		{
			for (int j = 0; j < x; j++)
			{
				if (j != vertex && matrix[i][j]!=0 && find(way.begin(), way.end(), j)==way.end())
				{
					child_vertex.push_back(j);
					break;
				}
			}
		}
	}

	for (int i = 0; i < child_vertex.size(); i++)
	{
		bool success = cycle_find(matrix, x, y, step + 1, way, child_vertex[i], result);
		if (success == 1)
		{
			return (1);
		}
	}
	return false;

};


int main()
{
	ifstream fileo;
	fileo.open("input.txt");
	int size_y, size_x;
	fileo >> size_y; fileo >> size_x;

	int** inc_matrix = new int* [size_y];
	for (int i = 0; i < size_y; i++)
	{
		inc_matrix[i] = new int[size_x];
	}

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			fileo >> inc_matrix[i][j];
		}
	}
	fileo.close();

	vector<int> result;
	if (cycle_find(inc_matrix, size_x, size_y, 0, vector<int>(), 0, result))
	{
		for (int i = 0; i < size_x + 1; i++)
		{
			cout << result[i] ;
			if (i != size_x ) {
				cout << "->";
			}
		}
	}
	else cout << "Fu*k";

	for (int i = 0; i < size_y; i++) {
		delete[] inc_matrix[i];
	}

	delete[] inc_matrix;
}
