#include "windows.h"
#include "kurs.h"



//Прототипи функцій
LONG WINAPI WinProc(HWND,UINT,WPARAM,LPARAM);



	LPCTSTR ProgName="Kurs";       //Рядок для реестрації віконного класу
	LPCTSTR Title="Программа керування каталогами"; //Заголовок вікна
	HMENU hMenu;		              //Дескр.Меню
	LPCTSTR MainMenu="MM";            //Імя меню
	HINSTANCE hInstance;
	HWND     hWnd;		              //Дескриптор вікна
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
//Точка входу
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR,int nCmdShow)
{
	
	MSG      msg;		                                         //Структута опису повідомлень
	WNDCLASSEX WndClass;	                                         //Структура атрибутів класу

	//Заповнення полів структури
	WndClass.cbSize=sizeof(WNDCLASSEX);
	WndClass.lpszClassName=ProgName;                             //Імя класу вікна
	WndClass.hInstance=hInstance;	                             //Дескр.екз.додатку
	WndClass.lpfnWndProc=(WNDPROC)WinProc;                       //Покажчик на віконну проц
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);                 //Завантаження курсору
	WndClass.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON));//Завантаження іконки
	WndClass.lpszMenuName=MainMenu;				                 //Меню
	WndClass.hbrBackground=(HBRUSH)4;							 //Фон вікна
	WndClass.style=CS_HREDRAW|CS_VREDRAW;						 //Стиль вікна
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hIconSm=LoadIcon(WndClass.hInstance,MAKEINTRESOURCE(IDI_SMALL));
    
	//Реестрування вікна
	   if(!RegisterClassEx(&WndClass))
		   return FALSE;

	//Створюємо вікно
	hWnd=CreateWindow(ProgName,Title,
		WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,NULL);
	MoveWindow(hWnd,100,100,450,450,TRUE);
	//Відображаємо вікно
	ShowWindow(hWnd,nCmdShow);

	//Посилаємо на віконну процедуру
	UpdateWindow(hWnd);

	//Цикл очікування повідомлень
	while(GetMessage(&msg,0,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

#include "funcs.h"
#include "wnd_proc.h"