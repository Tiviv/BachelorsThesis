#pragma once

class Matrix3f
{
public:
	Matrix3f(){}
	Matrix3f(float inpMatrix[3][3])
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] = inpMatrix[i][j];
			}
		}
	}

	inline Matrix3f& operator=(const Matrix3f& rhs)
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

	inline Matrix3f& operator+(const Matrix3f& rhs)
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

	inline Matrix3f& operator-(const Matrix3f& rhs)
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

	inline Matrix3f& operator*(const Matrix3f& rhs)
	{
		Matrix3f newMatrix;

		for (int row = 0; row < matrixSize; row++)
		{
			for (int col = 0; col < matrixSize; col++)
			{
				newMatrix.matrix[row][col] = matrix[row][0] * rhs.matrix[0][col] +
											 matrix[row][1] * rhs.matrix[1][col] +
											 matrix[row][2] * rhs.matrix[2][col];
			}
		}

		*this = newMatrix;
		return *this;
	}

	inline Matrix3f& initIdentity()
	{
		matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;
		matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;
		matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
 		return *this;
	}



private:
	float matrix[3][3];
	static const int matrixSize;
};