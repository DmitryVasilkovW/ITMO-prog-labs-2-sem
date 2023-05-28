#include "Cube.h"

void Cube::LoadFromFile(std::string filename)
{
	char colour;

	std::ifstream fin(filename);

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fin >> colour;
			cube[Top][i][k] = colour;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Left][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Front][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Right][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Back][i][j] = colour;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fin >> colour;
			cube[Bottom][i][k] = colour;
		}
	}
}

void Cube::printt()
{
	std::cout << "       " << cube[Top][0][0] << cube[Top][0][1] << cube[Top][0][2] << "\n";
	std::cout << "       " << cube[Top][1][0] << cube[Top][1][1] << cube[Top][1][2] << "\n";
	std::cout << "       " << cube[Top][2][0] << cube[Top][2][1] << cube[Top][2][2] << "\n";
	std::cout << "\n";

	std::cout << cube[Left][0][0] << cube[Left][0][1] << cube[Left][0][2] << "  ";
	std::cout << cube[Front][0][0] << cube[Front][0][1] << cube[Front][0][2] << "  ";
	std::cout << cube[Right][0][0] << cube[Right][0][1] << cube[Right][0][2] << "  ";
	std::cout << cube[Back][0][0] << cube[Back][0][1] << cube[Back][0][2] << "\n";

	std::cout << cube[Left][1][0] << cube[Left][1][1] << cube[Left][1][2] << "  ";
	std::cout << cube[Front][1][0] << cube[Front][1][1] << cube[Front][1][2] << "  ";
	std::cout << cube[Right][1][0] << cube[Right][1][1] << cube[Right][1][2] << "  ";
	std::cout << cube[Back][1][0] << cube[Back][1][1] << cube[Back][1][2] << "\n";

	std::cout << cube[Left][2][0] << cube[Left][2][1] << cube[Left][2][2] << "  ";
	std::cout << cube[Front][2][0] << cube[Front][2][1] << cube[Front][2][2] << "  ";
	std::cout << cube[Right][2][0] << cube[Right][2][1] << cube[Right][2][2] << "  ";
	std::cout << cube[Back][2][0] << cube[Back][2][1] << cube[Back][2][2] << "\n";
	std::cout << "\n";

	std::cout << "       " << cube[Bottom][0][0] << cube[Bottom][0][1] << cube[Bottom][0][2] << "\n";
	std::cout << "       " << cube[Bottom][1][0] << cube[Bottom][1][1] << cube[Bottom][1][2] << "\n";
	std::cout << "       " << cube[Bottom][2][0] << cube[Bottom][2][1] << cube[Bottom][2][2] << "\n";
}

void Cube::turnMatrix(int facet, bool cw)
{
	char facet_matrix[3][3];
	char side_col_matrix[3][4];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			facet_matrix[i][j] = cube[facet][i][j];
		}
	}

	if (cw)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[facet][j][2 - i] = facet_matrix[i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[facet][2 - j][i] = facet_matrix[i][j];
			}
		}
	}

	if (facet == Front)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][2][j];
			side_col_matrix[j][1] = cube[Right][j][0];
			side_col_matrix[j][2] = cube[Bottom][0][j];
			side_col_matrix[j][3] = cube[Left][j][2];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][0] = side_col_matrix[i][0];
				cube[Bottom][0][i] = side_col_matrix[2 - i][1];
				cube[Left][i][2] = side_col_matrix[i][2];
				cube[Top][2][i] = side_col_matrix[2 - i][3];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][0] = side_col_matrix[2 - i][2];
				cube[Bottom][0][i] = side_col_matrix[i][3];
				cube[Left][i][2] = side_col_matrix[2 - i][0];
				cube[Top][2][i] = side_col_matrix[i][1];
			}
		}
	}
	else if (facet == Back)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][0][j];
			side_col_matrix[j][1] = cube[Right][j][2];
			side_col_matrix[j][2] = cube[Bottom][2][j];
			side_col_matrix[j][3] = cube[Left][j][0];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][2] = side_col_matrix[2 - i][2];
				cube[Bottom][2][i] = side_col_matrix[i][3];
				cube[Left][i][0] = side_col_matrix[2 - i][0];
				cube[Top][0][i] = side_col_matrix[i][1];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][2] = side_col_matrix[i][0];
				cube[Bottom][2][i] = side_col_matrix[2 - i][1];
				cube[Left][i][0] = side_col_matrix[i][2];
				cube[Top][0][i] = side_col_matrix[2 - i][3];
			}
		}
	}
	else if (facet == Right)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][j][2];
			side_col_matrix[j][1] = cube[Front][j][2];
			side_col_matrix[j][2] = cube[Bottom][j][2];
			side_col_matrix[j][3] = cube[Back][j][0];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][2] = side_col_matrix[i][1];
				cube[Front][i][2] = side_col_matrix[i][2];
				cube[Bottom][i][2] = side_col_matrix[2 - i][3];
				cube[Back][i][0] = side_col_matrix[2 - i][0];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][2] = side_col_matrix[2 - i][3];
				cube[Front][i][2] = side_col_matrix[i][0];
				cube[Bottom][i][2] = side_col_matrix[i][1];
				cube[Back][i][0] = side_col_matrix[2 - i][2];
			}
		}
	}
	else if (facet == Left)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][j][0];
			side_col_matrix[j][1] = cube[Front][j][0];
			side_col_matrix[j][2] = cube[Bottom][j][0];
			side_col_matrix[j][3] = cube[Back][j][2];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][0] = side_col_matrix[2 - i][3];
				cube[Front][i][0] = side_col_matrix[i][0];
				cube[Bottom][i][0] = side_col_matrix[i][1];
				cube[Back][i][2] = side_col_matrix[2 - i][2];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][0] = side_col_matrix[i][1];
				cube[Front][i][0] = side_col_matrix[i][2];
				cube[Bottom][i][0] = side_col_matrix[2 - i][3];
				cube[Back][i][2] = side_col_matrix[2 - i][0];
			}
		}
	}
	else if (facet == Top)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Back][0][j];
			side_col_matrix[j][1] = cube[Right][0][j];
			side_col_matrix[j][2] = cube[Front][0][j];
			side_col_matrix[j][3] = cube[Left][0][j];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][0][i] = side_col_matrix[i][3];
				cube[Right][0][i] = side_col_matrix[i][0];
				cube[Front][0][i] = side_col_matrix[i][1];
				cube[Left][0][i] = side_col_matrix[i][2];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][0][i] = side_col_matrix[i][1];
				cube[Right][0][i] = side_col_matrix[i][2];
				cube[Front][0][i] = side_col_matrix[i][3];
				cube[Left][0][i] = side_col_matrix[i][0];
			}
		}
	}
	else if (facet == Bottom)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Back][2][j];
			side_col_matrix[j][1] = cube[Right][2][j];
			side_col_matrix[j][2] = cube[Front][2][j];
			side_col_matrix[j][3] = cube[Left][2][j];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][2][i] = side_col_matrix[i][1];
				cube[Right][2][i] = side_col_matrix[i][2];
				cube[Front][2][i] = side_col_matrix[i][3];
				cube[Left][2][i] = side_col_matrix[i][0];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][2][i] = side_col_matrix[i][3];
				cube[Right][2][i] = side_col_matrix[i][0];
				cube[Front][2][i] = side_col_matrix[i][1];
				cube[Left][2][i] = side_col_matrix[i][2];
			}
		}
	}
}

void Cube::F(bool cw)
{
	turnMatrix(Front, cw);
	if (cw)
		mass.push_back("F");
	else
		mass.push_back("F'");
}

void Cube::B(bool cw)
{
	turnMatrix(Back, cw);
	if (cw)
		mass.push_back("B");
	else
		mass.push_back("B'");
}

void Cube::L(bool cw)
{
	turnMatrix(Left, cw);
	if (cw)
		mass.push_back("L");
	else
		mass.push_back("L'");
}

void Cube::R(bool cw)
{
	turnMatrix(Right, cw);
	if (cw)
		mass.push_back("R");
	else
		mass.push_back("R'");
}

void Cube::U(bool cw)
{
	turnMatrix(Top, cw);
	if (cw)
		mass.push_back("U");
	else
		mass.push_back("U'");
}

void Cube::D(bool cw)
{
	turnMatrix(Bottom, cw);
	if (cw)
		mass.push_back("D");
	else
		mass.push_back("D'");
}

void Cube::Mixing()
{
	for (int i = 0; i < 10; i++)
	{
		int randNumber = rand() % 6;
		if (randNumber == 0)
		{
			F();
			std::cout << "F" << std::endl;
		}
		else if (randNumber == 1)
		{
			B();
			std::cout << "B" << std::endl;
		}
		else if (randNumber == 2)
		{
			L();
			std::cout << "L" << std::endl;
		}
		else if (randNumber == 3)
		{
			R();
			std::cout << "R" << std::endl;
		}
		else if (randNumber == 4)
		{
			U();
			std::cout << "U" << std::endl;
		}
		else if (randNumber == 5)
		{
			D();
			std::cout << "D" << std::endl;
		}
	}
}

void Cube::input_Mixing()
{
	int Number;
	std::cin >> Number;
	if (Number == 0)
	{
		F();
		std::cout << "F" << std::endl;
	}
	else if (Number == 1)
	{
		B();
		std::cout << "B" << std::endl;
	}
	else if (Number == 2)
	{
		L();
		std::cout << "L" << std::endl;
	}
	else if (Number == 3)
	{
		R();
		std::cout << "R" << std::endl;
	}
	else if (Number == 4)
	{
		U();
		std::cout << "U" << std::endl;
	}
	else if (Number == 5)
	{
		D();
		std::cout << "D" << std::endl;
	}
}


std::vector<std::string> Cube::cubeSolve()
{
	char topColour = cube[Top][1][1];
	bool crossReady = true;
	bool cornersReady = true;

	while (true)
	{
		getCross();

		getCentreCubes();

		getCornerCubes();

		if (!checkCentreCubes() || !checkCentreCubes() || !checkCross())
			continue;

		getSecondLayer();

		getBottonCross();

		if (!checkBottomCross())
			continue;

		if (!checkCentreCubes() || !checkCentreCubes() || !checkCross())
			continue;

		getSideCubesBottomLayer();

		if (!checkSideCubesBottomLayer())
			continue;

		getCornerCubesBottomLayer();

		if (!checkCornerCubesBottomLayer())
			continue;

		getThirdLayer();

		if (!checkThirdLayer() || !checkLastLayer())
			continue;

		break;
	}
	return mass;
}

void Cube::getCross()
{
	bool crossReady;
	char topColour = cube[Top][1][1];
	while (true)
	{
		crossReady = true;
		int count = 0;

		if (cube[Bottom][0][1] == topColour)
		{
			while (cube[Top][2][1] == topColour)
			{
				if (count > 3)
					break;
				U();
				count++;
			}
			if (count <= 3)
			{
				F();
				F();
			}
			count = 0;
		}
		if (cube[Bottom][1][0] == topColour)
		{
			while (cube[Top][1][0] == topColour)
			{
				if (count > 3)
					break;
				U();
				count++;
			}
			if (count <= 3)
			{
				L();
				L();
			}
			count = 0;
		}
		if (cube[Bottom][1][2] == topColour)
		{
			while (cube[Top][1][2] == topColour)
			{
				if (count > 3)
					break;
				U();
				count++;
			}
			if (count <= 3)
			{
				R();
				R();
			}
			count = 0;
		}
		if (cube[Bottom][2][1] == topColour)
		{
			while (cube[Top][0][1] == topColour)
			{
				if (count > 3)
					break;
				U();
				count++;
			}
			if (count <= 3)
			{
				B();
				B();
			}
			count = 0;
		}

		for (int i = Front; i <= Right; i++)
		{
			if (cube[i][2][1] == topColour)
			{
				if (i == Front)
				{
					while (cube[Top][2][1] == topColour)
					{
						if (count > 3)
							break;
						U();
						count++;
					}
					if (count <= 3)
					{
						F(0);
						U(0);
						R();
						U();
					}
				}
				else if (i == Back)
				{
					while (cube[Top][0][1] == topColour)
					{
						if (count > 3)
							break;
						U();
						count++;
					}
					if (count <= 3)
					{
						B(0);
						U(0);
						L();
						U();
					}
				}
				else if (i == Right)
				{
					while (cube[Top][1][2] == topColour)
					{
						if (count > 3)
							break;
						U();
						count++;
					}
					if (count <= 3)
					{
						R(0);
						U(0);
						B();
						U();
					}
				}
				else if (i == Left)
				{
					while (cube[Top][1][0] == topColour)
					{
						if (count > 3)
							break;
						U();
						count++;
					}
					if (count <= 3)
					{
						L(0);
						U(0);
						F();
						U();
					}
				}
			}

			count = 0;

			if (cube[i][1][0] == topColour || cube[i][1][2] == topColour)
			{
				if (cube[i][1][0] == topColour)
				{
					if (i == Front)
					{
						while (cube[Top][1][0] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							L(0);
						}
					}
					else if (i == Back)
					{
						while (cube[Top][1][2] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							R(0);
						}
					}
					else if (i == Right)
					{
						while (cube[Top][2][1] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							F(0);
						}
					}
					else if (i == Left)
					{
						while (cube[Top][0][1] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							B(0);
						}
					}
				}

				count = 0;

				if (cube[i][1][2] == topColour)
				{
					if (i == Front)
					{
						while (cube[Top][1][2] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							R();
						}
					}
					else if (i == Back)
					{
						while (cube[Top][1][0] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							L();
						}
					}
					else if (i == Right)
					{
						while (cube[Top][0][1] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							B();
						}
					}
					else if (i == Left)
					{
						while (cube[Top][2][1] == topColour)
						{
							if (count > 3)
								break;
							U();
							count++;
						}
						if (count <= 3)
						{
							F();
						}
					}
				}
			}

			count = 0;

			if (cube[i][0][1] == topColour)
			{
				if (i == Front)
				{
					F();
					U(0);
					R();
					U();
				}
				else if (i == Back)
				{
					B();
					U(0);
					L();
					U();
				}
				else if (i == Right)
				{
					R();
					U(0);
					B();
					U();
				}
				else if (i == Left)
				{
					L();
					U(0);
					F();
					U();
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != 1 && j != 1)
					continue;
				if (cube[Top][i][j] != topColour)
				{
					crossReady = false;
					break;
				}
			}
			if (!crossReady)
				break;
		}
		if (crossReady)
			break;
	}
}

void Cube::getSecondLayer()
{
	char downColour = cube[Bottom][1][1];
	char topColour = cube[Top][1][1];

	int facet;
	char colour_1 = -100;
	char colour_2 = -100;

	while (true)
	{
		colour_1 = -100;

		if (cube[Bottom][0][1] != downColour && cube[Front][2][1] != downColour)
		{
			facet = Front;
			colour_1 = cube[Bottom][0][1];
			colour_2 = cube[Front][2][1];
		}
		else if (cube[Bottom][1][0] != downColour && cube[Left][2][1] != downColour)
		{
			facet = Left;
			colour_1 = cube[Bottom][1][0];
			colour_2 = cube[Left][2][1];
		}
		else if (cube[Bottom][1][2] != downColour && cube[Right][2][1] != downColour)
		{
			facet = Right;
			colour_1 = cube[Bottom][1][2];
			colour_2 = cube[Right][2][1];
		}
		else if (cube[Bottom][2][1] != downColour && cube[Back][2][1] != downColour)
		{
			facet = Back;
			colour_1 = cube[Bottom][2][1];
			colour_2 = cube[Back][2][1];
		}

		if (colour_1 == -100 || colour_1 == topColour)
			break;
		while (colour_2 != cube[facet][1][1])
		{
			D();
			if (facet == Front)
				facet = Right;
			else if (facet == Right)
				facet = Back;
			else if (facet == Back)
				facet = Left;
			else if (facet == Left)
				facet = Front;
		}

		if (facet == Front)
		{
			if (cube[Right][1][1] == colour_1)
			{
				D(0);
				R(0);
				D();
				R();
				D();
				F();
				D(0);
				F(0);
			}
			else if (cube[Left][1][1] == colour_1)
			{
				D();
				L();
				D(0);
				L(0);
				D(0);
				F(0);
				D();
				F();
			}
		}
		else if (facet == Right)
		{
			if (cube[Back][1][1] == colour_1)
			{
				D(0);
				B(0);
				D();
				B();
				D();
				R();
				D(0);
				R(0);
			}
			else if (cube[Front][1][1] == colour_1)
			{
				D();
				F();
				D(0);
				F(0);
				D(0);
				R(0);
				D();
				R();
			}
		}
		else if (facet == Back)
		{
			if (cube[Left][1][1] == colour_1)
			{
				D(0);
				L(0);
				D();
				L();
				D();
				B();
				D(0);
				B(0);
			}
			else if (cube[Right][1][1] == colour_1)
			{
				D();
				R();
				D(0);
				R(0);
				D(0);
				B(0);
				D();
				B();
			}
		}
		else if (facet == Left)
		{
			if (cube[Front][1][1] == colour_1)
			{
				D(0);
				F(0);
				D();
				F();
				D();
				L();
				D(0);
				L(0);
			}
			else if (cube[Back][1][1] == colour_1)
			{
				D();
				B();
				D(0);
				B(0);
				D(0);
				L(0);
				D();
				L();
			}
		}

		if (cube[Front][1][0] == cube[Left][1][1] && cube[Left][1][2] == cube[Front][1][1])
		{
			D();
			L();
			D(0);
			L(0);
			D(0);
			F(0);
			D();
			F();
		}
		else if (cube[Front][1][2] == cube[Right][1][1] && cube[Right][1][0] == cube[Front][1][1])
		{
			D(0);
			R(0);
			D();
			R();
			D();
			F();
			D(0);
			F(0);
		}
		else if (cube[Back][1][0] == cube[Right][1][1] && cube[Right][1][2] == cube[Back][1][1])
		{
			D();
			R();
			D(0);
			R(0);
			D(0);
			B(0);
			D();
			B();
		}
		else if (cube[Back][1][2] == cube[Left][1][1] && cube[Left][1][0] == cube[Back][1][1])
		{
			D(0);
			L(0);
			D();
			L();
			D();
			B();
			D(0);
			B(0);
		}
		if (checkSecondLayer())
			break;
	}
}

void Cube::getCentreCubes()
{
	while (true)
	{
		if (cube[Front][0][1] == cube[Front][1][1] && cube[Right][0][1] == cube[Right][1][1])
		{
			if (cube[Back][0][1] == cube[Back][1][1] && cube[Left][0][1] == cube[Left][1][1])
				break;
			B();
			U();
			B(0);
			U(0);
			B();
			break;
		}
		if (cube[Front][0][1] == cube[Front][1][1] && cube[Left][0][1] == cube[Left][1][1])
		{
			if (cube[Back][0][1] == cube[Back][1][1] && cube[Right][0][1] == cube[Right][1][1])
				break;
			R();
			U();
			R(0);
			U(0);
			R();
			break;
		}
		if (cube[Back][0][1] == cube[Back][1][1] && cube[Right][0][1] == cube[Right][1][1])
		{
			if (cube[Front][0][1] == cube[Front][1][1] && cube[Left][0][1] == cube[Left][1][1])
				break;
			L();
			U();
			L(0);
			U(0);
			L();
			break;
		}
		if (cube[Back][0][1] == cube[Back][1][1] && cube[Left][0][1] == cube[Left][1][1])
		{
			if (cube[Front][0][1] == cube[Front][1][1] && cube[Right][0][1] == cube[Right][1][1])
				break;
			F();
			U();
			F(0);
			U(0);
			F();
			break;
		}

		if (cube[Front][0][1] == cube[Front][1][1] && cube[Back][0][1] == cube[Back][1][1])
		{
			if (cube[Right][0][1] == cube[Right][1][1] && cube[Left][0][1] == cube[Left][1][1])
				break;
			R();
			U();
			R(0);
			U(0);
			R();
		}

		if (cube[Right][0][1] == cube[Right][1][1] && cube[Left][0][1] == cube[Left][1][1])
		{
			B();
			U();
			B(0);
			U(0);
			B();
		}

		U();
	}
}

void Cube::getCornerCubes()
{
	char topColour = cube[Top][1][1];

	bool cornersReady;

	while (true)
	{
		if (!checkCentreCubes())
			break;
		cornersReady = true;

		for (int i = 0; i <= 2; i += 2)
		{
			for (int j = 0; j <= 2; j += 2)
			{
				if (cube[Bottom][i][j] == topColour)
				{
					char colour_1;
					char colour_2;
					int facet_1;
					int facet_2;

					if (i == 0 && j == 0)
					{
						colour_1 = cube[Front][2][0];
						colour_2 = cube[Left][2][2];
						facet_1 = Front;
						facet_2 = Left;
					}
					else if (i == 0 && j == 2)
					{
						colour_1 = cube[Right][2][0];
						colour_2 = cube[Front][2][2];
						facet_1 = Right;
						facet_2 = Front;
					}
					else if (i == 2 && j == 0)
					{
						colour_1 = cube[Left][2][0];
						colour_2 = cube[Back][2][2];
						facet_1 = Left;
						facet_2 = Back;
					}
					else if (i == 2 && j == 2)
					{
						colour_1 = cube[Back][2][0];
						colour_2 = cube[Right][2][2];
						facet_1 = Back;
						facet_2 = Right;
					}

					while (cube[facet_1][1][1] != colour_2 || cube[facet_2][1][1] != colour_1)
					{
						D();
						if (facet_1 == Front)
						{
							facet_1 = Right;
							facet_2 = Front;
						}
						else if (facet_1 == Right)
						{
							facet_1 = Back;
							facet_2 = Right;
						}
						else if (facet_1 == Back)
						{
							facet_1 = Left;
							facet_2 = Back;
						}
						else if (facet_1 == Left)
						{
							facet_1 = Front;
							facet_2 = Left;
						}
					}

					if (facet_1 == Front && facet_2 == Left)
					{
						F(0);
						D(0);
						D(0);
						F();
						D();
						F(0);
						D(0);
						F();
					}
					else if (facet_1 == Right && facet_2 == Front)
					{
						R(0);
						D(0);
						D(0);
						R();
						D();
						R(0);
						D(0);
						R();
					}
					else if (facet_1 == Back && facet_2 == Right)
					{
						B(0);
						D(0);
						D(0);
						B();
						D();
						B(0);
						D(0);
						B();
					}
					else if (facet_1 == Left && facet_2 == Back)
					{
						L(0);
						D(0);
						D(0);
						L();
						D();
						L(0);
						D(0);
						L();
					}
				}
			}
		}

		for (int k = Front; k <= Right; k++)
		{
			if (cube[k][2][0] == topColour || cube[k][2][2] == topColour)
			{
				if (cube[k][2][0] == topColour)
				{
					char colour_1;
					char colour_2;
					int facet_1;
					int facet_2;

					if (k == Front)
					{
						colour_1 = cube[Bottom][0][0];
						colour_2 = cube[Left][2][2];
						facet_1 = Front;
						facet_2 = Left;
					}
					else if (k == Right)
					{
						colour_1 = cube[Bottom][0][2];
						colour_2 = cube[Front][2][2];
						facet_1 = Right;
						facet_2 = Front;
					}
					else if (k == Back)
					{
						colour_1 = cube[Bottom][2][2];
						colour_2 = cube[Right][2][2];
						facet_1 = Back;
						facet_2 = Right;
					}
					else if (k == Left)
					{
						colour_1 = cube[Bottom][2][0];
						colour_2 = cube[Back][2][2];
						facet_1 = Left;
						facet_2 = Back;
					}
					while (cube[facet_1][1][1] != colour_1 || cube[facet_2][1][1] != colour_2)
					{
						D();
						if (facet_1 == Front)
						{
							facet_1 = Right;
							facet_2 = Front;
						}
						else if (facet_1 == Right)
						{
							facet_1 = Back;
							facet_2 = Right;
						}
						else if (facet_1 == Back)
						{
							facet_1 = Left;
							facet_2 = Back;
						}
						else if (facet_1 == Left)
						{
							facet_1 = Front;
							facet_2 = Left;
						}
					}
					if (facet_1 == Front && facet_2 == Left)
					{
						F(0);
						D(0);
						F();
						D();
					}
					else if (facet_1 == Right && facet_2 == Front)
					{
						R(0);
						D(0);
						R();
						D();
					}
					else if (facet_1 == Back && facet_2 == Right)
					{
						B(0);
						D(0);
						B();
						D();
					}
					else if (facet_1 == Left && facet_2 == Back)
					{
						L(0);
						D(0);
						L();
						D();
					}
				}

				if (cube[k][2][2] == topColour)
				{
					char colour_1;
					char colour_2;
					int facet_1;
					int facet_2;

					if (k == Front)
					{
						colour_1 = cube[Right][2][0];
						colour_2 = cube[Bottom][0][2];
						facet_1 = Right;
						facet_2 = Front;
					}
					else if (k == Right)
					{
						colour_1 = cube[Back][2][0];
						colour_2 = cube[Bottom][2][2];
						facet_1 = Back;
						facet_2 = Right;
					}
					else if (k == Back)
					{
						colour_1 = cube[Left][2][0];
						colour_2 = cube[Bottom][2][0];
						facet_1 = Left;
						facet_2 = Back;
					}
					else if (k == Left)
					{
						colour_1 = cube[Front][2][0];
						colour_2 = cube[Bottom][0][0];
						facet_1 = Front;
						facet_2 = Left;
					}
					while (cube[facet_1][1][1] != colour_1 || cube[facet_2][1][1] != colour_2)
					{
						D();
						if (facet_1 == Front)
						{
							facet_1 = Right;
							facet_2 = Front;
						}
						else if (facet_1 == Right)
						{
							facet_1 = Back;
							facet_2 = Right;
						}
						else if (facet_1 == Back)
						{
							facet_1 = Left;
							facet_2 = Back;
						}
						else if (facet_1 == Left)
						{
							facet_1 = Front;
							facet_2 = Left;
						}
					}
					if (facet_1 == Front && facet_2 == Left)
					{
						D(0);
						F(0);
						D();
						F();
					}
					else if (facet_1 == Right && facet_2 == Front)
					{
						D(0);
						R(0);
						D();
						R();
					}
					else if (facet_1 == Back && facet_2 == Right)
					{
						D(0);
						B(0);
						D();
						B();
					}
					else if (facet_1 == Left && facet_2 == Back)
					{
						D(0);
						L(0);
						D();
						L();
					}
				}
			}
		}


		for (int k = Front; k <= Right; k++)
		{
			if (cube[k][0][0] == topColour || cube[k][0][2] == topColour)
			{
				if (cube[k][0][0] == topColour)
				{
					if (k == Front)
					{
						F(0);
						U(0);
						F();
					}
					else if (k == Right)
					{
						R(0);
						U(0);
						R();
					}
					else if (k == Back)
					{
						B(0);
						U(0);
						B();
					}
					else if (k == Left)
					{
						L(0);
						U(0);
						L();
					}
				}
				if (cube[k][0][2] == topColour)
				{
					if (k == Front)
					{
						F();
						U();
						F(0);
					}
					else if (k == Right)
					{
						R();
						U();
						R(0);
					}
					else if (k == Back)
					{
						B();
						U();
						B(0);
					}
					else if (k == Left)
					{
						L();
						U();
						L(0);
					}

				}
			}
		}

		for (int i = Front; i <= Right; i++)
		{
			if (cube[i][0][0] != cube[i][0][1])
			{
				if (i == Front)
				{
					L();
					D();
					L(0);
				}
				else if (i == Right)
				{
					F();
					D();
					F(0);
				}
				else if (i == Back)
				{
					R();
					D();
					R(0);
				}
				else if (i == Left)
				{
					B();
					D();
					B(0);
				}
			}
			if (cube[i][0][2] != cube[i][0][1])
			{
				if (i == Front)
				{
					R(0);
					D(0);
					R();
				}
				else if (i == Right)
				{
					B(0);
					D(0);
					B();
				}
				else if (i == Back)
				{
					L(0);
					D(0);
					L();
				}
				else if (i == Left)
				{
					F(0);
					D(0);
					F();
				}
			}
		}


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != 1 && j != 1)
				{
					if (cube[Top][i][j] != topColour)
					{
						cornersReady = false;
						break;
					}
				}
			}
			if (cornersReady == false)
				break;
		}

		for (int i = Front; i <= Right; i++)
		{
			if (cube[i][0][0] != cube[i][0][2] || cube[i][0][0] != cube[i][1][1])
			{
				cornersReady = false;
				break;
			}
		}
		if (cornersReady == true)
			break;
	}
}

void Cube::getBottonCross()
{

	char downColour = cube[Bottom][1][1];
	int count_1 = 0;
	int count_2 = 0;

	for (int i = 0; i < 3; i++)
	{
		if (cube[Bottom][i][1] == downColour && i != 1)
			count_1++;
		if (cube[Bottom][1][i] == downColour && i != 1)
			count_2++;
	}

	if (count_1 == 2 && count_2 == 2)
		return;
	if (count_1 == 0 && count_2 == 0)
	{
		F();
		L();
		D();
		L(0);
		D(0);
		F(0);
	}
	if (count_1 == 2)
	{
		R();
		F();
		D();
		F(0);
		D(0);
		R(0);
	}
	else if (count_2 == 2)
	{
		B();
		R();
		D();
		R(0);
		D(0);
		B(0);
	}

	if (checkBottomCross())
		return;

	if (cube[Bottom][0][1] == downColour && cube[Bottom][1][0] == downColour)
	{
		B();
		R();
		D();
		R(0);
		D(0);
		B(0);
	}
	else if (cube[Bottom][0][1] == downColour && cube[Bottom][1][2] == downColour)
	{
		L();
		B();
		D();
		B(0);
		D(0);
		L(0);
	}
	else if (cube[Bottom][1][0] == downColour && cube[Bottom][2][1] == downColour)
	{
		R();
		F();
		D();
		F(0);
		D(0);
		R(0);
	}
	else if (cube[Bottom][2][1] == downColour && cube[Bottom][1][2] == downColour)
	{
		F();
		L();
		D();
		L(0);
		D(0);
		F(0);
	}
}

void Cube::getSideCubesBottomLayer()
{
	while (true)
	{
		while (cube[Front][2][1] != cube[Front][1][1])
		{
			D();
		}

		if (cube[Left][2][1] == cube[Left][1][1])
		{
			if (!checkSideCubesBottomLayer())
			{
				F();
				D();
				F(0);
				D();
				F();
				D();
				D();
				F(0);
				D();
			}
		}
		else if (cube[Right][2][1] == cube[Right][1][1])
		{
			if (!checkSideCubesBottomLayer())
			{
				R();
				D();
				R(0);
				D();
				R();
				D();
				D();
				R(0);
				D();
			}
		}
		else
		{
			L();
			D();
			L(0);
			D();
			L();
			D();
			D();
			L(0);
		}
		if (checkSideCubesBottomLayer())
			break;
	}
}

void Cube::getCornerCubesBottomLayer()
{
	char downColour = cube[Bottom][1][1];
	while (true)
	{
		if (cube[Front][2][2] == downColour)
		{
			U();
			R();
			U(0);
			R(0);
			U();
			R();
			U(0);
			R(0);
		}
		else if (cube[Right][2][0] == downColour)
		{
			R();
			U();
			R(0);
			U(0);
			R();
			U();
			R(0);
			U(0);
		}
		else
			D();
		if (checkCornerCubesBottomLayer())
			break;
	}
}

void Cube::getThirdLayer()
{
	char colour_1;
	char colour_2;

	while (!checkThirdLayer())
	{
		if (cube[Front][2][0] != cube[Front][2][1] && cube[Left][2][2] != cube[Left][2][1])
		{
			colour_1 = cube[Front][2][0];
			colour_2 = cube[Left][2][2];
			L(0);
			U();
			U();
			L();
			while (true)
			{
				if (colour_1 == 'W' || colour_2 == 'W')
					break;
				while (cube[Front][2][1] != colour_1 || cube[Left][2][1] != colour_2)
				{
					D(0);
				}
				colour_1 = cube[Front][2][0];
				colour_2 = cube[Left][2][2];
				L(0);
				U();
				U();
				L();
				if (checkThirdLayer())
					break;
			}
		}
		D(0);
	}

	while (!checkLastLayer())
	{
		D();
	}

}

bool Cube::checkLastLayer()
{
	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][2][1] != cube[i][1][1])
			return false;
	}
	return true;
}

bool Cube::checkCross()
{
	char topColour = cube[Top][1][1];

	bool crossReady = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 1 && j != 1)
				continue;
			if (cube[Top][i][j] != topColour)
			{
				crossReady = false;
				break;
			}
		}
		if (crossReady == false)
			break;
	}
	if (crossReady == true)
		return true;
	else
		return false;
}

bool Cube::checkSecondLayer()
{
	bool BottonCubesReady = true;

	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][1][0] != cube[i][1][1] || cube[i][1][2] != cube[i][1][1])
		{
			BottonCubesReady = false;
			break;
		}
	}
	if (BottonCubesReady)
		return true;
	else
		return false;
}



bool Cube::checkCentreCubes()
{
	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][1][1] != cube[i][0][1])
			return false;
	}
	return true;
}

bool Cube::checkBottomCross()
{
	bool BottomCrossReady = true;
	char downColour = cube[Bottom][1][1];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 1 && j != 1)
				continue;

			if (cube[Bottom][i][j] != downColour)
			{
				return false;
			}
		}
	}
	return true;
}

bool Cube::checkSideCubesBottomLayer()
{
	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][2][1] != cube[i][1][1])
		{
			return false;
		}
	}
	return true;
}

bool Cube::checkCornerCubesBottomLayer()
{
	char downColour = cube[Bottom][1][1];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cube[Bottom][i][j] != downColour)
				return false;
		}
	}

	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][2][1] != cube[i][1][1])
		{
			return false;
		}
	}

	return true;
}

bool Cube::checkThirdLayer()
{
	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][2][0] != cube[i][2][1] || cube[i][2][2] != cube[i][2][1])
			return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& out, Cube& cube)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << " ";

		std::cout << " ";

		for (int k = 0; k < 3; k++)
			std::cout << cube.cube[Top][i][k];
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Left][i][j];

		std::cout << " ";

		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Front][i][j];

		std::cout << " ";

		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Right][i][j];

		std::cout << " ";

		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Back][i][j];

		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << " ";

		std::cout << " ";

		for (int k = 0; k < 3; k++)
			std::cout << cube.cube[Bottom][i][k];
		std::cout << std::endl;
	}
	return out;
}

bool Cube::checkCornerCubes()
{
	bool cornersReady = true;

	for (int i = Front; i <= Right; i++)
	{
		if (cube[i][0][0] != cube[i][0][2] || cube[i][0][0] != cube[i][1][1])
		{
			cornersReady = false;
			break;
		}
	}
	if (cornersReady == true)
		return true;
	else
		return false;
}

bool Cube::checkState()
{
	centerCubes[{this->cube[Front][1][1], this->cube[Back][1][1]}]++;
	centerCubes[{this->cube[Top][1][1], this->cube[Bottom][1][1]}]++;
	centerCubes[{this->cube[Left][1][1], this->cube[Right][1][1]}]++;

	middleCubes[{this->cube[Front][0][1], this->cube[Top][2][1]}]++;
	middleCubes[{this->cube[Front][1][0], this->cube[Left][1][2]}]++;
	middleCubes[{this->cube[Front][2][1], this->cube[Bottom][0][1]}]++;
	middleCubes[{this->cube[Front][1][2], this->cube[Right][1][0]}]++;
	middleCubes[{this->cube[Top][0][1], this->cube[Back][0][1]}]++;
	middleCubes[{this->cube[Top][1][0], this->cube[Left][0][1]}]++;
	middleCubes[{this->cube[Top][1][2], this->cube[Right][0][1]}]++;
	middleCubes[{this->cube[Left][1][0], this->cube[Back][1][2]}]++;
	middleCubes[{this->cube[Left][2][1], this->cube[Bottom][1][0]}]++;
	middleCubes[{this->cube[Right][1][2], this->cube[Back][1][0]}]++;
	middleCubes[{this->cube[Right][2][1], this->cube[Bottom][1][2]}]++;
	middleCubes[{this->cube[Bottom][2][1], this->cube[Back][2][1]}]++;


	cornerCubes[{this->cube[Top][2][0], this->cube[Front][0][0], this->cube[Left][0][2]}]++;
	cornerCubes[{this->cube[Top][2][2], this->cube[Front][0][2], this->cube[Right][0][0]}]++;
	cornerCubes[{this->cube[Top][0][0], this->cube[Left][0][0], this->cube[Back][0][2]}]++;
	cornerCubes[{this->cube[Top][0][2], this->cube[Right][0][2], this->cube[Back][0][0]}]++;
	cornerCubes[{this->cube[Front][2][0], this->cube[Left][2][2], this->cube[Bottom][0][0]}]++;
	cornerCubes[{this->cube[Front][2][2], this->cube[Right][2][0], this->cube[Bottom][0][2]}]++;
	cornerCubes[{this->cube[Left][2][0], this->cube[Back][2][2], this->cube[Bottom][2][0]}]++;
	cornerCubes[{this->cube[Right][2][2], this->cube[Back][2][0], this->cube[Bottom][2][2]}]++;

	for (auto c : centerCubes)
		if (c.second != 1)
			return false;
	for (auto c : middleCubes)
		if (c.second != 1)
			return false;
	for (auto c : cornerCubes)
		if (c.second != 1)
			return false;

	return true;
}

Cube::Cube()
{

	int odd = 0;
	int even = 3;
	for (int color = 0; color < 6; color++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->cube[color][i][j] = colors[(color % 2 == 0 ? odd : even)];
			}
		}
		if (color % 2 == 0)
			odd++;
		else
			even++;
	}
}

