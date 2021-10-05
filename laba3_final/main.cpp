#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

#define TASK_CONST 10

int GetNumOfRows(vector<vector<int>>& Matrix) {
	int rows;

	for (int i = 0; i < Matrix.size(); i++) {
		if (Matrix[i].size() < Matrix[0].size()) {
			return Matrix[i].size() * 2 + 1;
		}
		if (Matrix[i].size() > Matrix[0].size()) {
			return Matrix[0].size() * 2 + 1;
		}
	}
	return Matrix[0].size() * 2;
}

vector<bool> GetDefaultVec(int Columns) {
	vector<bool> StartsWithTen;

	for (int i = 0; i < Columns; i++) {
		if ( !(i % 2) ) {
			StartsWithTen.push_back(true);
			continue;
		}
		StartsWithTen.push_back(false);
	}

	return StartsWithTen;
}

vector<vector<int>> Read(int& columns) {
	int variant;
	cout << "cin 1 if you want to insert an array or cin 2 if you want to work with random array." << endl;
	cin >> variant;
	while (variant != 1 && variant != 2) {
		cout << "Invalid input, try again" << endl;
		cin >> variant;
	}

	int row;
	cout << "cin the number of columns in the array <= 10: " << endl;
	cin >> row;
	cout << "cin the number of rows in the array <=10: " << endl;
	cin >> columns;

	while (row < 0 || row > 10 || columns < 1 || columns > 10) {
		cout << "Invalid input, try again";
		cin >> row;
		cin >> columns;
	}

	vector<vector<int>> Matrix;
	if (variant == 1) {
		cout << "cin the array:" << endl;
		int input;

		for (int i = 0; i < row; i++) {
			vector<int> Column;
			Matrix.push_back(Column);
			for (int j = 0; j < columns; j++) {
				if (!((i + j) % 2)) {
					continue;
				}
				cin >> input;
				Matrix[i].push_back(input);
			}
		}
	}
	else {
		for (int i = 0; i < row; i++) {
			vector<int> Column;
			Matrix.push_back(Column);
			for (int j = 0; j < columns; j++) {
				if (!((i + j) % 2)) {
					continue;
				}
				Matrix[i].push_back(rand() % 10 - 3);
			}
		}
	}

	return Matrix;
}

int GetElement(int i, int j, vector<bool>& StartsWithTen, vector<vector<int>>& Matrix) {
	if ((StartsWithTen[i] == true) && (j % 2 == 0)) return TASK_CONST;
	if ((StartsWithTen[i] == false) && (j % 2 == 1)) return TASK_CONST;

	int skip = 0;
	if (StartsWithTen[i] == true) {
		for (int k = 0; k < j; k++) {
			if (k % 2 == 0) {
				skip++;
			}
		}
	}
	else {
		for (int k = 0; k < j; k++) {
			if (k % 2 == 1) {
				skip++;
			}
		}
	}

	return Matrix[i][j - skip];
}

void Write(vector<vector<int>>& Matrix, vector<bool> StartsWithTen) {
	int rows = GetNumOfRows(Matrix);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < Matrix.size(); j++) {
			cout << setw(2) << GetElement(j, i, StartsWithTen, Matrix) << " ";
		}
		cout << endl;
	}
}

int GetSumOfColumn(int column, vector<bool>& StartsWithTen, vector<vector<int>>& Matrix) {
	int rows = GetNumOfRows(Matrix);
	int sum = 0;

	for (int i = 0; i < rows; i++) {
		if (i < Matrix[column].size()) {
			sum += Matrix[column][i];
		}
		else {
			sum += TASK_CONST;
		}
	}

	return sum;
}

void Restruct(vector<vector<int>>& Matrix, vector<bool>& StartsWithTen) {
	for (int i = 0; i < Matrix.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < Matrix.size(); j++) {
			if (GetSumOfColumn(min, StartsWithTen, Matrix) > GetSumOfColumn(j, StartsWithTen, Matrix)) {
				min = j;
			}
		}
		if (min != i) {
			swap(Matrix[i], Matrix[min]);
			swap(StartsWithTen[i], StartsWithTen[min]);
		}
	}
}

string FindFullyPositiveRow(vector<vector<int>>& Matrix, vector<bool>& StartsWithTen) {
	for (int i = 0; i < GetNumOfRows(Matrix); i++) {
		bool isPositive = true;
		for (int j = 0; j < Matrix.size(); j++) {
			if (GetElement(j, i, StartsWithTen, Matrix) < 0) {
				isPositive = false;
				break;
			}
		}
		if (isPositive == true) {
			return to_string(i);
		}
	}

	return "there is no such rows";
}

int main()
{
	int columns = 0;
	vector<vector<int>> Matrix = Read(columns);
	cout << endl << "our full array: " << endl;
	Write(Matrix, GetDefaultVec(TASK_CONST));

	vector<bool> StartsWithTen = GetDefaultVec(TASK_CONST);
	Restruct(Matrix, StartsWithTen);
	cout << endl << "array after changing of columns:" << endl;
	Write(Matrix, StartsWithTen);
    cout << endl << "number of positive row: ";
	cout << FindFullyPositiveRow(Matrix, StartsWithTen);

	return 0;
}
