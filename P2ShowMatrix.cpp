

const int ROWS = 5;
const int COLS = 5;

void showMatrix(array[ROWS][COLS])
{
	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLS; ++j)
		{
			cout << array[i][j] << "\t";
		}
	}

	cout << endl;
}



