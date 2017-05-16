#include "windows.h"
#include "kurs.h"



//��������� �������
LONG WINAPI WinProc(HWND,UINT,WPARAM,LPARAM);



	LPCTSTR ProgName="Kurs";       //����� ��� ���������� �������� �����
	LPCTSTR Title="��������� ��������� ����������"; //��������� ����
	HMENU hMenu;		              //�����.����
	LPCTSTR MainMenu="MM";            //��� ����
	HINSTANCE hInstance;
	HWND     hWnd;		              //���������� ����
	HANDLE hDir;
	BOOL first=TRUE;
	static HWND hbCreateDir;
	static HWND hbDeleteDir;
	static HWND hePath;
	static HWND hbFindFile;
	static HWND heFindPath;
	static HWND hlFileList;
	int i=0;
	int j=0;
//����� �����
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR,int nCmdShow)
{
	
	MSG      msg;		                                         //��������� ����� ����������
	WNDCLASSEX WndClass;	                                         //��������� �������� �����

	//���������� ���� ���������
	WndClass.cbSize=sizeof(WNDCLASSEX);
	WndClass.lpszClassName=ProgName;                             //��� ����� ����
	WndClass.hInstance=hInstance;	                             //�����.���.�������
	WndClass.lpfnWndProc=(WNDPROC)WinProc;                       //�������� �� ������ ����
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);                 //������������ �������
	WndClass.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON));//������������ ������
	WndClass.lpszMenuName=MainMenu;				                 //����
	WndClass.hbrBackground=(HBRUSH)4;							 //��� ����
	WndClass.style=CS_HREDRAW|CS_VREDRAW;						 //����� ����
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hIconSm=LoadIcon(WndClass.hInstance,MAKEINTRESOURCE(IDI_SMALL));
    
	//������������ ����
	   if(!RegisterClassEx(&WndClass))
		   return FALSE;

	//��������� ����
	hWnd=CreateWindow(ProgName,Title,
		WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,NULL);
	MoveWindow(hWnd,100,100,450,450,TRUE);
	//³��������� ����
	ShowWindow(hWnd,nCmdShow);

	//�������� �� ������ ���������
	UpdateWindow(hWnd);

	//���� ���������� ����������
	while(GetMessage(&msg,0,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

#include "funcs.h"
#include "wnd_proc.h"