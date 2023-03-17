#include"manage.h"

char Administer[] = "MingAn";
char AdPassword[] = "123lan??";
char Use[20] = { 0 };
char Password = { 0 };
struct User
{
	char name[21];
	char password[17];
	float water;
	float fee;
}user[1000] = { 0, 0, 0, 0 };

//---------------------------------------文件--------------------------------------
void File()
{
	FILE* fp = fopen("UserList", "r");
	if (fp == NULL)
	{
		printf("用户文件'UserList'不存在，将重新创建\n");
		fp = fopen("UserList", "w");
	}
}

void AddUserInformation()
{
	FILE* fp = fopen("UserList", "a+");
	struct user;
	printf("\n请输入用户名（最长20位）:");
	scanf("%s", user->name);
	printf("\n请输入密码（区分大小写、最长16位）:");
	scanf("%s", user->password);
	printf("\n请输入已使用的水量（单位：吨）");
	scanf("%f", &user->water);
	printf("\n系统正在计算您的费用...\n");
	float take = user->water;
	user->fee = BillingCalculation(&take);
	fwrite(&(user), 1, sizeof(struct User), fp);
	fclose(fp);
	printf("\n用户添加成功！\n即将返回上一级...\n");
}

void DeleteUserInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0;
	printf("\n请输入要删除的用户名:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			for (; count < num; count++)
			{
				strcpy(user[count].name, user[count + 1].name);
				strcpy(user[count].password, user[count + 1].password);
				user[count].water = user[count + 1].water;
				user[count].fee = user[count + 1].fee;
			}
			printf("\n删除成功！\n即将返回上一级\n");
			break;
		}
		else
			count++;
	}
	if (count > num)
		printf("\n未找到此用户\n即将返回上一级\n");
	fp = fopen("UserList", "w");
	count = 0;
	while (count < num)
	{
		fwrite(&user[count], 1, sizeof(struct User), fp);
		count++;
	}
	fclose(fp);
}

void SearchUserInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0, take = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0;
	printf("\n请输入要查找的用户名:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户信息                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       用户名：%-21s密码：%-17s用水量：%.1f吨\t费用：%.2f元\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\n未找到此用户！\n即将返回上一级...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n若要返回上一级");
		system("pause");
	}
}

void LookThroughAllUserInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	int count = 0;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户信息                                              |\n");
	while (count < num)
	{
		if (strcmp(user[count].name, "") != 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       用户名：%-21s密码：%-17s用水量：%.1f吨\t费用：%.2f元\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
		}
		else
			count++;
	}
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n若要返回上一级");
	system("pause");
}

void LookThroughUserInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0, take = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0;
	printf("\n请输入用户名以验证身份:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户信息                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       用户名：%-21s密码：%-17s用水量：%.1f吨\t费用：%.2f元\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\n用户验证失败！\n即将返回上一级...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n若要返回上一级");
		system("pause");
	}
}

void AdChangeUserInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0, take = 1;
	printf("\n请输入用户名:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			while (take)
			{
				printf("\n请输入要修改的密码:");
				scanf("%s", input);
				if (strcmp(user[count].password, input) == 0)
					printf("\n输入的密码与原密码一致，请重试！\n");
				else
				{
					strcpy(user[count].password, input);
					take = 0;
				}
			}
			printf("\n修改成功!\n即将返回上一级...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\n未找到此用户!\n即将返回上一级...\n");
	fp = fopen("UserList", "w");
	count = 0;
	while (count < num)
	{
		fwrite(&user[count], 1, sizeof(struct User), fp);
		count++;
	}
	fclose(fp);
}

void ChangeUserInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0, take = 1;
	printf("\n请输入你的用户名以确认身份:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			while (take)
			{
				printf("\n请输入要修改的密码:");
				scanf("%s", input);
				if (strcmp(user[count].password, input) == 0)
					printf("\n输入的密码与原密码一致，请重试！\n");
				else
				{
					strcpy(user[count].password, input);
					take = 0;
				}
			}
			printf("\n修改成功!\n即将返回上一级...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\n验证用户身份失败!\n即将返回上一级...\n");
	fp = fopen("UserList", "w");
	count = 0;
	while (count < num)
	{
		fwrite(&user[count], 1, sizeof(struct User), fp);
		count++;
	}
	fclose(fp);
}



//---------------------------------------菜单--------------------------------------
int PassMenu()
{
	int pass = 0, a = 0;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                             初始界面                                             |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                       未检测到用户登录信息                                       |\n");
	printf("|                                              请登录                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	do
	{
		char username[20] = { 0 }, password[20] = { 0 };
		printf("\n请输入账号:");
		gets(username);
		printf("\n请输入密码（区分大小写）:");
		gets(password);
		if (strcmp(username, Administer) == 0 && strcmp(password, AdPassword) == 0)//管理员
		{
			pass = 1;
			return pass;
		}
		else if (CheckName(username) == 1 && CheckPassword(password) == 1)//用户
		{
			pass = 2;
			return pass;
		}
		else
		{
			printf("\n用户名或密码错误，请重新输入\n");
			pass = 0;
			return pass;
		}
	} while (a);
}

int AdMainMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            管理员界面                                            |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                         1.查看系统基本信息                                       |\n");
	printf("|                                         2.用户信息管理                                           |\n");
	printf("|                                         3.用户收费管理                                           |\n");
	printf("|                                         4.退出                                                   |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n请输入数字以进行下一步操作:");
}

int UserMainMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户界面                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                          1.用户信息管理                                          |\n");
	printf("|                                          2.用户收费管理                                          |\n");
	printf("|                                          3.退出                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n请输入数字以进行下一步操作:");
}

int ExitMenu()
{
	printf("\n正在退出系统...\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                          感谢您的使用                                            |\n");
	printf("|                                          欢迎下次光临                                            |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

int AdUserManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户管理                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                         1.修改用户信息                                           |\n");
	printf("|                                         2.增加用户信息                                           |\n");
	printf("|                                         3.删除用户信息                                           |\n");
	printf("|                                         4.查找用户信息                                           |\n");
	printf("|                                         5.查看用户信息                                           |\n");
	printf("|                                         6.返回                                                   |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n请输入数字以进行下一步操作:");
}


int UserManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户管理                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                         1.修改用户信息                                           |\n");
	printf("|                                         2.查看用户信息                                           |\n");
	printf("|                                         3.返回                                                   |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n请输入数字以进行下一步操作:");
}

int AdBillingManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            收费管理                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                     1.查看全体用户费用信息                                       |\n");
	printf("|                                     2.查看单一用户费用信息                                       |\n");
	printf("|                                     3.查看收费标准                                               |\n");
	printf("|                                     4.用户费用充值                                               |\n");
	printf("|                                     5.用户费用预警                                               |\n");
	printf("|                                     6.返回                                                       |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n请输入数字以进行下一步操作:");
}

int BillingManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            收费管理                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                     1.查看收费标准                                               |\n");
	printf("|                                     2.查看费用信息                                               |\n");
	printf("|                                     3.费用充值                                                   |\n");
	printf("|                                     4.返回                                                       |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n请输入数字以进行下一步操作:");
}


//---------------------------------------信息--------------------------------------
void SystemInformation()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            系统信息                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                  系统名称：自来水收费管理系统                                    |\n");
	printf("|                             系统作者：十组 - 兰小贵、王奕力、杨浩楠                              |\n");
	printf("|                                         系统版本：V1.1                                           |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n若要返回主界面");
	system("pause");
}


//---------------------------------------收费--------------------------------------
void AllUserBillingInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	int count = 0;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            收费信息                                              |\n");
	while (count < num)
	{
		if (strcmp(user[count].name, "") != 0)
		{
			printf("|                                                                                                  |\n");
			printf("|              用户名：%-21s用水量：%.1f吨\t      费用：%.2f元\t           |\n", user[count].name, user[count].water, user[count].fee);
			count++;
		}
		else
		count++;
	}
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n若要返回上一级");
	system("pause");
}

void SearchUserBillingInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0, take = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0;
	printf("\n请输入要查找的用户名:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            收费信息                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|              用户名：%-21s用水量：%.1f吨\t      费用：%.2f元\t           |\n", user[count].name, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\n未找到此用户！\n即将返回上一级...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n若要返回上一级");
		system("pause");
	}
}

void UserBillingUp()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0, take = 1;
	printf("\n请输入用户名:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("\n请输入充值金额:");
			float fee = 0;
			scanf("%f", &fee);
			user[count].fee += fee;
			printf("\n充值成功!\n即将返回上一级...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\n未找到此用户!\n即将返回上一级...\n");
	fp = fopen("UserList", "w");
	count = 0;
	while (count < num)
	{
		fwrite(&user[count], 1, sizeof(struct User), fp);
		count++;
	}
	fclose(fp);
}

void UserBillingWarning()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	int count = 0;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            收费信息                                              |\n");
	while (count < num)
	{
		if (strcmp(user[count].name, "") != 0)
		{
			if (user[count].fee < 0)
			{
				printf("|                                                                                                  |\n");
				printf("|              用户名：%-21s用水量：%.1f吨\t      费用：%.2f元\t           |\n", user[count].name, user[count].water, user[count].fee);
				count++;
			}
			else
				count++;
		}
		else
			count++;
	}
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n若要返回上一级");
	system("pause");
}

void BillingInformation()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0, take = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0;
	printf("\n请输入用户名以验证身份:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            用户信息                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       用户名：%-21s密码：%-17s用水量：%.1f吨\t费用：%.2f元\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\n用户验证失败！即将返回上一级...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n若要返回上一级");
		system("pause");
	}
}

void BillingUp()
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	char input[21] = { 0 };
	int count = 0, take = 1;
	printf("\n请输入用户名以验证身份:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("\n请输入充值金额:");
			float fee = 0;
			scanf("%f", &fee);
			user[count].fee += fee;
			printf("\n充值成功!\n即将返回上一级...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\n用户验证失败!\n即将返回上一级...\n");
	fp = fopen("UserList", "w");
	count = 0;
	while (count < num)
	{
		fwrite(&user[count], 1, sizeof(struct User), fp);
		count++;
	}
	fclose(fp);
}

float BillingCalculation(float *water)
{
	float fee = 0;
	if (*water <= 15)
		fee = *water * 0.6;
	else if (*water > 15 && *water <= 20)
		fee = 9 + (*water - 15) * 1.4;
	else
		fee = 9 + 7 + (*water - 20) * 2.1;
	return -fee;
}

void BillingStandard()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  欢迎使用本公司自来水收费管理系统                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            收费标准                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                    用水15吨以内为0．6元/吨                                       |\n");
	printf("|                                    15-20吨为1．4元/吨                                            |\n");
	printf("|                                    20吨以上为2．1元/吨                                           |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n若要返回上一级");
	system("pause");
}


//---------------------------------------登录--------------------------------------

int CheckName(char Username[])
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0, take = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	int count = 0;
	while (count <= num)
	{
		if (strcmp(user[count].name, Username) == 0)
		{
			take = 1;
			return take;
		}
		else
			count++;
	}
	count--;
	if (count > num)
		take = 0;
	return take;
}

int CheckPassword(char Password[])
{
	FILE* fp = fopen("UserList", "r");
	int r = 0, num = 0, take = 0;
	r = fread(&user[num], 1, sizeof(struct User), fp);
	while (r)
	{
		num++;
		r = fread(&user[num], 1, sizeof(struct User), fp);
	}
	fclose(fp);
	int count = 0;
	while (count <= num)
	{
		if (strcmp(user[count].password, Password) == 0)
		{
			take = 1;
			return take;
		}
		else
			count++;
	}
	count--;
	if (count > num)
		take = 0;
	return take;
}