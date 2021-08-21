#include<iostream>
#include<fstream>
#include <STRING>
#include <WTypes.h>
#include <Winbase.h>
using namespace std;
int main()
{
	ofstream outf;
	ifstream inf;
	cout << " 开始设置本地域名（更改host），如果杀毒软件弹出窗口，请选择允许/信任\n";
	const char * lpFileName = "C:\\Windows\\System32\\drivers\\etc\\hosts";
	DWORD   dwAttribute = ::GetFileAttributes(lpFileName);
	DWORD   wrAttribute = dwAttribute;
	if (dwAttribute   &   FILE_ATTRIBUTE_READONLY)
	{
		wrAttribute = dwAttribute & ~FILE_ATTRIBUTE_READONLY;
		SetFileAttributes(lpFileName, wrAttribute);//去掉只读属性
	}
	inf.open(lpFileName, ios::in);
	string line;
	bool haskinpan = false;
	system("color 0A");
	while (getline(inf, line))
	{
		//cout<<line<<endl;
		if (line == "121.5.227.13 bakerygirl.gmgate.net")
		{
			haskinpan = true;
			cout << " 您已经通过公共服务器来跳过激活了！但是请注意公共服务器无法进行长期激活！ \n";
			break;
		}else if (line == "127.0.0.1 bakerygirl.gmgate.net")
		{
			haskinpan = true;
			cout << " 您已经通过本地服务器来跳过激活了！无需使用公共服务器激活啦！ \n";
			break;
		}
	}
	inf.close();
	if (haskinpan == false) {
		outf.open("C:\\Windows\\System32\\drivers\\etc\\hosts", ios::app);//追加
		outf << "\n121.5.227.13 bakerygirl.gmgate.net";
		outf << "\n";
		outf.close();
		cout << "设置成功! 您可以通过公共服务器来跳过激活了！但是请注意公共服务器无法进行长期激活！\n";
	}
	SetFileAttributes(lpFileName, dwAttribute);//恢复只读属性
	cout << " 您现在可以直接打开游戏进行激活啦！\n";
	system("pause");
	return 0;
}