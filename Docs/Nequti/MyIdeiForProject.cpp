/*������������� ��������� Nequti, � ��� , ��� ������ ����� ���������, API ������ � ����������, ������� + ������ � IO*/

/****************************************************************/
#include "Memory.h"
#include "Proc.h"
#include "Window.h"
#include "Graphics.h"
#include "Input.h"
/***************************************************************/

/*��� ������� , ���� ��� �������� �� C, � ��������� ������������ ����� ������������ �� C++*/
int main()
{
	/*�������������*/
	IProc* pProc = GetMemory( sizeof( CProc ) );
	IWindow win = pProc->GetWindowPlace( 800, 600, 32, "Test program for my OS" );
	IGraphics* graph = pProc->GetPlace( );/*������, ���, ��� ������� ����� ��������� ���� ������� � ����������*/
	IInput* input = GetKeyboardState( ALL_KEY ); /*����������*/
	graph->OpenGraphicDevice( graph->SMOOTH, graph->RGB, graph->VersionGraph, graph->Buffer = COLOUR_BUF | Z_BUF );
	
	win->ButtonOff( );/*��������� �������� � ������ ������ �� ����*/
	
	if( pProc == 0 )/*������� ��� ������?*/
	{
		return 1;
	}
	
	pProc->CreateProc( );
	pProc->LifeInterval = 0.94;/*����� , ����� ������� ������� �����������*/
	
	while( pProc->State != KILL_PROC/*0*/ )
	{
		graph->ClearBuffers( );
		
		if( pProc->Error == NONE_MEMORY )
		{
			pProc->RemoveMemory( ); /*���� �� ������� ������, �������� ���, ��� ���� �������� ��������*/
		}
		
		win->Draw( );
		pProc->Life( );/*������*/
		graph->Point( 100, 100, graph->Colour<float>( 1.0, 1.0, 1.0 ), graph->Size<int>( 10 ) );
		graph->Line( graph->Point<int>( 200, 200 )/*������������� �������*/, graph->Point<int>( 300, 300 ), graph->Colour<int>( 255, 255, 255 ), graph->Size<int>( 10 ) );
		if( input->Key == 27 )
		{
			pProc->State = KILL_PROC;
		}
	}
	
	win->Close();/*��������� ����*/
	graph->CloseDevice();/*��������� ��� ����������*/
	pProc->KillProg();/*�� ��������� ����� ������� �� ���������, ���� State == KILL_PROC*/
	
}