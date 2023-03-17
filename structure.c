#include"manage.h"

int main()
{
	//文件
	File();

	//系统
	int input1 = 1, input2 = 0, pass = 0;
	do
	{
		if (pass == 0)
			pass = PassMenu();
		else if (pass == 1)
		{
			AdMainMenu();
			scanf("%d", &input1);
			switch (input1)
			{
			case 1:
				SystemInformation();
				break;
			case 2:
				do
				{
					AdUserManageMenu();
					scanf("%d", &input2);
					switch (input2)
					{
					case 1:
						AdChangeUserInformation();
						break;
					case 2:
						AddUserInformation();
						break;
					case 3:
						DeleteUserInformation();
						break;
					case 4:
						SearchUserInformation();
						break;
					case 5:
						LookThroughAllUserInformation();
						break;
					case 6:
						printf("\n正在返回上一级...\n");
						input2 = 0;
						break;
					default:
						printf("\n输入错误，请重试\n");
					}
				} while (input2);
				break;
			case 3:
				do
				{
					AdBillingManageMenu();
					scanf("%d", &input2);
					switch (input2)
					{
					case 1:
						AllUserBillingInformation();
						break;
					case 2:
						SearchUserBillingInformation();
						break;
					case 3:
						BillingStandard();
						break;
					case 4:
						UserBillingUp();
						break;
					case 5:
						UserBillingWarning();
						break;
					case 6:
						printf("\n正在返回上一级...\n");
						input2 = 0;
						break;
					default:
						printf("\n输入错误，请重试\n");
					}
				} while (input2);
				break;
			case 4:
				ExitMenu();
				input1 = 0;
				break;
			default:
				printf("\n输入错误，请重试\n");
			}
		}
		else if (pass == 2)
		{
			UserMainMenu();
			scanf("%d", &input1);
			switch (input1)
			{
			case 1:
				do
				{
					UserManageMenu();
					scanf("%d", &input2);
					switch (input2)
					{
					case 1:
						ChangeUserInformation();
						break;
					case 2:
						LookThroughUserInformation();
						break;
					case 3:
						printf("\n正在返回上一级...\n");
						input2 = 0;
						break;
					default:
						printf("\n输入错误，请重试\n");
					}
				} while (input2);
				break;
			case 2:
				do
				{
					BillingManageMenu();
					scanf("%d", &input2);
					switch (input2)
					{
					case 1:
						BillingStandard();
						break;
					case 2:
						BillingInformation();
						break;
					case 3:
						BillingUp();
						break;
					case 4:
						printf("\n正在返回上一级...\n");
						input2 = 0;
						break;
					default:
						printf("\n输入错误，请重试\n");
					}
				} while (input2);
				break;
			case 3:
				ExitMenu();
				input1 = 0;
				break;
			default:
				printf("\n输入错误，请重试\n");
			}
		}
	} while (input1);
	return 0;
}