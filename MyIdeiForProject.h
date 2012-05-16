#include "Memory.h"
#include "Proc.h"

/*��� ������� , ���� ��� �������� �� C, � ��������� ������������ ����� ������������ �� C++*/
int main()
{
	CProc* pProc = GetMemory( sizeof( CProc ) );
	IGraphics<int>* graph = pProc->GetPlace();/*������, ���, ��� ������� ����� ��������� ���� ������� � ����������*/
	IInput* input = GetKeyboardState( ALL_KEY ); /*����������*/
	
	if( pProc == 0 )
	{
		return 1;
	}
	
	pProc->CreateProc( );
	pProc->LifeInterval = 0.94;/*����� , ����� ������� ������� �����������*/
	
	while( pProc->State != KILL_PROC/*0*/ )
	{
		pProc->RemoveMemory( ); /*���� �� ������� ������, �������� ���, ��� ���� �������� ��������*/
		pProc->Life( );/*������*/
		graph->Point( 100, 100, graph->Colour<float>( 1.0, 1.0, 1.0 ), graph->Size<int>( 10 ) );
		graph->Line( graph->Point<int>( 200, 200 )/*������������� �������*/, graph->Point<int>( 300, 300 ), graph->Colour<int>( 255, 255, 255 ), graph->Size<int>( 10 ) );
		if( input->Key == 27 )
		{
			pProc->State = KILL_PROC;
		}
	}
	pProc->KillProg();/*�� ��������� ����� ������� �� ���������, ���� State == KILL_PROC*/
}