#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/catalog.h"
#include "../main-project/processing.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{

	catalog* build_subscription(double cost1, unsigned int quan1, char category1[15])
	{
		catalog* prod = new catalog;
		prod->cost = cost1;
		prod->quan = quan1;
		prod->category = category1;
		return prod;
	}

	//       
	void delete_subscription(catalog* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}



	TEST_CLASS(unittestproject)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			catalog* prod[3];
			prod[0] = build_subscription(10, 2, "Продукты");
			prod[1] = build_subscription(11, 1, "Промтовары");
			prod[2] = build_subscription(5, 4, "Прдукты");
			Assert::AreEqual(40.0, process(prod, 3, "Продукты"));
			delete_subscription(prod, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			catalog* prod[3];
			prod[0] = build_subscription(112, 2, "Промтовары");
			prod[1] = build_subscription(11, 1, "Продукты");
			prod[2] = build_subscription(7, 4, "Промтовары");
			Assert::AreEqual(11.0, process(prod, 3, "Продукты"));
			delete_subscription(prod, 3);
		}
		TEST_METHOD(TestMethod3)
		{
			catalog* prod[3];
			prod[0] = build_subscription(15, 6, "Сладости");
			prod[1] = build_subscription(31, 1, "Сладости");
			prod[2] = build_subscription(7, 4, "Сладости");
			Assert::AreEqual(128.0, process(prod, 3, "Сладости"));
			delete_subscription(prod, 3);
		}
	};
}