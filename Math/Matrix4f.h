#pragma once
#pragma once

class Matrix4f
{
public:
	Matrix4f() {}
	Matrix4f(float inpMatrix[3][3])
	{
		for (int i = 0; i < matrixSize; i++)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[i][j] = inpMatrix[i][j];
			}
		}
	}

	inline Matrix4f& operator=(const Matrix4f& rhs)
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

	inline Matrix4f& operator+(const Matrix4f& rhs)
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

	inline Matrix4f& operator-(const Matrix4f& rhs)
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

	inline Matrix4f& operator*(const Matrix4f& rhs)
	{
		Matrix4f newMatrix;

		for (int row = 0; row < matrixSize; row++)
		{
			for (int col = 0; col < matrixSize; col++)
			{
				newMatrix.matrix[row][col] = matrix[row][0] * rhs.matrix[0][col] +
											 matrix[row][1] * rhs.matrix[1][col] +
											 matrix[row][2] * rhs.matrix[2][col] +
											 matrix[row][3] * rhs.matrix[3][col];
			}
		}

		*this = newMatrix;
		return *this;
	}

	inline Matrix4f& initIdentity()
	{
		matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
		matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0;
		matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0;
		matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;
		return *this;
	}


private:
	float matrix[4][4];
	static const int matrixSize;
};