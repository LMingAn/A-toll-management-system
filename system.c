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

//---------------------------------------�ļ�--------------------------------------
void File()
{
	FILE* fp = fopen("UserList", "r");
	if (fp == NULL)
	{
		printf("�û��ļ�'UserList'�����ڣ������´���\n");
		fp = fopen("UserList", "w");
	}
}

void AddUserInformation()
{
	FILE* fp = fopen("UserList", "a+");
	struct user;
	printf("\n�������û������20λ��:");
	scanf("%s", user->name);
	printf("\n���������루���ִ�Сд���16λ��:");
	scanf("%s", user->password);
	printf("\n��������ʹ�õ�ˮ������λ���֣�");
	scanf("%f", &user->water);
	printf("\nϵͳ���ڼ������ķ���...\n");
	float take = user->water;
	user->fee = BillingCalculation(&take);
	fwrite(&(user), 1, sizeof(struct User), fp);
	fclose(fp);
	printf("\n�û���ӳɹ���\n����������һ��...\n");
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
	printf("\n������Ҫɾ�����û���:");
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
			printf("\nɾ���ɹ���\n����������һ��\n");
			break;
		}
		else
			count++;
	}
	if (count > num)
		printf("\nδ�ҵ����û�\n����������һ��\n");
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
	printf("\n������Ҫ���ҵ��û���:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û���Ϣ                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       �û�����%-21s���룺%-17s��ˮ����%.1f��\t���ã�%.2fԪ\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\nδ�ҵ����û���\n����������һ��...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n��Ҫ������һ��");
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
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û���Ϣ                                              |\n");
	while (count < num)
	{
		if (strcmp(user[count].name, "") != 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       �û�����%-21s���룺%-17s��ˮ����%.1f��\t���ã�%.2fԪ\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
		}
		else
			count++;
	}
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n��Ҫ������һ��");
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
	printf("\n�������û�������֤���:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û���Ϣ                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       �û�����%-21s���룺%-17s��ˮ����%.1f��\t���ã�%.2fԪ\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\n�û���֤ʧ�ܣ�\n����������һ��...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n��Ҫ������һ��");
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
	printf("\n�������û���:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			while (take)
			{
				printf("\n������Ҫ�޸ĵ�����:");
				scanf("%s", input);
				if (strcmp(user[count].password, input) == 0)
					printf("\n�����������ԭ����һ�£������ԣ�\n");
				else
				{
					strcpy(user[count].password, input);
					take = 0;
				}
			}
			printf("\n�޸ĳɹ�!\n����������һ��...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\nδ�ҵ����û�!\n����������һ��...\n");
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
	printf("\n����������û�����ȷ�����:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			while (take)
			{
				printf("\n������Ҫ�޸ĵ�����:");
				scanf("%s", input);
				if (strcmp(user[count].password, input) == 0)
					printf("\n�����������ԭ����һ�£������ԣ�\n");
				else
				{
					strcpy(user[count].password, input);
					take = 0;
				}
			}
			printf("\n�޸ĳɹ�!\n����������һ��...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\n��֤�û����ʧ��!\n����������һ��...\n");
	fp = fopen("UserList", "w");
	count = 0;
	while (count < num)
	{
		fwrite(&user[count], 1, sizeof(struct User), fp);
		count++;
	}
	fclose(fp);
}



//---------------------------------------�˵�--------------------------------------
int PassMenu()
{
	int pass = 0, a = 0;
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                             ��ʼ����                                             |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                       δ��⵽�û���¼��Ϣ                                       |\n");
	printf("|                                              ���¼                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	do
	{
		char username[20] = { 0 }, password[20] = { 0 };
		printf("\n�������˺�:");
		gets(username);
		printf("\n���������루���ִ�Сд��:");
		gets(password);
		if (strcmp(username, Administer) == 0 && strcmp(password, AdPassword) == 0)//����Ա
		{
			pass = 1;
			return pass;
		}
		else if (CheckName(username) == 1 && CheckPassword(password) == 1)//�û�
		{
			pass = 2;
			return pass;
		}
		else
		{
			printf("\n�û����������������������\n");
			pass = 0;
			return pass;
		}
	} while (a);
}

int AdMainMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            ����Ա����                                            |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                         1.�鿴ϵͳ������Ϣ                                       |\n");
	printf("|                                         2.�û���Ϣ����                                           |\n");
	printf("|                                         3.�û��շѹ���                                           |\n");
	printf("|                                         4.�˳�                                                   |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n�����������Խ�����һ������:");
}

int UserMainMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û�����                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                          1.�û���Ϣ����                                          |\n");
	printf("|                                          2.�û��շѹ���                                          |\n");
	printf("|                                          3.�˳�                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n�����������Խ�����һ������:");
}

int ExitMenu()
{
	printf("\n�����˳�ϵͳ...\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                          ��л����ʹ��                                            |\n");
	printf("|                                          ��ӭ�´ι���                                            |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

int AdUserManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û�����                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                         1.�޸��û���Ϣ                                           |\n");
	printf("|                                         2.�����û���Ϣ                                           |\n");
	printf("|                                         3.ɾ���û���Ϣ                                           |\n");
	printf("|                                         4.�����û���Ϣ                                           |\n");
	printf("|                                         5.�鿴�û���Ϣ                                           |\n");
	printf("|                                         6.����                                                   |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n�����������Խ�����һ������:");
}


int UserManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û�����                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                         1.�޸��û���Ϣ                                           |\n");
	printf("|                                         2.�鿴�û���Ϣ                                           |\n");
	printf("|                                         3.����                                                   |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n�����������Խ�����һ������:");
}

int AdBillingManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �շѹ���                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                     1.�鿴ȫ���û�������Ϣ                                       |\n");
	printf("|                                     2.�鿴��һ�û�������Ϣ                                       |\n");
	printf("|                                     3.�鿴�շѱ�׼                                               |\n");
	printf("|                                     4.�û����ó�ֵ                                               |\n");
	printf("|                                     5.�û�����Ԥ��                                               |\n");
	printf("|                                     6.����                                                       |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n�����������Խ�����һ������:");
}

int BillingManageMenu()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �շѹ���                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                     1.�鿴�շѱ�׼                                               |\n");
	printf("|                                     2.�鿴������Ϣ                                               |\n");
	printf("|                                     3.���ó�ֵ                                                   |\n");
	printf("|                                     4.����                                                       |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n�����������Խ�����һ������:");
}


//---------------------------------------��Ϣ--------------------------------------
void SystemInformation()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            ϵͳ��Ϣ                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                  ϵͳ���ƣ�����ˮ�շѹ���ϵͳ                                    |\n");
	printf("|                             ϵͳ���ߣ�ʮ�� - ��С��������������                              |\n");
	printf("|                                         ϵͳ�汾��V1.1                                           |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n��Ҫ����������");
	system("pause");
}


//---------------------------------------�շ�--------------------------------------
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
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �շ���Ϣ                                              |\n");
	while (count < num)
	{
		if (strcmp(user[count].name, "") != 0)
		{
			printf("|                                                                                                  |\n");
			printf("|              �û�����%-21s��ˮ����%.1f��\t      ���ã�%.2fԪ\t           |\n", user[count].name, user[count].water, user[count].fee);
			count++;
		}
		else
		count++;
	}
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n��Ҫ������һ��");
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
	printf("\n������Ҫ���ҵ��û���:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �շ���Ϣ                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|              �û�����%-21s��ˮ����%.1f��\t      ���ã�%.2fԪ\t           |\n", user[count].name, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\nδ�ҵ����û���\n����������һ��...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n��Ҫ������һ��");
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
	printf("\n�������û���:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("\n�������ֵ���:");
			float fee = 0;
			scanf("%f", &fee);
			user[count].fee += fee;
			printf("\n��ֵ�ɹ�!\n����������һ��...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\nδ�ҵ����û�!\n����������һ��...\n");
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
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �շ���Ϣ                                              |\n");
	while (count < num)
	{
		if (strcmp(user[count].name, "") != 0)
		{
			if (user[count].fee < 0)
			{
				printf("|                                                                                                  |\n");
				printf("|              �û�����%-21s��ˮ����%.1f��\t      ���ã�%.2fԪ\t           |\n", user[count].name, user[count].water, user[count].fee);
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
	printf("\n��Ҫ������һ��");
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
	printf("\n�������û�������֤���:");
	scanf("%s", input);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �û���Ϣ                                              |\n");
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("|                                                                                                  |\n");
			printf("|       �û�����%-21s���룺%-17s��ˮ����%.1f��\t���ã�%.2fԪ\t   |\n", user[count].name, user[count].password, user[count].water, user[count].fee);
			count++;
			take = 1;
		}
		else
			count++;
	}
	if (take == 0)
		printf("\n�û���֤ʧ�ܣ�����������һ��...\n");
	else
	{
		printf("|                                                                                                  |\n");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("\n��Ҫ������һ��");
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
	printf("\n�������û�������֤���:");
	scanf("%s", input);
	while (count <= num)
	{
		if (strcmp(user[count].name, input) == 0)
		{
			printf("\n�������ֵ���:");
			float fee = 0;
			scanf("%f", &fee);
			user[count].fee += fee;
			printf("\n��ֵ�ɹ�!\n����������һ��...\n");
			break;
		}
		count++;
	}
	if (count > num)
		printf("\n�û���֤ʧ��!\n����������һ��...\n");
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
	printf("|                                  ��ӭʹ�ñ���˾����ˮ�շѹ���ϵͳ                                |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("|                                            �շѱ�׼                                              |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                    ��ˮ15������Ϊ0��6Ԫ/��                                       |\n");
	printf("|                                    15-20��Ϊ1��4Ԫ/��                                            |\n");
	printf("|                                    20������Ϊ2��1Ԫ/��                                           |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("|                                                                                                  |\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n��Ҫ������һ��");
	system("pause");
}


//---------------------------------------��¼--------------------------------------

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