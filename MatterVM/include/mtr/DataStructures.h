#pragma once

#ifndef _DATASTRUCTURES_H_
#define _DATASTRUCTURES_H_

#include <memory>
#include <cstdio>
#include <stack>
#include <vector>

namespace mtr
{
	typedef char u8;
	typedef unsigned short int u16;
	typedef unsigned int u32;

	typedef char i8;
	typedef short int i16;
	typedef int i32;

	typedef float f;

	namespace DataTypes
	{
		#define	MAGIC_NUMBER (u16)0x4d2f;

		class SHeader
		{
		public:
			u16 MagicNumber;
			u16 CountImports;
			u32 CountFunctions;
			u32 CountVarBytes;
			u32 CountVarWords;
			u32 CountVarQWords;
			u32 CountVarCustoms;

			size_t allValuesSize() const;
			std::string str() const;

			static std::shared_ptr<SHeader> read(FILE *file);
			static void write(FILE *file, std::shared_ptr<SHeader> hdr);
		};




		class SImportStructure
		{
		public:
			u8 NameLength;
			u16 Index;
			std::shared_ptr<i8> Name;

			std::string str() const;

			static std::shared_ptr<SImportStructure> read(FILE *file);
			static void write(FILE *file, std::shared_ptr<SImportStructure> data);

		};





		class SFunctionStructure
		{
		public:
			u32 BytecodeLength;
			std::shared_ptr<u8> Bytecode;

			std::string str() const;

			static std::shared_ptr<SFunctionStructure> read(FILE *file);
			static void write(FILE *file, std::shared_ptr<SFunctionStructure> data);
		};




		class STypeStructure
		{
		public:
			u8 Length;
			std::shared_ptr<u8> Array;

			std::string str() const;

			static std::shared_ptr<STypeStructure> read(FILE *file);
			static void write(FILE *file, std::shared_ptr<STypeStructure> data);
		};




		class SFileStructure
		{
		public:
			std::shared_ptr<SHeader> Head;
			std::vector<std::shared_ptr<SImportStructure>> ArrImports;
			std::vector<std::shared_ptr<SFunctionStructure>> ArrFunctions;
			std::shared_ptr<u8> ArrValues;
			std::vector<std::shared_ptr<STypeStructure>> ArrCustomValues;

			SFileStructure(std::shared_ptr<SHeader> header);

			u8 byteValue(u32 index) const;
			void byteValue(u32 index, u8 newValue);

			u16 wordValue(u32 index) const;
			void wordValue(u32 index, u16 newValue);

			u32 qwordValue(u32 index) const;
			void qwordValue(u32 index, u32 newValue);

			std::string str() const;

			static std::shared_ptr<SFileStructure> read(FILE *file);
			static std::shared_ptr<SFileStructure> read(const char *file_name);
			static void write(FILE *file, std::shared_ptr<SFileStructure> data);

		};

		class DataHelper
		{
		public:
			static bool read_8(void* data, FILE *file);
			static bool read_16(void *data, FILE* file);
			static bool read_32(void *data, FILE* file);

			static u16 make_16(std::stack<u8> &stack);
			static u32 make_32(std::stack<u8> &stack);
			static f make_f(std::stack<u8> &stack);

			static f utof(u32 u);
			static u8 byteFromFloat(float val, u8 byte_i);
		};

#define MAKE_ARR_DWORD(val) ((u8)((val)>>24)&0xFF), ((u8)((val)>>16)&0xFF), ((u8)((val)>>8)&0xFF), ((u8)(val)&0xFF)
#define MAKE_ARR_F_DWORD(val) DataHelper::byteFromFloat(val, 3), DataHelper::byteFromFloat(val, 2), DataHelper::byteFromFloat(val, 1), DataHelper::byteFromFloat(val, 0)
	}
}

#endif