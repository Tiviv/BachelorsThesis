#include "stdafx.h"
#include "CppUnitTest.h"

#include "Math/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define EPS 0.0000001f

namespace MathUnitTest
{		
	TEST_CLASS(TestVec2)
	{
	public:
		
		TEST_METHOD(VectorAddition)
		{
            Vec2 v1(8.0f, 13.0f);
			Vec2 v2(26.0f, 7.0f);

			auto result = v1 + v2;

			Assert::AreEqual(34.0f, result.x, EPS);
			Assert::AreEqual(20.0f, result.y, EPS);

			auto result2 = v2 + v1;

			Assert::AreEqual(result.x, result2.x, EPS);
			Assert::AreEqual(result.y, result2.y, EPS);

			v1 += v2;
			Assert::AreEqual(v1.x, result.x, EPS);
			Assert::AreEqual(v1.y, result.y, EPS);
		}

		TEST_METHOD(VectorSubtraction)
		{
			Vec2 v1(12.0f, 2.0f);
			Vec2 v2(4.0f, 5.0f);

			auto result = v1 - v2;

			Assert::AreEqual(8.0f, result.x, EPS);
			Assert::AreEqual(-3.0f, result.y, EPS);
		}

		TEST_METHOD(VectorSet)
		{
			const auto resultX = 8.0f;
			const auto resultY = 13.0f;

			Vec2 v1(resultX, resultY);
			Vec2 v2(26.0f, 7.0f);
			Vec2 v3(4.0f, 5.0f);

			v3 = v2 = v1;

			Assert::AreEqual(resultX, v2.x, EPS);
			Assert::AreEqual(resultX, v3.x, EPS);

			Assert::AreEqual(resultY, v2.y, EPS);
			Assert::AreEqual(resultY, v3.y, EPS);
		}

		TEST_METHOD(VectorScalarMultiplication)
		{
			Vec2 v1(7.0f, 3.0f);
			float scalar = 3.0f;

			auto result = v1 * scalar;

			Assert::AreEqual(21.0f, result.x, EPS);
			Assert::AreEqual(9.0f, result.y, EPS);

			v1 *= scalar;

			Assert::AreEqual(v1.x, result.x, EPS);
			Assert::AreEqual(v1.y, result.y, EPS);
		}

		TEST_METHOD(VectorDotProduct)
		{
			Vec2 v1(-6.0f, 8.0f);
			Vec2 v2(5.0f, 12.0f);

			auto result = dot(v1, v2);

			Assert::AreEqual(66.0f, result, EPS);
		}
	};
}