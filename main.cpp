#include"sale.h"
//Ö÷º¯Êý

int main()
{
	int n;
	while (true)
	{
		switch (mainSelect())
		{
		case 1:
			while (n = salesmanManage())
			{
				Salesman* p = nullptr;
				switch (n)
				{
				case 1:
					Add(p);
					continue;
				case 2:
					Check(p);
					continue;
				case 3:
					Alter(p);
					continue;
				case 4:
					Delete(p);
					continue;
				case 5:
					Traverse(p);
					continue;
				case 0:
					break;
				}
			}
			break;
		case 2:
			while (n = productManage())
			{
				Product* p=nullptr;
				switch (n)
				{
				case 1:
					Add(p);
					continue;
				case 2:
					Check(p);
					continue;
				case 3:
					Alter(p);
					continue;
				case 4:
					Delete(p);
					continue;
				case 5:
					Traverse(p);
					continue;
				case 0:
					break;
				}
			}
			break;
		case 3:
			while (n = sellerManage())
			{
				Producer* p=nullptr;
				switch (n)
				{
				case 1:
					Add(p);
					continue;
				case 2:
					Check(p);
					continue;
				case 3:
					Alter(p);
					continue;
				case 4:
					Delete(p);
					continue;
				case 5:
					Traverse(p);
					continue;
				case 0:
					break;
				}
			}
			break;
		case 4:
			while (n = customerManage())
			{
				Customer* p=nullptr;
				switch (n)
				{
				case 1:
					Add(p);
					continue;
				case 2:
					Check(p);
					continue;
				case 3:
					Alter(p);
					continue;
				case 4:
					Delete(p);
					continue;
				case 5:
					Traverse(p);
					continue;
				case 0:
					break;
				}
			}
			break;
		case 5:
			while (n = marketManage())
			{
				Market* p=nullptr;
				switch (n)
				{
				case 1:
					Add(p);
					continue;
				case 2:
					Check(p);
					continue;
				case 3:
					Alter(p);
					continue;
				case 4:
					Delete(p);
					continue;
				case 5:
					Traverse(p);
					continue;
				case 0:
					break;
				}
			}
			break;
		case 0:
			return 0;
		}
	}
	return 0;
}
