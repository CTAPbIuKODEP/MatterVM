// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������,
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include <SDKDDKVer.h>

// ��������� CppUnitTest
#include "CppUnitTest.h"


#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)
std::string GetDirectoryName(std::string path);

void __WriteBytecode(char * file, char * bc, size_t sz);

#define WRITE_BYTECODE(file, bc) __WriteBytecode(file, bc, sizeof(bc))

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
