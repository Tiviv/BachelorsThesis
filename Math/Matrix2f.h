#pragma once

class Matrix2f
{
public:
	Matrix2f(){}
	Matrix2f(float inpMatrix[2][2])
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] = inpMatrix[i][j];
			}
		}
	}

	inline Matrix2f& operator=(const Matrix2f& rhs)
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] = rhs.matrix[i][j];
			}
		}
		return *this;

	}

	inline Matrix2f& operator+(const Matrix2f& rhs)
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] += rhs.matrix[i][j];
			}
		}
		return *this;
	}

	inline Matrix2f& operator-(const Matrix2f& rhs)
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] -= rhs.matrix[i][j];
			}
		}
		return *this;
	}

	inline Matrix2f& operator*(const Matrix2f& rhs)
	{
		Matrix2f newMatrix;

		for (int row = 0; row < matrixSize; row++)
		{
			for (int col = 0; col < matrixSize; col++)
			{
				newMatrix.matrix[row][col] = matrix[row][0] * rhs.matrix[0][col] +
							       matrix[row][1] * rhs.matrix[1][col];
			}
		}

		*this = newMatrix;
		return *this;
	}

	inline Matrix2f& initIdentity()
	{
		matrix[0][0] = 1; matrix[0][1] = 0;
		matrix[1][0] = 0; matrix[1][1] = 1;
		return *this;
	}

private:
	float matrix[2][2];
	static const int matrixSize = 2;
};