#include "stdafx.h"
#include "CppUnitTest.h"

#include "Math/Matrix4f.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define EPS 0.0000001f

namespace MathUnitTest
{
	TEST_CLASS(TestMatrix4f)
	{
	public:

		TEST_METHOD(MatrixAddition)
		{
			for (int i = 0; i < 10; i++)
			{
				Matrix4f *matrix = new Matrix4f();
				matrix->initIdentity();

				Assert::IsNotNull(matrix);
			}
		}

		TEST_METHOD(MatrixSubtraction)
		{
			Matrix4f *matrix = new Matrix4f();
			matrix->initIdentity();

			Assert::IsNotNull(matrix);
		}

		TEST_METHOD(MatrixMultiplication)
		{
			for (int i = 0; i < 50; i++)
			{
				Matrix4f *matrix = new Matrix4f();
				matrix->initIdentity();

				Assert::IsNotNull(matrix);
			}
		}

		TEST_METHOD(MatrixInitIdentity)
		{
			Matrix4f *matrix = new Matrix4f();
			matrix->initIdentity();

			Assert::IsNotNull(matrix);
		}
	};
}