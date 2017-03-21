#define MODULE_IMPL

#include <mtr/DataStructures.h>
#include <mtr/VMachine.h>
#include <mtr/IModule.h>

#include <stdio.h>

using namespace mtr;
using namespace mtr::DataTypes;
using namespace mtr::Modules;
using namespace std;


/*
������� 1 - ������ Hello, world
������� 2 - ������ 1 ������� �� �����
������� 3 - ����������� ����� 102 �� ����
*/


extern "C"
{
	MODULEAPI void API_MTR execute_func(u32 function_id, VMachine * machine)
	{
		char symbol;
		switch (function_id)
		{
		case 1:
			printf("Hello, world!!! I am test module for matter vm.\n");
			break;

		case 2:
			symbol = (char)machine->stack.pop_32();
			printf("%c", symbol);
			break;

		case 3:
			machine->stack.push((u32)102);
			break;
		}
	}

	MODULEAPI u32 API_MTR function_count()
	{
		return 3;
	}
}