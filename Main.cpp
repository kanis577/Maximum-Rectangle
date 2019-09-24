#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
struct Point
{
	int x;
	int y;
};

int GetArea(Point pRed, Point pBle)
{
	int nArea = 0;

	// 算法 follow pdf
	int nWidth	= pBle.x - pRed.x;	
	int nHeight = pRed.y - pBle.y;

	if (nWidth < 0) nWidth		= 0;
	if (nHeight < 0) nHeight	= 0;

	nArea = nWidth * nHeight;

	return  nArea;
}

bool IsInteger(double dInput)
{
	double b = pow(10, -6.0);
	if ((dInput - (int)dInput < b) && (dInput - (int)dInput > -b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsInRange(double nInput)
{
	if (nInput >= 4294697295)
	{
		return false;
	}
	return true;
}


int main()
{
	int nRedPointSet = 4;
	int nBlePointSet = 4;
	std::cout << "Red set : ";
	std::cin >> nRedPointSet;

	std::cout << "Blue set : ";
	std::cin >> nBlePointSet;

	std::vector<int>	vArea;
	std::vector<Point>	vRed;
	std::vector<Point>	vBle;

	vRed.resize(nRedPointSet);
	vBle.resize(nBlePointSet);
	std::cout << std::endl;
	std::cout << "Point Set of Red : " << std::endl;
	for (int i = 0; i < nRedPointSet; i++)
	{
		double dInput = 0.0;

		while (true)
		{
			std::cout << "X: ";
			std::cin >> dInput;

			if (IsInRange(dInput) && IsInteger(dInput))
			{
				vRed[i].x = (int)dInput;
				break;
			}
			else
			{
				std::cout << "Over range OR Not a Integer, input again" << std::endl;
			}
		}

		while (true)
		{
			std::cout << "Y: ";
			std::cin >> dInput;

			if (IsInRange(dInput) && IsInteger(dInput))
			{
				vRed[i].y = (int)dInput;
				break;
			}
			else
			{
				std::cout << "Over range OR Not a Integer, input again" << std::endl;
			}
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Point Set of Blue : " << std::endl;
	for (int i = 0; i < nBlePointSet; i++)
	{
		double dInput = 0.0;

		while (true)
		{
			std::cout << "X: ";
			std::cin >> dInput;

			if (IsInRange(dInput) && IsInteger(dInput))
			{
				vBle[i].x = (int)dInput;
				break;
			}
			else
			{
				std::cout << "Over range OR Not a Integer, input again" << std::endl;
			}
		}

		while (true)
		{
			std::cout << "Y: ";
			std::cin >> dInput;

			if (IsInRange(dInput) && IsInteger(dInput))
			{
				vBle[i].y = (int)dInput;
				break;
			}
			else
			{
				std::cout << "Over range OR Not a Integer, input again" << std::endl;
			}
			std::cout<<std::endl;
		}
	}
	for (int i = 0; i < vRed.size(); i++)
	{
		std::cout << "Red " << i + 1 << " : " << vRed[i].x << " " << vRed[i].y << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < vBle.size(); i++)
	{
		std::cout << "Blue " << i + 1 << " : " << vBle[i].x << " " << vBle[i].y << std::endl;
	}

	for (int i = 0; i < vRed.size(); i++)
	{
		for (int j = 0; j < vBle.size(); j++)
		{
			int nArea = 0;
			nArea = GetArea(vRed[i], vBle[j]);
			vArea.push_back(nArea);
		}
	}

	std::sort(vArea.begin(), vArea.end());

	std::cout << std::endl << std::endl;
	std::cout << "OUTPUT:" << std::endl;
	std::cout << "Maximum Area is " << vArea[vArea.size() - 1];
	std::cout << std::endl;

	system("pause");
	return 0;
}
