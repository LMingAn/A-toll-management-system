#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//文件
void File();
void AddUserInformation();
void DeleteUserInformation();
void SearchUserInformation();
void LookThroughAllUserInformation();
void LookThroughUserInformation();
void AdChangeUserInformation();
void ChangeUserInformation();

//菜单
int PassMenu();
int AdMainMenu();
int UserMainMenu();
int ExitMenu();
int AdUserManageMenu();
int UserManageMenu();
int AdBillingManageMenu();
int BillingManageMenu();

//系统
void SystemInformation();

//登录
int CheckName();
int CheckPassword();

//收费
void AllUserBillingInformation();
void SearchUserBillingInformation();
void UserBillingUp();
void UserBillingWarning();
void BillingInformation();
void BillingUp();
float BillingCalculation();
void BillingStandard();